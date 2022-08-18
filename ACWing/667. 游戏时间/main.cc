#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    cout << "O JOGO DUROU ";
    if (a < b)  cout << b - a ;
    else if (a == b) cout << 24;
    else cout << b + 24 - a;
    cout << " HORA(S)" << endl;

    return 0;
}