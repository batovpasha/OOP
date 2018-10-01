#include <set>

using namespace std;

class Set {
  
  set<int> numbers;
  
  public:
    Set(char *setAsString);
    Set(set<int> set);
    int get_set_size();
    set<int>::iterator get_begin_set_iterator();
    set<int>::iterator get_end_set_iterator();
    set<int> get_set();
    void insert_number(int number);
    Set& operator+(Set &additionSet);
    Set& operator+=(Set &additionSet);
    Set& operator*(Set intersectingSet);
    Set& operator*=(Set &intersectingSet);
    Set& operator-(Set &negativeSet);
    Set& operator-=(Set &negativeSet);
    Set& operator<<(int newSetValue);
    Set& operator>>(int removableValue);
    Set& operator=(Set &newSet);
    void print_set();
    ~Set();

};