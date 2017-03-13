#pragma once
#include "card.h"

class deck {
private:
  card stack[52];
  int deal_count;
public:
  deck();
  void print_deck();
  void shuffle();
  card deal();
  int stack_size();
  void gather_and_shuffle();
};
