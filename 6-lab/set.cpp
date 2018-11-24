#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include "set.h"

using namespace std;

Set::Set(set<int> newSet) 
{
    numbers = newSet;
}

Set::Set(char *setAsString) 
{
    // make a set from a string, where number values are separated by commas
  
    char *pointer = strtok(setAsString, ",");

    while (pointer != nullptr) 
    {
        int number = atoi(pointer);

        numbers.insert(number);

        pointer = strtok(nullptr, ",");
    }

}

int Set::get_set_size() 
{
    return numbers.size();
}

set<int>::iterator Set::get_begin_set_iterator() 
{
    return numbers.begin();
}

set<int>::iterator Set::get_end_set_iterator() 
{
    return numbers.end();
}

set<int> Set::get_set() 
{
    return numbers;
}

void Set::insert_number(int number) 
{
    numbers.insert(number);
}

Set& Set::operator+(Set &additionSet) 
{
    Set *resultingSet = new Set(this->get_set()); // init resulting set with this set as default
  
    set<int>::iterator begin_iterator = additionSet.get_begin_set_iterator();
    set<int>::iterator end_iterator = additionSet.get_end_set_iterator();

    while (begin_iterator != end_iterator) 
    {
        resultingSet->insert_number(*begin_iterator);
        begin_iterator++;
    }

    return *resultingSet;
}

Set& Set::operator+=(Set &additionSet) 
{
    set<int>::iterator begin_iterator = additionSet.get_begin_set_iterator();
    set<int>::iterator end_iterator = additionSet.get_end_set_iterator();

    while (begin_iterator != end_iterator) 
    {
        numbers.insert(*begin_iterator);
        begin_iterator++;
    }
  
    return *this;
}

Set& Set::operator*(Set &intersectingSet) 
{
    int min_waiting_intersection_size = min(this->get_set_size(), 
                                            intersectingSet.get_set_size());

    vector<int> resulting_vector(min_waiting_intersection_size);
  
    vector<int>::iterator it;
  
    it = set_intersection(this->get_begin_set_iterator(),
                          this->get_end_set_iterator(),
                          intersectingSet.get_begin_set_iterator(),
                          intersectingSet.get_end_set_iterator(),
                          resulting_vector.begin());
  
    resulting_vector.resize(it - resulting_vector.begin());

    set<int> resulting_set(resulting_vector.begin(), resulting_vector.end());

    Set *intersectionResult = new Set(resulting_set);
  
    return *intersectionResult;    
}

Set& Set::operator*=(Set &intersectingSet) 
{
    int min_waiting_intersection_size = min(this->get_set_size(), 
                                            intersectingSet.get_set_size());

    vector<int> resulting_vector(min_waiting_intersection_size);
  
    vector<int>::iterator it;
  
    it = set_intersection(this->get_begin_set_iterator(),
                          this->get_end_set_iterator(),
                          intersectingSet.get_begin_set_iterator(),
                          intersectingSet.get_end_set_iterator(),
                          resulting_vector.begin());
  
    resulting_vector.resize(it - resulting_vector.begin());

    set<int> resulting_set(resulting_vector.begin(), resulting_vector.end());

    numbers = resulting_set;
  
    return *this;   
}

Set& Set::operator-(Set &negativeSet) 
{
    vector<int> resulting_vector(get_set_size());
  
    vector<int>::iterator it;
  
    it = set_difference(this->get_begin_set_iterator(),
                        this->get_end_set_iterator(),
                        negativeSet.get_begin_set_iterator(),
                        negativeSet.get_end_set_iterator(),
                        resulting_vector.begin());
  
    resulting_vector.resize(it - resulting_vector.begin());

    set<int> resulting_set(resulting_vector.begin(), resulting_vector.end());

    Set *differenceResult = new Set(resulting_set); 
  
    return *differenceResult;    
}

Set& Set::operator-=(Set &negativeSet) 
{
    vector<int> resulting_vector(get_set_size());
  
    vector<int>::iterator it;
  
    it = set_difference(this->get_begin_set_iterator(),
                        this->get_end_set_iterator(),
                        negativeSet.get_begin_set_iterator(),
                        negativeSet.get_end_set_iterator(),
                        resulting_vector.begin());
  
    resulting_vector.resize(it - resulting_vector.begin());

    set<int> resulting_set(resulting_vector.begin(), resulting_vector.end());

    numbers = resulting_set; // redefine numbers set into difference set 
  
    return *this;    
}

Set& Set::operator<<(int newSetValue) 
{
    set<int>::iterator it;

    for (it = get_begin_set_iterator(); it != get_end_set_iterator(); it++) 
    {
        if (*it == newSetValue) 
        {
           cout << newSetValue << " number is already included is set!" << endl;
      
           return *this;
        }
    }

    numbers.insert(newSetValue);

    return *this;
} 

Set& Set::operator>>(int removableValue) 
{
    set<int>::iterator it;

    for (it = get_begin_set_iterator(); it != get_end_set_iterator(); it++) 
    {
        if (*it == removableValue) 
        {
            numbers.erase(removableValue);

            return *this;
        }
    }

    cout << "Set doesn't include " << removableValue << " number!" << endl;

    return *this;
}

Set& Set::operator=(Set &newSet) 
{
    numbers = newSet.get_set();

    return *this;
}

void Set::print_set() 
{
    set<int>::iterator it; // create an iterator

    for (it = numbers.begin(); it != numbers.end(); it++) // move iterator over the set and cout the value
        cout << *it << " ";

    cout << endl;
}

void Set::not_integer_report()
{   
    cout << "Type error:"                                << endl;
    cout << "   Set includes non-integer value!"         << endl;
    cout << "   Set must includes only integer numbers!" << endl;
}

Set::~Set() 
{
    numbers.clear();
  
    set<int>().swap(numbers);
}

void FloatTypeError::error()
{
    cout << "Set must not includes float values!" << endl;
}

void StringTypeError::error()
{
    cout << "Set must not includes string values!" << endl;
}

