#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a % b == 0 || b % a == 0) puts("Sao Multiplos");
    else puts("Nao sao Multiplos");

    return 0;
}