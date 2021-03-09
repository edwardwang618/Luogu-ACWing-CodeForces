#include <iostream>
#include <vector>
using namespace std;

const int N = 55;
int n;
int a[N];
vector<long> f[N][N];

vector<long> mul(vector<long> A, int b) {
    vector<long> C;
    if (A.empty()) return C;
    long t = 0;
    for (int i = 0; i < A.size() || t; i++) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    return C;
}

vector<long> add(vector<long> A, vector<long> B) {
    if (A.empty()) return B;
    else if (B.empty()) return A;

    vector<long> C;
    long t = 0;
    for (int i = 0; i < A.size() || i < B.size() || t; i++) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    return C;
}

int cmp(vector<long> A, vector<long> B) {
    if (A.size() != B.size()) return A.size() > B.size() ? 1 : -1;
    for (int i = A.size() - 1; i >= 0; i--)
        if (A[i] != B[i]) return A[i] > B[i] ? 1 : -1;
    return 0;
}

void printv(vector<long> A) {
    for (int i = A.size() - 1; i >= 0; i--) cout << A[i];
    cout << endl;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int len = 3; len <= n; len++)
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            for (int i = 0; i < 34; i++) f[l][r].push_back(0);
            f[l][r].push_back(1);

            for (int k = l + 1; k < r; k++) {
                vector<long> tmp;
                tmp.push_back(1);
                tmp = mul(tmp, a[l]);
                tmp = mul(tmp, a[k]);
                tmp = mul(tmp, a[r]);
                if (len == 3) f[l][r] = tmp;
                else {
                    tmp = add(tmp, f[l][k]);
                    tmp = add(tmp, f[k][r]);
                    if (cmp(tmp, f[l][r]) < 0) f[l][r] = tmp;
                }
            }
        }

    printv(f[1][n]);

    return 0;
}