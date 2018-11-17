#include <iostream>
#include <fstream>

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
        bool check_reserve(FromCurrency, ToCurrency&);
        void print_reserve(ToCurrency);
        bool give_amount_in_certain_bills(float, ToCurrency&);
        bool check_for_critical_minimum(Currency*);
};

template <class FromCurrency, class ToCurrency>
class Client
{
    FromCurrency amountToExchange;

    public:
        Client();
        float        get_amount_to_exchange();
        FromCurrency get_currency();
        bool         request_for_exchange(Cashier<FromCurrency, ToCurrency>&, ToCurrency&);
        void         ask_to_get_amount_in_certain_bills(Cashier<FromCurrency, ToCurrency>&, float, ToCurrency&);
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
        Receipt() {};
        Receipt(string, string, float, T, string);
        void print();
        void operator>>(ofstream&);
};

template <class T>
class Report
{
    T*    amountAtTheBeginning;
    T*    amountAtTheEnd;
    float profit = 0;

    public:
        void set_amount_at_the_beginning(T*);
        void set_amount_at_the_end(T*);
        void calculate_profit();
        void print();
        ~Report();
};

template <class T>
class ReceiptsCollection
{
    T* receipts;
    int currentPosition = 0;

    public:
        ReceiptsCollection(int);
        void add(T);
        void print_collection();
        ~ReceiptsCollection();
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
bool Client<FromCurrency, ToCurrency>::request_for_exchange(Cashier<FromCurrency, ToCurrency> &cashier, 
                                                            ToCurrency &reserveCurrency)
{
    if (cashier.check_reserve(get_currency(), reserveCurrency))
    {
        cout << "Exchange is possible!" << endl;
        return true;
    }
    else {
        cout << "Sorry, not enough money in reserve for exchange." << endl;
        return false;
    }
}

template <class FromCurrency, class ToCurrency>
void Client<FromCurrency, ToCurrency>::ask_to_get_amount_in_certain_bills(Cashier<FromCurrency, ToCurrency>& cashier,
                                                                          float amount,  
                                                                          ToCurrency &reserveCurrency)
{
    cashier.give_amount_in_certain_bills(amount, reserveCurrency);
}

template <class FromCurrency, class ToCurrency>
bool Cashier<FromCurrency, ToCurrency>::check_reserve(FromCurrency clientCurrency, ToCurrency &reserveCurrency)
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

template <class FromCurrency, class ToCurrency>
bool Cashier<FromCurrency, ToCurrency>::give_amount_in_certain_bills(float      amount, 
                                                                     ToCurrency &reserveCurrency)
{
    int bills[] = { 10, 20, 50, 100 };
    int size = sizeof(bills) / sizeof(int);

    int randomBill = bills[rand() % size];

    if ((int) (amount * reserveCurrency.get_exchange_rate()) % randomBill == 0.0)
        cout << "Give out the amount in " << randomBill << " bills." << endl;
    else 
        cout << "Can not give out the amount in " << randomBill << " bills!" << endl;
    
    reserveCurrency.set_amount(reserveCurrency.get_amount() 
                            -  amount 
                            *  reserveCurrency.get_exchange_rate());
}

template <class FromCurrency, class ToCurrency>
bool Cashier<FromCurrency, ToCurrency>::check_for_critical_minimum(Currency *currencies)
{
    for (int i = 0; i < 3; i++)
    {
        if (currencies[i].get_amount() < 1000)
        {
            cout << "Critical minimum for the " << (i + 1) << " currency!" << endl;
        }
    }
}

template <class T>
Receipt<T>::Receipt(string _fromCurrency, 
                    string _toCurrency, 
                    float  _exchangeRate, 
                    T      _currency, 
                    string _date) 
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

template <class T>
void Receipt<T>::operator>>(ofstream &file)
{
    file << "From currency: " << fromCurrency          << endl;
    file << "To currency: "   << toCurrency            << endl;
    file << "Exchange rate: " << exchangeRate          << endl;
    file << "Amount: "        << currency.get_amount() << endl;
    file << "Date: "          << date                  << endl;

    file.close();
}

template <class T>
void Report<T>::set_amount_at_the_beginning(T* currencies)
{
    amountAtTheBeginning = currencies;
}

template <class T>
void Report<T>::set_amount_at_the_end(T* currencies)
{
    amountAtTheEnd = currencies;
}

template <class T>
void Report<T>::print()
{
    cout << "Array of amounts at the beginning: ";

    for (int i = 0; i < 3; i++)
        cout << amountAtTheBeginning[i].get_amount() << " ";
    
    cout << endl;

    cout << "Array of amounts at the end: ";

    for (int i = 0; i < 3; i++)
        cout << amountAtTheEnd[i].get_amount() << " ";
    
    cout << endl;

    cout << "Daily profit: " << profit << endl;
}

template <class T>
void Report<T>::calculate_profit()
{
    for (int i = 0; i < 3; i++)
    {
        profit += abs(amountAtTheEnd[i].get_amount() - amountAtTheBeginning[i].get_amount()) * 0.1;
    }
}

template <class T>
Report<T>::~Report()
{
    delete[] amountAtTheBeginning;
    delete[] amountAtTheEnd;

    cout << "Report has been deleted!" << endl;
}

template <class T>
ReceiptsCollection<T>::ReceiptsCollection(int size)
{
    receipts = new T[size];
}

template <class T>
void ReceiptsCollection<T>::add(T receipt)
{
    receipts[currentPosition] = receipt;

    cout << endl;
    cout << "Receipt from receipts collection:" << endl;
    receipts[currentPosition].print();

    currentPosition++;
}

template <class T>
ReceiptsCollection<T>::~ReceiptsCollection()
{
    delete[] receipts;

    cout << "Receipts collection have been deleted!" << endl;
}

