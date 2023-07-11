#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "cmds.h"

int main() {
	// Make variables
	const int maxargs = 512;
	int maxbuffer = 4096;
	int splittercount = 0;
	int child_status;

	char* cmd = new char[maxbuffer];
	char* args[maxargs + 1];

	bool running = true;

	pid_t child_pid;

	// Customization stuff
	char hostname[256];
    gethostname(hostname, sizeof(hostname));
	char* username = getenv("USER");

	while(running) {
		// Reset
		splittercount = 0;
		for(int i; i <= maxargs; i++) {
			args[i] = "";
		}

		// Get input	
		std::cout << "[" << username << "@" << hostname << "]: ";
		std::cin.getline (cmd, maxbuffer);

		// Finish command
		char* splitter = std::strtok(const_cast<char*>(cmd), " ");
		while (splitter != nullptr && splittercount < maxargs) {
			args[splittercount] = splitter;
			splittercount++;
			splitter = std::strtok(nullptr, " ");
		}
		args[splittercount] = NULL;

		// Check for command
		checkforcmd(args);

		// Make process
		child_pid = fork();
		// Child Process
		if(child_pid == 0) {
			// Getting output
			//TODO

			// Execute
			execvp(args[0], args);

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
