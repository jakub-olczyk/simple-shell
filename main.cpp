#include <iostream>
#include <string>


#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

const char* ss_version = "v0.1";

void print_prompt()
{
	std::cout <<"$";
}

void set_command(std::string& s_cmd, 
		 		 std::string& path, 
				 char* cmd, 
				 char* args[50])
{
	std::string buff;
	std::string	cmd_out = path;
	cmd_out += s_cmd.substr(s_cmd.find_first_of(' '));
	s_cmd.erase(0,s_cmd.find_first_of(' '));
	std::cout << "\t>>debug: " << s_cmd << std::endl;
	s_cmd.erase(0);
	std::cout << "\t>>debug: " << std::endl;
	for(int i=0;i<50;++i){
		buff = s_cmd.substr(s_cmd.find_first_of(' '));
		s_cmd.erase(0,s_cmd.find_first_of(' '));
		std::strcpy(args[i],buff.c_str());
	}
	std::strcpy(cmd,cmd_out.c_str());
}

int execute(const std::string& cmd, bool& e)
{
	std::cout << "Execute: " + cmd << std::endl;
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
	
	std::string path= "/usr/bin/";
	char c_cmd[1024];
	char c_args[50][1024];
	set_command(cmd,path,c_cmd,c_args);
	pid_t pid; 
	switch(pid=fork()){
		case -1 :
			std::cout<<"Can't start this program\n";
			std::exit(EXIT_FAILURE);
		case 0 :
		  	execl(c_cmd,c_args[0],c_args[1],c_args[2],c_args[3],c_args[3],c_args[5],NULL);
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
