class Integration
{   
    protected:
        double a, b, n;

    public:
        void set_values(double, double, double);
        double fn(double x);
        virtual double calculate() = 0;
        void print_result_of_calculating();
};

class TrapezoidalRule: public Integration
{   
    public:
        double calculate();
};

class LeftRiemannSum: public Integration
{
    public:
        double calculate();
};

class RightRiemannSum: public Integration
{
    public:
        double calculate();
};
