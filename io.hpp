/* name : io.hpp
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
#ifndef SIMPLE_SHELL_IO_HPP__
#define SIMPLE_SHELL_IO_HPP__

#include <iostream>
#include <string>

void print_prompt();

uint8_t set_command(std::string, char [][1024]);

void clear_command(char [][1024]);

#endif
