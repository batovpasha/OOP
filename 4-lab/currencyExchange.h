#include <iostream>

using namespace std;

class Currency
{   
    protected:
        float amount;
        float exchangeRate;

    public:
        void  set_amount(float);
        float get_amount();
        void  set_exchange_rate(float);
        float get_exchange_rate();
};

class UAH: public Currency
{
    public:
        UAH() {};
        UAH(float);
};

class USD: public Currency
{
    public:
        USD() {};
        USD(float);
};

class EUR: public Currency
{
    public:
        EUR() {};
        EUR(float);
};
 
template <class T>
class Client
{
    T amountToExchange;

    public:
        Client();
        float get_amount_to_exchange();
        T get_currency();
};

template <class FromCurrency, class ToCurrency>
class Cashier
{
    public:
        bool check_reserve(FromCurrency, ToCurrency);
};

void Currency::set_amount(float _amount)
{
    amount = _amount;
}

float Currency::get_amount()
{
    return amount;
}

void Currency::set_exchange_rate(float _exchangeRate)
{
    exchangeRate = _exchangeRate;
}

float Currency::get_exchange_rate()
{
    return exchangeRate;
}

UAH::UAH(float exchangeRate)
{
    set_exchange_rate(exchangeRate);

    set_amount(rand() % 3501 + 500); // set amount from 500 to 4000
}

USD::USD(float exchangeRate)
{
    set_exchange_rate(exchangeRate);

    set_amount(rand() % 3501 + 500); // set amount from 500 to 4000
}

EUR::EUR(float exchangeRate)
{
    set_exchange_rate(exchangeRate);

    set_amount(rand() % 3501 + 500); // set amount from 500 to 4000
}

template <class T>
Client<T>::Client()
{
    amountToExchange.set_amount(rand() % 1501 + 500); // set amount from 500 to 2000
}

template <class T>
float Client<T>::get_amount_to_exchange()
{
    return amountToExchange.get_amount();
}

template <class T>
T Client<T>::get_currency()
{
    return amountToExchange;
}

template <class FromCurrency, class ToCurrency>
bool Cashier<FromCurrency, ToCurrency>::check_reserve(FromCurrency clientAmount, ToCurrency reserveAmount)
{  
    if (reserveAmount.get_amount() >= clientAmount.get_amount() * reserveAmount.get_exchange_rate())
        return true;

    return false;
}