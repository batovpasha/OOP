#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include "set.h"

using namespace std;

int main(int argc, char **argv) {
  Set first_set(argv[1]);
  Set second_set(argv[2]);
  Set third_set(argv[3]);

  first_set += second_set;

  first_set.print_set();

  first_set += third_set;

  first_set.print_set();

  return 0;
}
