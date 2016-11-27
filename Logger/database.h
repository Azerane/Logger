#ifndef DATABASE_H_
#define DATABASE_H_

#include "user.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class User;

class DataBase {
private:
  std::vector<User*> _data;

public:
  DataBase();
  ~DataBase();
  void AddUser();

private:
  void ExtractUser();
  void split(const std::string &s, char delim, std::vector<std::string> &elems);
};

#endif
