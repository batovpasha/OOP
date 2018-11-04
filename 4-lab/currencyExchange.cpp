#include <iostream>
#include "currencyExchange.h"

using namespace std;

const float UAH_TO_USD = 0.04;
const float UAH_TO_EUR = 0.03;

const float USD_TO_UAH = 28.16;
const float USD_TO_EUR = 0.88;

const float EUR_TO_UAH = 32.08;
const float EUR_TO_USD = 1.14;

void Currency::set_amount(float _amount)
{
    amount = _amount;
}

float Currency::get_amount()
{
    return amount;
}

float UAH::to_USD(float amountToExchange)
{
    return amountToExchange * UAH_TO_USD;
}

float UAH::to_EUR(float amountToExchange)
{
    return amountToExchange * UAH_TO_EUR;
}

float USD::to_UAH(float amountToExchange)
{
    return amountToExchange * USD_TO_UAH;
}

float USD::to_EUR(float amountToExchange)
{
    return amountToExchange * USD_TO_EUR;
}

float EUR::to_UAH(float amountToExchange)
{
    return amountToExchange * EUR_TO_UAH;
}

float EUR::to_USD(float amountToExchange)
{
    return amountToExchange * EUR_TO_USD;
}

CurrencyReserve::CurrencyReserve()
{
    srand(time(nullptr));

    uah.set_amount(rand() % 4501 + 500); // reserve from 500 to 5000 for each currency
    usd.set_amount(rand() % 4501 + 500); //
    eur.set_amount(rand() % 4501 + 500); //
}

float CurrencyReserve::get_UAH_amount()
{
    return uah.get_amount();
}

float CurrencyReserve::get_USD_amount()
{
    return usd.get_amount();
}

float CurrencyReserve::get_EUR_amount()
{
    return eur.get_amount();
}

void CurrencyReserve::print_reserve()
{
    cout << "UAH: " << get_UAH_amount() << endl;
    cout << "USD: " << get_USD_amount() << endl;
    cout << "EUR: " << get_EUR_amount() << endl;
}