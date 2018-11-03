#include <iostream>
#include "currencyExchange.h"
#include "exchangeRate.h"

using namespace std;

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
    return amountToExchange * USD_TO_EUR;
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

float CurrencyReserve::get_UAH_amount()
{
    return uah.get_amount();
}