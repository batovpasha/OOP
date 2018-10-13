#include <iostream>
#include "integration.h"

using namespace std;

void Integration::set_values(double _a, double _b, double _n)
{
    a = _a;
    b = _b;
    n = _n;
}

double Integration::fn(double x) // function for integration
{
    return x * x;
}

void Integration::print_result_of_calculating()
{
    cout << calculate() << endl;
}

double TrapezoidalRule::calculate()
{   
    double h = (b - a) / n;

    double sum = fn(a) + fn(b);

    for (int i = 1; i < n; i++)
        sum += 2 * fn(a + i * h);
    
    double result = (h / 2) * sum; 

    return result;
};

double LeftRiemannSum::calculate()
{
    double dx = abs(a - b) / n;
    double sum = 0.0;

    double x = a;

    for (x; x <= b; x += dx)
        sum += fn(x) * dx;
    
    return sum;
}

double RightRiemannSum::calculate()
{
    double dx = abs(a - b) / n;
    double sum = 0.0;

    double x = a + dx;

    for (x; x <= b; x += dx)
        sum += fn(x) * dx;
    
    return sum;
}





