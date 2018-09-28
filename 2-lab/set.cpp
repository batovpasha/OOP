#include <iostream>
#include <cstring>
#include "set.h"

using namespace std;

Set::Set(char *setAsString) {
  // make a set from a string, where number values are separated by commas
  
  char *pointer = strtok(setAsString, ",");

  while (pointer != nullptr) {
    int number = atoi(pointer);

    numbers.insert(number);

    pointer = strtok(nullptr, ",");
  }
}

set<int>::iterator Set::get_begin_set_iterator() {
  return numbers.begin();
}

set<int>::iterator Set::get_end_set_iterator() {
  return numbers.end();
}

Set& Set::operator+(Set &additionSet) {
  set<int>::iterator begin_iterator = additionSet.get_begin_set_iterator();
  set<int>::iterator end_iterator = additionSet.get_end_set_iterator();

  while (begin_iterator != end_iterator) {
    numbers.insert(*begin_iterator);
    begin_iterator++;
  }

  return *this;
}

Set& Set::operator+=(Set &additionSet) {
  set<int>::iterator begin_iterator = additionSet.get_begin_set_iterator();
  set<int>::iterator end_iterator = additionSet.get_end_set_iterator();

  while (begin_iterator != end_iterator) {
    numbers.insert(*begin_iterator);
    begin_iterator++;
  }
  
  return *this;
}

void Set::print_set() {
  set<int>::iterator it; // create an iterator

  for (it = numbers.begin(); it != numbers.end(); it++) // move iterator over the set and cout the value
    cout << *it << " ";

  cout << endl;
}