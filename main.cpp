#include <iostream>
#include <unistd.h>

int main() {
	char* cmd = new char[10000];
	std::cout << "[placeholder]: ";
	std::cin >> cmd;
	char* arguments[] = {cmd, NULL};
	execvp(cmd, arguments);

	return 0;	
}
