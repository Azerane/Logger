#include "database.h"

DataBase::DataBase() {
  ExtractUser();
}

DataBase::~DataBase() {

}

void DataBase::AddUser() {
  User* _user;
  std::vector<std::string> _double;
  int i;

  i = 0;
  while (i < _data.size()) {
    _double.push_back(_data[i]->getEmail());
    _double.push_back(_data[i]->getNickname());
    i++;
  }
  _user =  new User();
  if (_user->CreateNewUser(_double) == 0)
    _data.push_back(_user);
}

void DataBase::split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

void DataBase::ExtractUser() {
    std::ifstream dataFile(DATA_USER);
    std::string line;

    if (dataFile.is_open()) {
      while (getline(dataFile, line)) {
        std::vector<std::string> elems;
        split(line, ';', elems);
        _data.push_back(new User(elems[0], elems[1], elems[2], elems[3]));
      }
      dataFile.close();
    }
}
