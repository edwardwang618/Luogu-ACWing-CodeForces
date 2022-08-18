#include <iostream>
using namespace std;

int main() {
    int id1, cnt1, id2, cnt2;
    double p1, p2;
    cin >> id1 >> cnt1 >> p1 >> id2 >> cnt2 >> p2;
    printf("VALOR A PAGAR: R$ %.2lf\n", cnt1 * p1 + cnt2 * p2);
    return 0;
}