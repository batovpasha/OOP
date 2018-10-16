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

    // calculating integral using trapezoidal rule
    Integration *integrationByTrapezoidalRule = new TrapezoidalRule;
    integrationByTrapezoidalRule->set_values(a, b, n);

    cout << "Result of integration using trapezoidal rule: ";
    integrationByTrapezoidalRule->print_result_of_calculating();


    // calculating integral using Left Riemann sum 
    Integration *integrationByLeftRiemannSum = new LeftRiemannSum;
    integrationByLeftRiemannSum->set_values(a, b, n);

    cout << "Result of integration using Left Riemann sum: ";
    integrationByLeftRiemannSum->print_result_of_calculating();    
    
    
    // calculating integral using Right Riemann sum
    Integration *integrationByRightRiemannSum = new RightRiemannSum;
    integrationByRightRiemannSum->set_values(a, b, n);

    cout << "Result of integration using Right Riemann sum: ";
    integrationByRightRiemannSum->print_result_of_calculating();

    // Memory cleaning
    cout << "Memory cleaning:" << endl;

    delete integrationByTrapezoidalRule;
    delete integrationByLeftRiemannSum;
    delete integrationByRightRiemannSum;
}

int main()
{   
    testing();
    return 0;
}