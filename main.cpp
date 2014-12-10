#include <iostream>
#include <string>
#include <cstdint> 
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

const char* ss_version = "v0.1";

void print_prompt()
{
	std::cout <<"$ ";
}

uint8_t set_command(std::string cmd, char out_args[][1024])	
{
	uint8_t argc = 0;
	uint16_t wordc = 0;
	for(auto i=cmd.begin();i!=cmd.end();++i){
		switch (*i){ 
			case ' ':
				argc++;
				wordc = 0;
				break;
			default:
				out_args[argc][wordc] = *i; 
				out_args[argc][((wordc+1) < 1024) ? (wordc+1) : wordc] = '\0'; 
				wordc++;
		}
	}
	for (int i=0;i<argc;++i){
		std::cout << out_args[i] << std::endl;
	}
	return argc;	
}

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
	switch(pid=fork()){
		case -1 :
			std::cout<<"Can't start this program\n";
			std::exit(EXIT_FAILURE);
		case 0 :
		  	execv(set_args[0], &set_args[1]); //FIXME
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
if (argc != 1) 
	with_flags(argc, argv);	

std::string command;	

for(bool end=true;end;){
	print_prompt();
	std::getline(std::cin,command); 
	execute(command,end);
}

return 0;
}
