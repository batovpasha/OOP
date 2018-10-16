class Integration
{   
    protected:           // a - begin of integration interval    
        double a, b, n;  // b - end of integration interval
                         // n - number of subintervals for integration
    public:
        virtual void set_values(double, double, double) = 0;
        virtual double fn(double) = 0; 
        virtual double calculate() = 0;
        virtual void print_result_of_calculating() = 0;
        virtual ~Integration() {};
};

class TrapezoidalRule: public Integration
{   
    public:
        void set_values(double, double, double);
        double fn(double);
        double calculate();
        void print_result_of_calculating();
        ~TrapezoidalRule();
};

class LeftRiemannSum: public Integration
{
    public:
        void set_values(double, double, double);
        double fn(double);
        double calculate();
        void print_result_of_calculating();
        ~LeftRiemannSum();
};

class RightRiemannSum: public Integration
{
    public:
        void set_values(double, double, double);
        double fn(double);
        double calculate();
        void print_result_of_calculating();
        ~RightRiemannSum();
};
