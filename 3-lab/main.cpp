#include <iostream> 
#include "integration.h"

using namespace std;

void testing()
{   
    cout << "Function: x^2" << endl;

    // calculating integral using trapezoidal rule
    Integration *integrationByTrapezoidalRule = new TrapezoidalRule;
    integrationByTrapezoidalRule->set_values(-1.0, 2.0, 2000);

    cout << "Result of integration using trapezoidal rule: ";
    integrationByTrapezoidalRule->print_result_of_calculating();

    // calculating integral using Left Riemann sum 
    Integration *integrationByLeftRiemannSum = new LeftRiemannSum;
    integrationByLeftRiemannSum->set_values(-1.0, 2.0, 2000);

    cout << "Result of integration using Left Riemann sum: ";
    integrationByLeftRiemannSum->print_result_of_calculating();    
    
    // calculating integral using Right Riemann sum
    Integration *integrationByRightRiemannSum = new RightRiemannSum;
    integrationByRightRiemannSum->set_values(-1.0, 2.0, 2000);

    cout << "Result of integration using Right Riemann sum: ";
    integrationByRightRiemannSum->print_result_of_calculating();
}

int main()
{   
    testing();
    return 0;
}