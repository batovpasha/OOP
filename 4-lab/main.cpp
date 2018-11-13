#include <iostream>
#include "currencyExchange.h"

using namespace std;

void currencyExchange(string fromCurrency, string toCurrency, float rate)
{   
    Client<UAH> client;
    
    // generating currency reserve
    UAH uah(rate);
    USD usd(rate);
    EUR eur(rate);

    Cashier<UAH, USD> cashier;

    cout << client.get_amount_to_exchange() << endl;
    cout << usd.get_amount() << endl;
    cout << usd.get_exchange_rate() << endl;

    cout << cashier.check_reserve(client.get_currency(), usd) << endl;
}

int main(int argc, char **argv)
{   
    string fromCurrency       (argv[1]); // 
    string toCurrency         (argv[2]); // parsing data from command line //
    float  exchangeRate = atof(argv[3]); // 

    srand(time(nullptr)); // for random numbers

    currencyExchange(fromCurrency, toCurrency, exchangeRate);

    return 0;
}
