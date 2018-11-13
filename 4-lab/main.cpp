#include <iostream>
#include "currencyExchange.h"

using namespace std;

string get_current_date()
{
    time_t now = time(0);
   
    // convert now to string form
    char* dt = ctime(&now);

    string date(dt);

    return date;
}

void currencyExchange(string fromCurrency, string toCurrency, float rate)
{   
    Client<UAH, USD> client;
    
    // generating currency reserve
    UAH uah(rate);
    USD usd(rate);
    EUR eur(rate);

    Cashier<UAH, USD> cashier;
    cashier.print_reserve(usd);
    
    client.request_for_exchange(cashier, usd);
    
    // creating a receipt
    Receipt<UAH> receipt(fromCurrency, 
                         toCurrency, 
                         rate, 
                         client.get_currency(), 
                         get_current_date());

    cout << "Receipt: " << endl;
    receipt.print();

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
