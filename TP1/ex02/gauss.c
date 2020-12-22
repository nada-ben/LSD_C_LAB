#include <stdio.h>
#define N 10
float *remontee(float A[N][N], float B[N], int n)
{
  int i,j;
  float *x;
  float s;


  x = malloc(sizeof(float) * n);

  x[n - 1] = B[n - 1] / A[n -1][n - 1];
  
  for (i = n - 2; i >= 0; i--)
  {
     float s = 0;
     for (j = i + 1; j < n; j++)
     {
	     s += A[i][j] * x[j];
     }
     x[i] = (B[i] - s) / A[i][i];
  }

  return x;
}

float *gauss(float A[N][N] ,float B[N], int n)
{
  int i,j,k;
  float *x;

  x = malloc(sizeof(float) * n);

  
  for (k = 0; k < n - 1; k++)
  {
	 for (i = k + 1; i < n; i++)
	 {
		 float F = A[i][k] / A[k][k];
		 
		 for (j = k + 1; j < n; j++)
		 {
			 A[i][j] = A[i][j] - F * A[k][j];
		 }
		 B[i] = B[i] - F * B[k];
	 }
  } 
  x = remontee(A, B, n);
  return(x);
}
void get_input(float A[][N], float *B, int *n)
{
  printf("Enter the Matrix dimension: ");
  scanf("%d", n);
  /* get the input from the user */
  for (int i = 0; i < *n; i++)
  {
    for (int j = 0; j < *n; j++)
    {
      printf("A[%d][%d] = ", i, j);
      scanf("%f", &A[i][j]);
    }
  }
  for (int i = 0; i < *n; i++)
  {
    printf("B[%d] = ", i);
    scanf("%f", &B[i]);
  }
}
int main()
{
  float A[N][N], B[N], X[N];
  int n;
  get_input(A, B, &n);
  for (int k = 0; k < n - 1; k++)
  {
    for (int i = k + 1; i < n; i++)
    {
      float factor = A[i][k] / A[k][k];
      for (int j = k + 1; j < n; j++)
      {
        A[i][j] = A[i][j] - factor * A[k][j];
      }
      B[i] = B[i] - factor * B[k];
    }
  }
  X[n - 1] = B[n - 1] / A[n - 1][n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    float s = 0;
    for (int j = i + 1; j < n; j++)
    {
      s = s + A[i][j] * X[j];
    }
    X[i] = (B[i] - s) / A[i][i];
  }
  printf("Result vector X: ");
  for (int i = 0; i < n; i++)
    printf("%f ", X[i]);
  printf("\n");
  return 0;
}
