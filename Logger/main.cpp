// Password Hash.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <vector>
#include "sha256.h"
#include "user.h"

int main()
{
	std::vector<User*> _database;
	std::string _choice;
	std::cout << "Welcome on Azerane Logger" << std::endl;
	std::cout << "\t[C] -> Create new accout" << std::endl;
	std::cout << "\t[L] -> Login to registered accout" << std::endl;
	do {
		_choice = "";
		std::cin >> _choice;
	} while (_choice[0] != 'C' && _choice[0] != 'L' && _choice[0] != 'c' && _choice[0] != 'l');
	if (_choice[0] == 'C' || _choice[0] == 'c')
		_database.push_back(new User(1));
    return 0;
}

