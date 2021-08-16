#include <iostream>
#include <vector>
using namespace std;

vector<int> multiply(vector<int>& A, vector<int>& B) {
    vector<int> C(A.size() + B.size(), 0);
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < B.size(); j++)
            C[i + j] += A[i] * B[j];

	// 处理一下进位
    for (int i = 0; i < C.size() - 1; i++) {
        C[i + 1] += C[i] / 10;
        C[i] %= 10;
    }
	
	// 去掉高位的0
    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

int main() {
    string a, b;
    cin >> a >> b;

    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    vector<int> C = multiply(A, B);
    for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);

    return 0;
}