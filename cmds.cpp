#include <iostream>
#include <cstring>

void exitcmd() {
	std::exit(0);
}

// Handle custom commands
void checkforcmd(char* args[]) {
	if(std::strcmp(args[0], "exit") == 0) {
		exitcmd();
	}
}
