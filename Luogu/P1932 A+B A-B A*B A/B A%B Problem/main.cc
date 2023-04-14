#include <cstring>
#include <iostream>

using namespace std;
using ll = long long;

const int N = 1e4 + 10, M = N >> 2;
#define sz 8

// MOD = 10 ^ sz
const ll MOD = 1e8;

char s1[N], s2[N];
// 0为非负，1为负
int sn1, sn2, sn;
ll a[M], b[M], s[M];
ll cp[M], lt[M];

void write(ll num[]);
void clear(ll num[]);
void rm(ll num[]);
void lm(ll num[]);
void cpy(ll num1[], ll num2[]);
int cmp(ll num1[], ll num2[]);
void pls(ll a[], ll b[]);
void mnu(ll a[], ll b[]);
void mul(ll a[], ll b[]);
void div(ll a[], ll b[]);

void write(ll num[]) {
  if (sn) putchar('-'), sn = 0;
  printf("%lld", num[num[0]]);
  for (int i = num[0] - 1; i; i--) printf("%08lld", num[i]);
  puts("");
}

// 将num清空变成数字0
void clear(ll num[]) {
  for (int i = num[0]; i; i--) num[i] = 0;
  num[0] = 1;
}

// num >>= 1
void rm(ll num[]) {
  for (int i = num[0]; i; i--) {
    if ((num[i] & 1) && i > 1) num[i - 1] += MOD;
    num[i] >>= 1;
  }
  if (!num[num[0]] && num[0] > 1) num[0]--;
}

// num <<= 1
void lm(ll num[]) {
  num[0]++;
  for (int i = 1; i <= num[0]; i++) {
    num[i] <<= 1;
    if (i > 1 && num[i - 1] >= MOD) num[i - 1] -= MOD, num[i]++;
  }
  if (!num[num[0]] && num[0] > 1) num[0]--;
}

// 将num2拷贝到num1上去
void cpy(ll num1[], ll num2[]) {
  for (int i = 0; i <= max(num1[0], num2[0]); i++) num1[i] = num2[i];
}

// 比较num1和num2，如果num1 > num2则返回1，<则返回-1，等于返回0
int cmp(ll num1[], ll num2[]) {
  if (num1[0] != num2[0]) return num1[0] > num2[0] ? 1 : -1;
  for (int i = num1[0]; i; i--)
    if (num1[i] != num2[i]) return num1[i] > num2[i] ? 1 : -1;
  return 0;
}

// 将s表示的从左向右读的十进制数表示为压8位的从低位到高位读的数
void init(char s[], ll num[]) {
  for (int i = strlen(s) - 1; i >= 0; i -= sz) {
    ll pw = 1;
    num[0]++;
    for (int j = i; j > i - sz && j >= 0; j--) {
      num[num[0]] += (s[j] - '0') * pw;
      pw *= 10;
    }
  }
}

// 求a + b将答案存进数组s中。如果a和b不同号，则用减法算。
void pls(ll a[], ll b[]) {
  // 如果a和b不同号
  if (sn1 ^ sn2) {
    // 如果a为负，a + b = b - (-a)
    if (sn1) sn1 ^= 1, mnu(b, a), sn1 ^= 1;
    // 如果b为负，a + b = a - (-b)
    if (sn2) sn2 ^= 1, mnu(a, b), sn2 ^= 1;
    return;
  }

  // 如果a和b都是负的，a + b = - ((-a) + (-b))
  if (sn1 & sn2) {
    sn1 = sn2 = 0, pls(a, b), sn = 1;
    // 将符号恢复原状
    sn1 = sn2 = 1;
    return;
  }

  clear(s);
  s[0] = max(a[0], b[0]);

  for (int i = 1; i <= s[0]; i++) {
    s[i] += a[i] + b[i];
    if (s[i] >= MOD) s[i] -= MOD, s[i + 1]++;
  }

  if (s[s[0] + 1]) s[0]++;
}

// 求a - b将答案存进数组s中。如果a和b不同号，则用加法算。
void mnu(ll a[], ll b[]) {
  // 如果a和b不同号
  if (sn1 ^ sn2) {
    // 如果a为负，a - b = -(-a + b)
    if (sn1) sn1 ^= 1, pls(a, b), sn = 1;
    // 如果b为负，a - b = a + (-b)
    if (sn2) sn2 ^= 1, pls(a, b);
    return;
  }

  // 如果a和b都是负的，a - b = -b - (-a)
  if (sn1 & sn2) {
    sn1 = sn2 = 0, mnu(b, a);
    sn1 = sn2 = 1;
    return;
  }

  // 如果a和b都是正的，并且a < b，则化为算b - a，符号为负
  if (cmp(a, b) == -1) swap(a, b), sn = 1;
  // 到此a > b且都为正
  clear(s);
  s[0] = max(a[0], b[0]);
  for (int i = 1; i <= s[0]; i++) {
    s[i] += a[i] - b[i];
    if (s[i] < 0) s[i] += MOD, s[i + 1]--;
  }
  // 去掉开头0
  while (!s[s[0]] && s[0] > 1) s[0]--;
  if (sn == 1) swap(a, b);
}

// 求a * b将答案存进数组s中。
void mul(ll a[], ll b[]) {
  if (sn1 ^ sn2) sn = 1;
  clear(s);
  s[0] = a[0] + b[0];
  for (int i = 1; i <= a[0]; i++)
    for (int j = 1; j <= b[0]; j++) {
      s[i + j - 1] += a[i] * b[j];
      if (s[i + j - 1] >= MOD)
        s[i + j] += s[i + j - 1] / MOD, s[i + j - 1] %= MOD;
    }

  if (!s[s[0]] && s[0] > 1) s[0]--;
}

void div(ll a[], ll b[]) {
  if (sn1 ^ sn2) sn = 1;
  clear(cp), cp[1] = 1;
  clear(lt);
  // 如果a >= b，则将除数倍增到不小于被除数，确定商二进制最高位
  while (~cmp(a, b)) lm(b), lm(cp);
  while (cp[0] > 1 || cp[1]) {
    if (~cmp(a, b)) {
      // a -= b
      mnu(a, b), cpy(a, s);
      // lt += cp
      pls(lt, cp), cpy(lt, s);
    }
    // b >>= 1, cp >>= 1
    rm(b), rm(cp);
  }
  // 此时，lt是商，a是余数
}

int main() {
  scanf("%s%s", s1, s2);
  if (s1[0] == '-') s1[0] = '0', sn1 = 1;
  if (s2[0] == '-') s2[0] = '0', sn2 = 1;
  init(s1, a);
  init(s2, b);
  clear(s);
  pls(a, b);
  write(s);
  mnu(a, b);
  write(s);
  mul(a, b);
  write(s);
  div(a, b);
  write(lt);
  write(a);
}