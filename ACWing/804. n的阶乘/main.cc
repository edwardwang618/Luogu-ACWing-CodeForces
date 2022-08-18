#include <iostream>
using namespace std;

int fact(int n) {
    int res = 1;
    while (n > 1) {
        res *= n--;
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    cout << fact(n) << endl;
    return 0;
}