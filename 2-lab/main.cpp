#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include "set.h"

using namespace std;

void show_operations(char **setsAsStrings) {
  Set A(setsAsStrings[1]);
  Set B(setsAsStrings[2]);
  Set C(setsAsStrings[3]);

  cout << "A set: ";
  A.print_set();

  cout << "B set: ";
  B.print_set();

  cout << "C set: ";
  C.print_set();

  // set union 
  cout << "Union (A + B) '+': ";
  Set set_union = A + B;
  set_union.print_set();
  
  cout << "Short union operator (A + B + C) '+=': ";
  C += A;
  C += B;
  C.print_set();

  // set intersection
  cout << "Intersection (A * B) '*': ";
  C = A * B;
  C.print_set();
}

int main(int argc, char **argv) {
  show_operations(argv);
  return 0;
}