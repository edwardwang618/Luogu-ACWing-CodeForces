#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    switch (x) {
        case 61: puts("Brasilia"); break;
        case 71: puts("Salvador"); break;
        case 11: puts("Sao Paulo"); break;
        case 21: puts("Rio de Janeiro"); break;
        case 32: puts("Juiz de Fora"); break;
        case 19: puts("Campinas"); break;
        case 27: puts("Vitoria"); break;
        case 31: puts("Belo Horizonte"); break;
        default: puts("DDD nao cadastrado"); break;
    }

    return 0;
}