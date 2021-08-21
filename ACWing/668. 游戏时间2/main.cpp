#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int hour, minute;
    if (d >= b) {
        minute = d - b; hour = c - a;
    } else {
        minute = d + 60 - b; hour = c - a - 1;
    }

    if (hour < 0) hour += 24;
    if (!hour && !minute) hour = 24;

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)", hour, minute);

    return 0;
}