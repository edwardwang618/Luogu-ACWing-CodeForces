#include <iostream>
using namespace std;

int main() {
    int kilo;
    double oil;
    cin >> kilo >> oil;
    printf("%.3lf km/l\n", kilo / oil);
    return 0;
}