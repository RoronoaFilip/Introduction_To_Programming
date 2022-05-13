#include <cmath>
#include <iostream>
using namespace std;
double fabs(double a, double b) {
    double x = a - b;
    return (x >= 0) ? x : -x;
}
double sqrt_a(double a, double eps) {
    double x = a;
    double x1 = (a + 1) / 2;
    while (fabs(x1, x) >= eps) {
        x = x1;
        x1 = (x1 + a / x1) / 2;
    }
    return x1;
}
int main() {
    double x = 4;
    const double eps = 1e-100;
    cout << sqrt_a(x, eps);
    cout << endl;
    cout << sqrt(x);

    cout << endl;

    double y = 9;
    cout << sqrt_a(y, eps);
    cout << endl;
    cout << sqrt(y);
    return 0;
}