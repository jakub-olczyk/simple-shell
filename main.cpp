#include <iostream>
#include <string>
#include <cstdint> 
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "io.hpp"

const char* ss_version = "v0.1";

int execute(const std::string& cmd, bool& e)
{
	std::cout << "Execute:" + cmd << std::endl;
	if (cmd == "clear"){
	   	std::cout << "\x1b\x5b\x48\x1b\x5b\x32\x4a";
		return 0;
	}	
	if (cmd == "exit"){
		std::cout <<"Bye!"<<std::endl;
		e=false;
	return 0;
	}
	int died, status;
	
	char set_cmd[1024];
	char set_args[50][1024];
	uint8_t argsc = set_command(cmd, set_args); //FIXME
	pid_t pid; 
	std::cout << "Starting..." << std::endl;
	std::cout << "\t>>"<<set_args[0] <<" "<< set_args[1] << std::endl;
	switch(pid=fork()){
		case -1 :
			std::cout<<"Can't start this program\n";
			std::exit(EXIT_FAILURE);
		case 0 :
		  	execv(strcat("/usr/bin/",set_args[0]), reinterpret_cast<char*const*>(&set_args[1])); //FIXME
			std::exit(EXIT_SUCCESS);
		default:
			died = wait(&status);
			return 0; 
	}
}

void with_flags(int argc,char* argv[])
{
for (int i=1;i<argc;++i) {
	if (argv[i][0] != '-') break;

	switch(argv[i][1]){
		case 'h':
			std::cout <<"Simple Shell "<< ss_version <<"\ncopyleft Jakub Olczyk\nwritten as an OS learning aid" << std::endl;
			break;
		case 'V':
			std::cout <<"Simple Shell "<< ss_version << std::endl;
			break;
	}
}
}

int main(int argc, char* argv[])
{
if (argc != 1) {
	with_flags(argc, argv);	
	return 0;
}

std::string command;	

for(bool end=true;end;){
	print_prompt();
	std::getline(std::cin,command); 
	execute(command,end);
}

return 0;
}
