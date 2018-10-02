#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include "set.h"

using namespace std;

void show_operations(char **setsAsStrings) {
  Set A(setsAsStrings[1]), 
      B(setsAsStrings[2]),
      C(setsAsStrings[3]), 
      D(setsAsStrings[4]);
  
  // show sets
  cout << "A set: ";
  A.print_set();

  cout << "B set: ";
  B.print_set();

  cout << "C set: ";
  C.print_set();

  cout << "D set: ";
  D.print_set();

  // set union 
  cout << "Union (A + B) '+': ";
  Set set_union = A + B;
  set_union.print_set();

  cout << "Short union operator (C + A + B) '+=': ";
  C += A;
  C += B;
  C.print_set();

  // set intersection
  cout << "Intersection (A * B) '*': ";
  C = A * B;
  C.print_set();

  cout << "Short intersection operator (A *= B) '*=': ";
  A *= B;
  A.print_set();

  // set difference
  cout << "Difference (B - D) '-': ";
  Set set_difference = B - D;
  set_difference.print_set();

  cout << "Difference (D - B) '-': ";
  set_difference = D - B;
  set_difference.print_set();

  cout << "Short set difference operator (B -= D) '-=': ";
  B -= D;
  B.print_set();

  // adding to set
  cout << "Enter number what you want to add to D set: ";
  
  int numberToAdd;
  cin >> numberToAdd;
  
  D << numberToAdd;
  
  cout << "New D set: ";
  D.print_set();

  // deleting from set
  cout << "Enter number what you want to remove from D set: ";

  int numberToDelete;
  cin >> numberToDelete;

  D >> numberToDelete;
  
  cout << "New D set: ";
  D.print_set();

  // appropriation
  cout << "Appropriation (С = D) '=': ";
  C = D;
  C.print_set();
}

int main(int argc, char **argv) {
  show_operations(argv);
  return 0;
}