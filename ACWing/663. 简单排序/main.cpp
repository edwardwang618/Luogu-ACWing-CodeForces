#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int d = a, e = b, f = c;
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    cout << a << endl << b << endl << c << endl;
    cout << endl;
    cout << d << endl << e << endl << f << endl;

    return 0;
}