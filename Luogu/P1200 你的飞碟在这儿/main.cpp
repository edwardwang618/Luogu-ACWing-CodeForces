#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int x = 1, y = 1;
    for (char ch : a) x = x * (ch - 'A' + 1) % 47;
    for (char ch : b) y = y * (ch - 'A' + 1) % 47;
    if (x == y) puts("GO");
    else puts("STAY");

    return 0;
}