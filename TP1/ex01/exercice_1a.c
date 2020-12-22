#include <stdio.h>
#define N 10
float *descente(float A[N][N], float B[N], int n)
{
  float   *x;
  float    s;
  int     i,j;

  /* Here we allocate the result verctor \
  (you're gonna do it yourself in the next exercises)*/
  x = malloc(sizeof(float) * n);


  x[0] = B[0] / A[0][0];

  for (i= 1; i < n; i++)
  {
	  s = 0;
          for (j = 0; j <= i-1; j++)
	  {	
		  s += A[i][j] * x[j];
          }
	  x[i] = (B[i] - s) / A[i][i];
  }

  return (x);
}
int main()
{
  float A[N][N], B[N], X[N];
  int n;
  int i, j;
  float s;

  printf("Enter the size of the matrix: ");
  scanf("%d", &n);

  /* Filling the matrix A */
  printf("Filling the matrix A\n");
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      printf("A[%d][%d] = ", i, j);
      scanf("%f", &A[i][j]);
    }
  }

  /* Filling the matrix B*/
  printf("Filling the matrix B\n");
  for (i = 0; i < n; i++)
  {
    printf("B[%d] = ", i);
    scanf("%f", &B[i]);
  }

  /*Apllying forward substitution*/
  X[0] = B[0]/A[0][0];
  for (i = 1;i < n; i++)
  {
    s = 0;
    for (j=0;j<i;j++)
      s += A[i][j] * X[j];
    X[i] = (B[i] - s)/A[i][i];
  }

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (i = 0; i < n; i++)
    printf("%f%c", X[i], ",]"[i == n - 1]);
}
