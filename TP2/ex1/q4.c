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
int main()
{
  double a=1;
  double b=2;
  double n=100;
  double integr=simpson(f,a,b,n);
  printf("le resultat est : %f",integr);
  return 0;
  }
