#include <iostream>
#include <algorithm>
#include <random>
#include <cassert>
#include "deck.h"
#include "shuffle.h"
using namespace std;

deck::deck()
{
	deal_count = 0;

	for(int i = 1; i <= 13; i++)
	{
		stack[i - 1] = card(i, 'C');
	}
	for(int i = 1; i <= 13; i++)
	{
		stack[i + 12] = card(i, 'D');
	}
	for(int i = 1; i <= 13; i++)
	{
		stack[i + 25] = card(i, 'H');
	}
	for(int i = 1; i <= 13; i++)
	{
		stack[i + 38] = card(i, 'S');
	}
}

card deck::deal()
{
	assert(deal_count < 52);
	return stack[deal_count++];
}

int deck::stack_size()
{
	return 52 - deal_count;
}

void deck::gather_and_shuffle()
{
	deal_count = 0;
	shuffle();
}

//Do not change this function
void deck::shuffle() {
  assert(deal_count == 0);
  std::default_random_engine eng(SEED_MACRO);
  std::shuffle(stack, stack + 52, eng);
}

void deck::print_deck() {
  for (int i = 0; i < 52; i++)
    cout << stack[i].read() << endl;
}

