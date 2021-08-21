#include <iostream>
using namespace std;

int main() {    
    double a, b, c;
    cin >> a >> b >> c;
    if (a < b) swap(a, b);
    if (a < c) swap(a, c);
    if (b < c) swap(b, c);

    if (a >= b + c) puts("NAO FORMA TRIANGULO");
    else {
        int aa = a * a, bb = b * b, cc = c * c;
        if (aa == bb + cc) puts("TRIANGULO RETANGULO");
        else if (aa > bb + cc) puts("TRIANGULO OBTUSANGULO");
        else puts("TRIANGULO ACUTANGULO");

        if (a == b && a == c) puts("TRIANGULO EQUILATERO");
        else if (a == b || a == c || b == c) puts("TRIANGULO ISOSCELES");
    }

    return 0;
}