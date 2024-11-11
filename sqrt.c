#include<stdio.h>

int closestSquare(double);
double power(double, int);
int factorial(int);
double linear_sqrt(double);
double quad_sqrt(double);
double general_sqrt(double x, int n);

int main(void)
{
  double input;
  int accuracy;

  printf("Enter input -> ");
  scanf("%lf", &input);
  printf("Enter accuracy -> ");
  scanf("%d", &accuracy);

  printf("%lf\n", general_sqrt(input, accuracy));

  return(0);
}

int closestSquare(double x)
{
  int previousSquare = 0;
  int nextSquare = 0;

  while (nextSquare * nextSquare < x)
  {
    previousSquare = nextSquare++;
  }

  return (nextSquare * nextSquare - x) > (x - previousSquare * previousSquare) ? previousSquare : nextSquare;
}

double power(double base, int exp)
{
  int negative = 0;
  if (exp < 0)
  {
    exp *= -1;
    negative = 1;
  }

  double output = 1;

  for (int i = 0; i < exp; i++)
  {
    output *= base;
  }

  return negative ? (1.0 / output) : output;
}

int factorial(int n)
{
  return n > 2 ? n * factorial(n - 1) : n;
}

double linear_sqrt(double x)
{
  int cs = closestSquare(x);
  return (1.0 / (2 * cs)) * (x - cs * cs) + cs;
}

double quad_sqrt(double x)
{
  int cs = closestSquare(x);
  return (-1.0 / (8 * power(cs, 3))) * power((x - cs * cs), 2) + (1.0 / (2 * cs)) * (x - cs * cs) + cs;
}

double general_sqrt(double x, int n)
{
  int cs = closestSquare(x);
  double approx = cs;

  double coefficient = 0.5;

  for (int k = 1; k <= n; k++)
  {
    approx += power(x - cs * cs, k) / factorial(k) * coefficient * power(cs, 1 - 2 * k);
    coefficient *= (1 - 2 * k) / 2.0;
  }

  return approx;
}
