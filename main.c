#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double integral_v20(double x);
double method_left_rectangle(double (*integral)(double), double a, double b, int n);
double method_right_rectangle(double (*integral)(double), double a, double b, int n);
double method_trapezoidal(double (*integral)(double), double a, double b, int n);
double method_simpson(double (*integral)(double), double a, double b, int n);


int main()
{
  	int method;
  	do
    {
  		printf("Vyberit' method:\n");
  		printf("(1 - method_left_rectangle; 2 - method_right_rectangle; 3 - method_trapezoidal; 4 - method_simpson)\n");
  		scanf("%d", &method);
    } while(method < 1 && method > 4);

  	double a;
  	printf("a = ");
  	scanf("%lf", &a);

  	double b;
  	printf("b = ");
  	scanf("%lf", &b);

  	int n;
  	printf("n = ");
  	scanf("%d", &n);

  	double result;
  	switch(method)
    {
      case 1:
        result = method_left_rectangle(integral_v20, a, b, n);
        break;
      case 2:
        result = method_right_rectangle(integral_v20, a, b, n);
        break;
      case 3:
        result = method_trapezoidal(integral_v20, a, b, n);
        break;
      case 4:
        result = method_simpson(integral_v20, a, b, n);
        break;
    }
    printf("result = %.3f", result);

  	return 0;
}

double integral_v20(double x)
{
    return pow(x, 4) + 3 * x;
}

double method_left_rectangle(double (*integral)(double), double a, double b, int n)
{
    double h = (b - a) / n;
    double s = 0;
    for(int i = 0; i <= n-1; ++i)
    {
        s += h * integral(a + i * h);
    }
    return s;
}

double method_right_rectangle(double (*integral)(double), double a, double b, int n)
{
    double h = (b - a) / n;
    double s = 0;
    for(int i = 0; i <= n; ++i)
    {
        s += h * integral(a + i * h);
    }
    return s;
}

double method_trapezoidal(double (*integral)(double), double a, double b, int n)
{
    double h = (b - a) / n;
    double s = integral(a) + integral(b);
    for(int i = 0; i <= n-1; ++i)
    {
        s += 2 * integral(a+ i * h);
    }
    s *= h / 2;
    return s;
}

double method_simpson(double (*integral)(double), double a, double b, int n)
{
    double h = (b - a) / n;
    double s = integral(a) + integral(b);
    for(int i = 0, k = 0; i <= n-1; ++i, k = 2 + 2 * (i % 2))
    {
        s += k * integral(a + i * h);
    }
    s *= h / 3;
    return s;
}
