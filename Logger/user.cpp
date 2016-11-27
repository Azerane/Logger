#include "user.h"

User::User() {

}

User::User(std::string & email, std::string & nick, std::string & salt, std::string & hash)
: _email(email), _nickname(nick), _salt(salt), _hash(hash) {
	/*std::cout << "Email: " << _email << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Salt: " << _salt << std::endl;
	std::cout << "Hash: " << _hash << "\n" << std::endl;*/
}

User::~User()
{
}

int User::CreateNewUser(std::vector<std::string> & _double)
{
	int i;
	std::string _password;
	std::cout << "Email: ";
	std::cin >> _email;
	i = 0;
	while (i < _double.size()) {
		if (_double[i] == _email) {
			std::cout << "Can't create User, Email already taken." << std::endl;
			return 1;
		}
		i++;
	}
	std::cout << "Nickname: ";
	std::cin >> _nickname;
	i = 0;
	while (i < _double.size()) {
		if (_double[i] == _nickname) {
			std::cout << "Can't create User, Nickname already taken." << std::endl;
			return 1;
		}
		i++;
	}
	std::cout << "Password: ";
	std::cin >> _password;

	_salt = GenerateSalt(32);
	_hash = GenerateHash(_password, _salt);
	std::cout << "Genated HASH: " << _hash << std::endl;
	this->ExportUser();
	return 0;
}

void User::ExportUser(void)
{
	std::ofstream outputfile(DATA_USER, std::ios_base::app);
	outputfile << _email << ";" << _nickname << ";" << _salt << ";" << _hash << std::endl;
	outputfile.close();
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

std::string User::getEmail() const {
	return _email;
}

std::string User::getNickname() const {
	return _nickname;
}
