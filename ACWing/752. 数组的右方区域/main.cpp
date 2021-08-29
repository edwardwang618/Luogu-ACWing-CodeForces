#include <iostream>
using namespace std;

int main() {
    double x, sum = 0.0, cnt = 0;
    char ch;
    cin >> ch;
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++) {
            cin >> x;
            if (i < j && i + j > 11) sum += x, cnt++;
        }

    if (ch == 'S') printf("%.1lf\n", sum);
    else printf("%.1lf\n", sum / cnt);

    return 0;
}