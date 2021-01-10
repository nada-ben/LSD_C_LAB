#include<stdio.h>
#include<stdlib.h>
double f(double x)
{
        return x;
}

double trapeze(double(*f)(double),double a, double b, double n)
{
        float h=(b-a)/n;
        double z=0.5*(f(a)+f(b));
        for (int i=1;i<n;i++)
        {
                double x=a+i*h;
                z+=f(x);
        }
       return z*h;
}
int main()
{
        double a=1;
        double b=2;
        double n=100;
        double i=trapeze(f,a,b,n);
        printf("le resulta est :%f",i);
        return 0;
}
