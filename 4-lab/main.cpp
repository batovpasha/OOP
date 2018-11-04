#include <iostream>
#include <cstring>
#include "currencyExchange.h"

using namespace std;

bool isEnoughMoneyInReserve(CurrencyReserve *reserve, string fromCurrency, string toCurrency, float amount)
{   
    if (fromCurrency == "UAH")
    {
        UAH uah;

        if (toCurrency == "USD")
        {
            if (uah.to_USD(amount) > reserve->get_USD_amount())
                return false;
        }

        if (toCurrency == "EUR")
        {
            if (uah.to_EUR(amount) > reserve->get_EUR_amount())
                return false;
        }
    }

    if (fromCurrency == "USD")
    {   
        USD usd;

        if (toCurrency == "UAH")
        {   
            if (usd.to_UAH(amount) > reserve->get_UAH_amount())
                return false;
        }

        if (toCurrency == "EUR")
        {
            if (usd.to_EUR(amount) > reserve->get_EUR_amount())
                return false;
        }
    }

    if (fromCurrency == "EUR")
    {   
        EUR eur;

        if (toCurrency == "UAH")
        {
            if (eur.to_UAH(amount) > reserve->get_UAH_amount())
                return false;
        }

        if (toCurrency == "USD")
        {
            if (eur.to_USD(amount) > reserve->get_USD_amount())
                return false;
        }
    }

    return true;
}

void currencyExchange(string fromCurrency, string toCurrency, float amount)
{
    CurrencyReserve *reserve = new CurrencyReserve();

    cout << "Reserve: " << endl;
    reserve->print_reserve();

    if (!isEnoughMoneyInReserve(reserve, fromCurrency, toCurrency, amount))
    {
        cout << "Sorry, not enough money in reserve for the operation." << endl;
        return;
    }



}

int main(int argc, char **argv)
{   
    string fromCurrency    (argv[1]); // 
    string toCurrency      (argv[2]); // parsing data from command line
    float  amount =    atof(argv[3]); //

    currencyExchange(fromCurrency, toCurrency, amount);

    return 0;
}
