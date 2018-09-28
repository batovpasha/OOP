#include <set>

using namespace std;

class Set {
  
  set<int> numbers;
  
  public:
    Set(char *setAsString);
    Set(set<int> set);
    set<int>::iterator get_begin_set_iterator();
    set<int>::iterator get_end_set_iterator();
    Set& operator+(Set &additionSet);
    Set& operator+=(Set &additionSet);
    void print_set();

};