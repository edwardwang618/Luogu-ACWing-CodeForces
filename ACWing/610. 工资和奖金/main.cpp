#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    double a, b;
    cin >> a >> b;
    printf("TOTAL = R$ %.2lf\n", a + b * 0.15);

    return 0;
}