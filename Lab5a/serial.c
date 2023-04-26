#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double f(double x);
void Trap(double a, double b, int n, double *global_result_p);

int main(int argc, char *argv[]) {
double global_result = 0.0;
double a, b;
int n;

printf("Enter a, b, and n\n");
scanf("%lf %lf %d", &a, &b, &n);

Trap(a, b, n, &global_result);

printf("With n = %d trapezoids, our estimate\n", n);
printf("of the integral from %f to %f = %.14e\n", a, b, global_result);

return 0;
}

double f(double x) {
return exp(x);
}

void Trap(double a, double b, int n, double *global_result_p) {
double h = (b - a) / n;
double x, my_result = 0.0;

for (int i = 0; i < n; i++) {
x = a + i * h;
my_result += f(x) + f(x + h);
}

my_result *= h / 2.0;
*global_result_p += my_result;
}
