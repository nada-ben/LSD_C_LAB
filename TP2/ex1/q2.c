#include<stdio.h>
#include<stdlib.h>
double f(double x)
{
        return x;
}
double rectgauche(double (*f)(double),double a, double b, int n)
{
        float h=b-a/n;
        double s=0;
        double x;
        for(int i=1; i<n+1; i++)
        {
                x=a+i*h;
                s+=f(x);
        }
        return s*h;
}
int main()
{
        double a=0;
        double b=1;
        int n=100;
        double inte=rectgauche(f,a,b,n);
        printf("le resultat est %f",inte);
        return 0;
}
