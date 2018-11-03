class Currency
{   
    protected:
        float amount;

    public:
        float get_amount();
};

class UAH: public Currency
{
    public:
        float to_USD(float);
        float to_EUR(float);
};

class USD: public Currency
{
    public:
        float to_UAH(float);
        float to_EUR(float);
};

class EUR: public Currency
{
    public:
        float to_UAH(float);
        float to_USD(float);
};

class CurrencyReserve
{
    UAH uah;
    USD usd;
    EUR eur;

    public:
        float get_UAH_amount();
        float get_USD_amount();
        float get_EUR_amount();
};
