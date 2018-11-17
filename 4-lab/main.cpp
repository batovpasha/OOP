#include <iostream>
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
    Client<UAH, USD> client;
    
    // generating currency reserve
    UAH uah(rate);
    USD usd(rate);
    EUR eur(rate);
    
    Report<Currency> *report = new Report<Currency>;

    Currency *currenciesAtTheBeginning = new Currency[3];
    
    currenciesAtTheBeginning[0] = uah;
    currenciesAtTheBeginning[1] = usd;
    currenciesAtTheBeginning[2] = eur;

    report->set_amount_at_the_beginning(currenciesAtTheBeginning);

    Cashier<UAH, USD> cashier;
    
    // creating a receipt
    Receipt<UAH> receipt(fromCurrency, 
                         toCurrency, 
                         rate, 
                         client.get_currency(), 
                         get_current_date());

    cout << "Receipt: " << endl;
    receipt.print();
    
    if (!client.request_for_exchange(cashier, usd))
        return;

    // ask cashier to get amount in certain bills
    client.ask_to_get_amount_in_certain_bills(cashier, client.get_amount_to_exchange(), usd);
    
    Currency *currenciesAtTheEnd = new Currency[3];

    currenciesAtTheEnd[0] = uah;
    currenciesAtTheEnd[1] = usd;
    currenciesAtTheEnd[2] = eur;

    report->set_amount_at_the_end(currenciesAtTheEnd);
    
    report->calculate_profit();

    cout << "Daily report: " << endl;
    report->print();

    ReceiptsCollection<Receipt<UAH>> *receiptsCollection = new ReceiptsCollection<Receipt<UAH>>(10);
    receiptsCollection->add(receipt);

    cashier.check_for_critical_minimum(currenciesAtTheEnd);

    delete report;
    delete receiptsCollection;

    ofstream file("output.txt");

    receipt >> file;

    file.close();
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
