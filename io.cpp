/* name : io.cpp 
 * 
 * author: Jakub Olczyk (jakub.olczyk@openmailbox.com)
 * license : Beerware license similar to the one below. But the beer goes to me ;) 
 *
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <phk@FreeBSD.ORG> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */
#include <iostream>

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
	//for (int i=0;i<=argc;++i){
		//std::cout << "Wypisuje: ";
		//std::cout << out_args[i] << std::endl;
	//}
	return argc;	
}

void clear_command(char args[][1024])
{



}

