#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool cmp(vector<int>& A, vector<int>& B) {
  if (A.size() != B.size()) return A.size() >= B.size();
  for (int i = A.size(); i >= 0; i--)
    if (A[i] != B[i]) return A[i] >= B[i];

  return true;
}

vector<int> subtract(vector<int>& A, vector<int>& B) {
  vector<int> C;
  for (int i = 0; i < A.size(); i++) {
    if (A[i] >= B[i])
      C.push_back(A[i] - B[i]);
    else {
      C.push_back(A[i] + 10 - B[i]);
      A[i + 1]--;
    }
  }

  while (C.size() > 1 && C.back() == 0) C.pop_back();

  return C;
}

int main() {
  string a, b;
  vector<int> A, B;

  cin >> a >> b;
  for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
  for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

  vector<int> C;
  if (cmp(A, B))
    C = subtract(A, B);
  else {
    C = subtract(B, A);
    printf("-");
  }

  for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);

  return 0;
}