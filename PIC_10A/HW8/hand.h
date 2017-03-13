#pragma once
#include "card.h"

class hand {
public:
  card c1, c2;
  bool operator<(hand rhs);
  bool operator>(hand rhs);
  bool operator<=(hand rhs);
  bool operator>=(hand rhs);
  bool operator==(hand rhs);
};
