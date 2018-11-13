#include <iostream>
#include <memory>
#include "currencyExchange.h"

using namespace std;

string get_current_date()
{
    time_t now = time(0);
   
    // convert now to string form
    char* dt = ctime(&now);

    string date(dt);

    return date;
}

void currencyExchange(string fromCurrency, string toCurrency, float rate)
{   
    unique_ptr<Client<UAH, USD>> client(new Client<UAH, USD>);
    
    // generating currency reserve
    UAH uah(rate);
    USD usd(rate);
    EUR eur(rate);

    unique_ptr<Report<Currency>> report(new Report<Currency>);
 
    vector<Currency> currenciesAtTheBeginning = { uah, usd, eur };

    report->set_amount_at_the_beginning(currenciesAtTheBeginning);

    Cashier<UAH, USD> cashier;
    
    // creating a receipt
    Receipt<UAH> receipt(fromCurrency, 
                         toCurrency, 
                         rate, 
                         client->get_currency(), 
                         get_current_date());

    cout << "Receipt: " << endl;
    receipt.print();
    
    if (!client->request_for_exchange(cashier, usd))
        return;

    // ask cashier to get amount in certain bills
    client->ask_to_get_amount_in_certain_bills(cashier, client->get_amount_to_exchange(), usd);

    vector<Currency> currenciesAtTheEnd = { uah, usd, eur };

    report->set_amount_at_the_end(currenciesAtTheEnd);
    
    report->calculate_profit();

    cout << "Daily report: " << endl;
    report->print();

    unique_ptr<ReceiptsCollection<Receipt<UAH>>> receiptsCollection(new ReceiptsCollection<Receipt<UAH>>(10));
    receiptsCollection->add(receipt);

    cashier.check_for_critical_minimum(currenciesAtTheEnd);
}

int main(int argc, char **argv)
{   
    string fromCurrency       (argv[1]); // 
    string toCurrency         (argv[2]); // parsing data from command line //
    float  exchangeRate = atof(argv[3]); // 

    srand(time(nullptr)); // for random numbers

    currencyExchange(fromCurrency, toCurrency, exchangeRate);

    return 0;
}
