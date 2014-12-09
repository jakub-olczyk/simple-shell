#include <iostream>
#include <string>

const char* ss_version = "v0.1";

void print_prompt()
{
	std::cout <<"$";
}

void execute(const std::string& cmd, bool& e)
{
	if (cmd == "clear") std::cout << "\x1b\x5b\x48\x1b\x5b\x32\x4a";
	if (cmd == "exit"){ std::cout << "Bye!"<<std::endl; e=false;}
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
	print_prompt(pwd);
	std::getline(std::cin,command); 
	execute(command,end);
}

return 0;
}
