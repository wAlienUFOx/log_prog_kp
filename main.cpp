#include <iostream>
#include <fstream>
#include <string>
#include <map>

bool isIdx(std::string str){   //0 @I500001@
  if (str[0] == '0' && str[2] == '@' && str[3] == 'I' )
    return true;
  return false;
}

std::string getIdx(std::string str){
  std::string res;
  res = str.substr(3, 7);
  return res;
}

bool isName(std::string str){
  if (str[2] == 'G' && str[3] == 'I' && str[4] == 'V' && str[5] == 'N')
    return true;
  return false;
}

std::string getName(std::string str){
  std::string res;
  res = str.substr(7, str.size() - 7);
  res.push_back(' ');
  return res;
}

bool isSurn(std::string str){
  if (str[2] == 'S' && str[3] == 'U' && str[4] == 'R' && str[5] == 'N')
    return true;
  return false;
}

std::string getSurn(std::string str){
  std::string res;
  res = str.substr(7, str.size() - 7);
  return res;
}

bool isSex(std::string str){
  if (str[2] == 'S' && str[3] == 'E' && str[4] == 'X')
    return true;
  return false;
}

char getSex(std::string str){
  char res;
  res = str[6];
  return res;
}

bool isHusb(std::string str){
  if (str[2] == 'H' && str[3] == 'U' && str[4] == 'S' && str[5] == 'B')
    return true;
  return false;
}

std::string getHusb(std::string str){
  std::string res;
  res = str.substr(8, 7);
  return res;
}

bool isWife(std::string str){
  if (str[2] == 'W' && str[3] == 'I' && str[4] == 'F' && str[5] == 'E')
    return true;
  return false;
}

std::string getWife(std::string str){
  std::string res;
  res = str.substr(8, 7);
  return res;
}

bool isChil(std::string str){
  if (str[2] == 'C' && str[3] == 'H' && str[4] == 'I' && str[5] == 'L')
    return true;
  return false;
}

std::string getChil(std::string str){
  std::string res;
  res = str.substr(8, 7);
  return res;
}

int main(){
  std::ifstream in("fam.txt");
  std::ofstream out("predicates.txt");
  std::string tmp, name, surn, idx, husb, wife, child, fullname;
  std::map<std::string, std::string> person;
  char sex;
  while(std::getline(in, tmp)) {
    if (isIdx(tmp))
      idx = getIdx(tmp);
    if (isName(tmp))
      name = getName(tmp);
    if (isSurn(tmp)){
      surn = getSurn(tmp);
      fullname = name + surn;
      person.insert(std::pair<std::string, std::string>(idx, fullname));
    }
    if (isSex(tmp)){
      sex = getSex(tmp);
      out << "sex(" << fullname << ", "  << sex << ")\n";
    }
    if (isHusb(tmp))
      husb = getHusb(tmp);
    if (isWife(tmp))
      wife = getWife(tmp);
    if (isChil(tmp)){
      child = getChil(tmp);
      out << "parent(" << person.find(husb)->second << ", " <<person.find(child)->second << ")\n";
      out << "parent(" << person.find(wife)->second << ", " <<person.find(child)->second << ")\n";
    }
  }
  return 0;
}
