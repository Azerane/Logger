#include "user.h"

User::User(int create)
{
	if (create == 1)
	CreateNewUser();
}

User::~User()
{
}

void User::CreateNewUser()
{
	std::string _password;
	std::cout << "Email: ";
	std::cin >> _email;
	std::cout << "Nickname: ";
	std::cin >> _nickname;
	std::cout << "Password: ";
	std::cin >> _password;
	_salt = GenerateSalt(32);
	_hash = GenerateHash(_password, _salt);
	std::cout << " Genated HASH: " << _hash << std::endl;
	this->ExportUser();
	std::cin >> _password;
}

void User::ExportUser(void)
{
	std::ofstream outputfile(DATA_USER);
	outputfile << _email << ";" << _nickname << ";" << _salt << ";" << _hash << std::endl;
}

void User::ImportUser(void)
{
}

std::string User::GenerateSalt(unsigned int length)
{
	std::string _salt = "";
	std::string _base = "abcdefghijklmnopqrstuvwmxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 !\"#$%&\'()*+,-./<=>?@[\\]^_`{|}~";
	int i;
	srand(time(NULL));
	i = 0;
	while (i < length) {
		_salt += _base[rand() % _base.length()];
		i++;
	}
	return _salt;
}

std::string User::GenerateHash(std::string & password, std::string & salt)
{
	return sha256(salt + password);
}
