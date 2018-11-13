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

template <class FromCurrency, class ToCurrency>
class Cashier
{
    public:
        bool check_reserve(FromCurrency, ToCurrency);
        void print_reserve(ToCurrency reserveAmount);
};

template <class FromCurrency, class ToCurrency>
class Client
{
    FromCurrency amountToExchange;

    public:
        Client();
        float        get_amount_to_exchange();
        FromCurrency get_currency();
        void         request_for_exchange(Cashier<FromCurrency, ToCurrency>&, ToCurrency);
};

template <class T>
class Receipt
{
    string fromCurrency;
    string toCurrency;
    float  exchangeRate;
    T      currency;
    string date;

    public:
        Receipt(string, string, float, T, string);
        void print();
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

template <class FromCurrency, class ToCurrency>
Client<FromCurrency, ToCurrency>::Client()
{
    amountToExchange.set_amount(rand() % 1501 + 500); // set amount from 500 to 2000
}

template <class FromCurrency, class ToCurrency>
float Client<FromCurrency, ToCurrency>::get_amount_to_exchange()
{
    return amountToExchange.get_amount();
}

template <class FromCurrency, class ToCurrency>
FromCurrency Client<FromCurrency, ToCurrency>::get_currency()
{
    return amountToExchange;
}

template <class FromCurrency, class ToCurrency>
void Client<FromCurrency, ToCurrency>::request_for_exchange(Cashier<FromCurrency, ToCurrency> &cashier, ToCurrency reserveCurrency)
{
    if (cashier.check_reserve(get_currency(), reserveCurrency))
        cout << "Exchange is possible!" << endl;
    else 
        cout << "Sorry, not enough money in reserve for exchange." << endl;
}

template <class FromCurrency, class ToCurrency>
bool Cashier<FromCurrency, ToCurrency>::check_reserve(FromCurrency clientCurrency, ToCurrency reserveCurrency)
{  
    if (reserveCurrency.get_amount() >= clientCurrency.get_amount() * reserveCurrency.get_exchange_rate())
        return true;

    return false;
}

template <class FromCurrency, class ToCurrency>
void Cashier<FromCurrency, ToCurrency>::print_reserve(ToCurrency reserveAmount)
{
    cout << "Reserve: " << reserveAmount.get_amount() << endl;
}

template <class T>
Receipt<T>::Receipt(string _fromCurrency, string _toCurrency, float _exchangeRate, T _currency, string _date) 
{
    fromCurrency = _fromCurrency;
    toCurrency   = _toCurrency;
    exchangeRate = _exchangeRate;
    currency     = _currency;
    date         = _date;
}

template <class T>
void Receipt<T>::print()
{
    cout << "From currency: " << fromCurrency          << endl;
    cout << "To currency: "   << toCurrency            << endl;
    cout << "Exchange rate: " << exchangeRate          << endl;
    cout << "Amount: "        << currency.get_amount() << endl;
    cout << "Date: "          << date                  << endl;
}