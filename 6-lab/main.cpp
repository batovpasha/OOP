#include <iostream>
#include <cstring>
#include "set.h"

#define SET_NUMBER 4

using namespace std;

bool isCorrectType(char **setsAsStrings)
{
    for (int i = 0; i < SET_NUMBER; i++)
    {   
        char *temp = new char[sizeof(setsAsStrings[i]) / sizeof(char)];

        strcpy(temp, setsAsStrings[i]);
        
        char *pointer = strtok(temp, ",");

        while (pointer != nullptr) 
        {   
            if (isalpha(pointer[0]))
            {
                throw Set(setsAsStrings[i]);
                return false;
            }

            if (atof(pointer) - atoi(pointer) > 0)
            {
                throw Set(setsAsStrings[i]);
                return false;
            }
            
            pointer = strtok(nullptr, ",");
        }
    }

    return true;
}

void show_operations() 
{   
    while (true)
    {
        try
        {   
            char **setsAsStrings = new char*[SET_NUMBER];

            for (int i = 0; i < SET_NUMBER; i++)
            {
                setsAsStrings[i] = new char[80];
            }

            cin >> setsAsStrings[0];
            cin >> setsAsStrings[1];
            cin >> setsAsStrings[2];
            cin >> setsAsStrings[3];

            isCorrectType(setsAsStrings);

            Set A(setsAsStrings[0]);
            Set B(setsAsStrings[1]);
            Set C(setsAsStrings[2]);
            Set D(setsAsStrings[3]);

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
        catch(Set e)
        {
            e.not_integer_report();
            cout << "Try again!" << endl;
        }
    }
}

int main() 
{   
    show_operations();
    return 0;
}