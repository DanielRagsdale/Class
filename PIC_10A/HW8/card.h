#pragma once
#include <string>
using namespace std;

class card {
  int num; 
  char suit; //there are 4 suits: C D H S
public:
  void setNum(int n);
  void setSuit(char s);
  int getNum();
  char getSuit();
  string read();
  card();
  card(int n, char s);
};
