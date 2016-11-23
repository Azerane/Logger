#ifndef USER_H_
#define USER_H_

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "sha256.h"

class User {
private:
	std::string _email;
	std::string _nickname;
	std::string _salt;
	std::string _hash;

public:
	User(int);
	~User();

private:
	void CreateNewUser();
	void ExportUser(void);
	void ImportUser(void);
	std::string GenerateSalt(unsigned int length);
	std::string GenerateHash(std::string &, std::string &);
};

#endif