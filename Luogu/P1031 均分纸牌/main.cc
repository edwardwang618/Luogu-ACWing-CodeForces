#include <iostream>
using namespace std;

int pile[105];

int main() {
    int N;
    cin >> N;

    int tot = 0;
    for (int i = 0; i < N; i++) {
        cin >> pile[i];
        tot += pile[i];
    }

    int avg = tot / N;

    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (pile[i] != avg) {
            pile[i + 1] += pile[i] - avg;
            count++;
        }
    }

    cout << count << endl;
    return 0;
}