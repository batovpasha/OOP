#include <iostream>
#include "integration.h"

using namespace std;

void TrapezoidalRule::set_values(double _a, double _b, double _n)
{
    a = _a;
    b = _b;
    n = _n;
}

double TrapezoidalRule::fn(double x)
{
    return x * x;
}

double TrapezoidalRule::calculate()
{   
    double h = abs(a - b) / n;

    double sum = fn(a) + fn(b);

    for (int i = 1; i < n; i++)
        sum += 2 * fn(a + i * h);
    
    double result = (h / 2) * sum; 

    return result;
};

void TrapezoidalRule::print_result_of_calculating()
{
    cout << calculate() << endl;
}

TrapezoidalRule::~TrapezoidalRule()
{
    cout << "Object of class TrapezoidalRule was destroyed!" << endl;
}

void LeftRiemannSum::set_values(double _a, double _b, double _n)
{
    a = _a;
    b = _b;
    n = _n;
}

double LeftRiemannSum::fn(double x)
{
    return x * x;
}

double LeftRiemannSum::calculate()
{
    double dx = abs(a - b) / n;
    double sum = 0.0;

    double x = a;

    for (x; x <= b; x += dx)
        sum += fn(x) * dx;
    
    return sum;
}

void LeftRiemannSum::print_result_of_calculating()
{
    cout << calculate() << endl;
}

LeftRiemannSum::~LeftRiemannSum()
{
    cout << "Object of class LeftRiemannSum was destroyed!" << endl;
}

void RightRiemannSum::set_values(double _a, double _b, double _n)
{
    a = _a;
    b = _b;
    n = _n;
}

double RightRiemannSum::fn(double x)
{
    return x * x;
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

void RightRiemannSum::print_result_of_calculating()
{
    cout << calculate() << endl;
}

RightRiemannSum::~RightRiemannSum()
{
    cout << "Object of class RightRiemannSum was destroyed!" << endl;
}

