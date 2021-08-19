#include <iostream>
using namespace std;

int main() {
    int i = 1;
    int a, b, res = 0;
    for (;i <= 7; i++) {
        cin >> a >> b;
        if (a + b > 8) if (!res) res = i; 
    }

    cout << res << endl;
    return 0;
}