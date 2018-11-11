#include <iostream>
#include "currencyExchange.h"

using namespace std;

void Currency::set_amount(float _amount)
{
    amount = _amount;
}

float Currency::get_amount()
{
    return amount;
}

UAH::UAH(float _exchangeRate)
{
    exchangeRate = _exchangeRate;
}

USD::USD(float _exchangeRate)
{
    exchangeRate = _exchangeRate;
}

EUR::EUR(float _exchangeRate)
{
    exchangeRate = _exchangeRate;
}

template <class T>
Client<T>::Client()
{
    srand(time(nullptr));

    currency.set_amount(rand() % 1501 + 500);
}

template <class T>
float Client<T>::get_amount()
{
    return currency.get_amount();
}

template <class T>
Cashier<T>::Cashier()
{
    reserve.set_amount(rand() % 3501 + 500);
}