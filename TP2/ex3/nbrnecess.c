#include<stdio.h>
#include<stdlib.h>
double f(double x)
{
        return x;
}
double simpson(double(*f)(double),double a, double b, double n)
{
        float h=(b-a)/n;
        double x=a+h;
        double z=(a+h)/2;
        double integ1=0;
        double integ2=f(z);
        for (int i=0;i++;i<n-1)
        {
                z+=h;
                integ1+=f(x);
                integ2+=f(z);
                x+=h;

        }
        return (h/6)*(f(a)+f(b)+2*integ1+4*integ2);
        }

double nombrnec(double(*f)(double),double a, double b, double err, double(*meth)(double (*)(double),double ,double ,double), double I)
{
        int n=1;
        while(abs(meth(f,a,b,n)-I)>err)
        {n=n+1;
        }
        return n;
        }
int main()
{
 double a=0;
 double b=1;
 double  n=100;
 double I=0.5;
 double nb=nombrnec(f,a,b,0.01,simpson,I);
 printf("le resultat est :%f",nb);
 return 0;
 }
