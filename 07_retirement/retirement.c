#include<stdio.h>
#include<stdlib.h>

struct _retire_info {
    int months;
    double contribution;
    double rate_of_return;
};

typedef struct _retire_info retire_info;

// typedef struct _retire_info retire_info;

double calc_balance(double balance, double rate_of_interest, double contribution)
{
    double _bal=balance*(rate_of_interest+1) + contribution;
    return _bal;
}
void print_info(int month, double balance)
{
    int age=month/12;
    month=month%12;
    printf("Age %3d month %2d you have $%.2lf\n", age, month, balance);
}

void retirement(int startAge,//in months
        double initial, //initial savings in dollors
                retire_info working, //info about working
                 retire_info retired //info about being retired
        )
{
    int age=startAge;
    int i;
    double balance=initial;

    for(i=0; i<working.months; i++)
    {
        print_info(age, balance);
        age++;
        balance=calc_balance(balance, working.rate_of_return, working.contribution);
    }
    
    for(i=0; i<retired.months; i++)
    {
        print_info(age, balance);
        age++;
        balance=calc_balance(balance, retired.rate_of_return, retired.contribution);
    }
}

int main()
{
    retire_info working = {489, 1000.0, 0.045/12};

    retire_info retired = {384, -4000.0, 0.01/12};

    int startAge=327;
    int initial=21345;

    retirement(startAge, initial, working, retired);

    return 0;
}
