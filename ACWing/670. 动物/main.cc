#include <iostream>
using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    if (a == "vertebrado") {
        if (b == "ave") {
            if (c == "carnivoro") puts("aguia");
            else puts("pomba");
        } else {
            if (c == "onivoro") puts("homem");
            else puts("vaca");
        }
    } else {
        if (b == "inseto") {
            if (c == "hematofago") puts("pulga");
            else puts("lagarta");
        } else {
            if (c == "hematofago") puts("sanguessuga");
            else puts("minhoca");
        }
    }

    return 0;
}