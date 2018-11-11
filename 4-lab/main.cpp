#include <iostream>
#include "currencyExchange.h"

using namespace std;

int main(int argc, char **argv)
{   
    string fromCurrency       (argv[1]); // 
    string toCurrency         (argv[2]); // parsing data from command line
    float  amount =       atof(argv[3]); //
    float  exchangeRate = atof(argv[4]); // 

    return 0;
}
