#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	// Make variables
	char* cmd = new char[4096];
	bool running = true;
	pid_t child_pid;
	int child_status;

	// Customization stuff
	char hostname[256];
    gethostname(hostname, sizeof(hostname));
	char* username = getenv("USER");

	while(running) {
		// Get input	
		std::cout << "[" << username << "@" << hostname << "]: ";
		std::cin >> cmd;

		// Finish command
		char* arguments[] = {cmd, NULL};

		// Make process
		child_pid = fork();
		// Child Process
		if(child_pid == 0) {
			// Getting output
			//TODO

			// Execute
			execvp(cmd, arguments);

			// Exit if error
			exit(1);
		}
		// Parent Process
		else {
			// Wait for program to finish
			wait(&child_status);
			
			// If command does not execute correctly, return error
			if (WIFEXITED(child_status) && WEXITSTATUS(child_status) != 0) {
                std::cout << "Command failed to execute\n";
            }
		}
	}
	
	return 0;	
}
