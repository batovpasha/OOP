#include <iostream> 
#include "integration.h"

using namespace std;

void testing()
{   
    cout << "Function: x^2" << endl;

    double a, b, n;

    cout << "Enter begin value of interval: ";
    cin >> a;

    cout << "Enter end value of interval: ";
    cin >> b;

    cout << "Enter number of number of subintervals: ";
    cin >> n;

    Integration *integration;

    // calculating integral using trapezoidal rule
    integration = new TrapezoidalRule;
    integration->set_values(a, b, n);

    cout << "Result of integration using trapezoidal rule: ";
    integration->print_result_of_calculating();

    cout << "Delete TrapezoidalRule class object: ";
    delete integration;

    // calculating integral using Left Riemann sum 
    integration = new LeftRiemannSum;
    integration->set_values(a, b, n);

    cout << "Result of integration using Left Riemann sum: ";
    integration->print_result_of_calculating();    
    
    cout << "Delete Left Riemann sum class object: ";
    delete integration;

    // calculating integral using Right Riemann sum
    integration = new RightRiemannSum;
    integration->set_values(a, b, n);

    cout << "Result of integration using Right Riemann sum: ";
    integration->print_result_of_calculating();

    cout << "Delete Right Riemann sum class object: ";
    delete integration;
}

int main()
{   
    testing();
    return 0;
}