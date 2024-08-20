#include <stdio.h>
#include <math.h>

// Define the function to integrate
double f(double x) {
    // Example function: f(x) = x^2
    return x * x;
}

// Trapezoidal rule function
double trapezoidal(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n; // Width of each trapezoid
    double sum = 0.5 * (func(a) + func(b)); // Sum of the first and last terms

    for (int i = 1; i < n; i++) {
        sum += func(a + i * h); // Sum of the middle terms
    }

    return sum * h; // Multiply by the width to get the integral
}

int main() {
    double a, b;
    int n;

    // Input range and number of intervals
    printf("Enter the lower limit of integration (a): ");
    scanf("%lf", &a);
    printf("Enter the upper limit of integration (b): ");
    scanf("%lf", &b);
    printf("Enter the number of intervals (n): ");
    scanf("%d", &n);

    // Calculate the integral
    double result = trapezoidal(f, a, b, n);

    // Output the result
    printf("The approximate value of the integral is: %.6lf\n", result);

    return 0;
}
