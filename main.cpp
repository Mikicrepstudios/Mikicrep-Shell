#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	// Make variables
	char* cmd = new char[10000];
	bool running = true;
	pid_t child_pid;
	int child_status;

	while(running) {
		// Get input	
		std::cout << "[placeholder]: ";
		std::cin >> cmd;

		// Finish command
		char* arguments[] = {cmd, NULL};

		// Make process
		child_pid = fork();
		// Do execution stuff
		if(child_pid == 0) {
			// Execute
			execvp(cmd, arguments);

			// Exit if error
			exit(1);
		}
		// Repeat
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
