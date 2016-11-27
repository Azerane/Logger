#ifndef USER_H_
#define USER_H_

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include "sha256.h"
#include "database.h"
#include <vector>

#define DATA_USER "R-type UserData.data"

class DataBase;

class User {
private:
	std::string _email;
	std::string _nickname;
	std::string _salt;
	std::string _hash;

public:
	User();
	User(std::string &, std::string &, std::string &, std::string &);
	~User();
	int CreateNewUser(std::vector<std::string> &);
	std::string getEmail(void) const;
	std::string getNickname(void) const;

private:
	void ExportUser(void);
	std::string GenerateSalt(unsigned int length);
	std::string GenerateHash(std::string &, std::string &);
};

#endif
