class Currency
{   
    protected:
        float amount;

    public:
        void  set_amount(float);
        float get_amount();
};

class UAH: public Currency
{
    float exchangeRate;

    public:
        UAH(float);
};

class USD: public Currency
{
    float exchangeRate;

    public:
        USD(float);
};

class EUR: public Currency
{
    float exchangeRate;

    public:
        EUR(float);
};

template <class T>
class Client
{
    T currency;

    public:
        Client();
        float get_amount();
};

template <class T>
class Cashier
{
    T reserve;

    public:
        Cashier();
};