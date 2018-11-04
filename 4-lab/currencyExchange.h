class Currency
{   
    protected:
        float amount;

    public:
        void set_amount(float);
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
        CurrencyReserve();
        float get_UAH_amount();
        float get_USD_amount();
        float get_EUR_amount();
        void print_reserve();
};
