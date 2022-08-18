#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double N1, N2, N3, N4, media;
    int l;
    cin >> N1 >> N2 >> N3 >> N4;
    media = (N1 * 2 + N2 * 3 + N3 * 4 + N4 * 1) / 10.0;
    l = round(media * 100);
    if (l % 10 >= 5) media = (double) (l / 10) / 10 + 0.1;
    else media = (double) (l / 10) / 10;
    printf("Media: %.1lf\n", media);
    if (media >= 7) cout << "Aluno aprovado." << endl;
    else if (media < 5) cout << "Aluno reprovado." << endl;
    else {
        cout << "Aluno em exame." << endl;
        double Y, Z;
        cin >> Y;
        printf("Nota do exame: %.1lf\n", Y);
        Z = (media + Y) / 2;
        if (Z >= 5) cout << "Aluno aprovado." << endl;
        else cout << "Aluno reprovado." << endl;
        printf("Media final: %.1lf", Z);
    }
    
    return 0;
}