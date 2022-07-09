#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
vector<int> post_stk;
stack<int> in_stk;
int pre_stk = 1;
int cnt;

void dfs() {
  if (cnt == 20) return;

  if (post_stk.size() == n) {
    for (int x : post_stk) printf("%d", x);
    puts("");
    cnt++;
    return;
  }

  if (in_stk.size()) {
    post_stk.push_back(in_stk.top());
    in_stk.pop();
    dfs();
    in_stk.push(post_stk.back());
    post_stk.pop_back();
  }

  if (pre_stk <= n) {
    in_stk.push(pre_stk++);
    dfs();
    in_stk.pop();
    pre_stk--;
  }
}

int main() {
  scanf("%d", &n);
  dfs();
}