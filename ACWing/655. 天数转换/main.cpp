#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    printf("%d ano(s)\n", n / 365); n %= 365;
    printf("%d mes(es)\n", n / 30); n %= 30;
    printf("%d dia(s)\n", n);
    return 0;
}