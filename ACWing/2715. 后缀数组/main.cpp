#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e6 + 10;
// m是离散化的最大值
int n, m;
char s[N];
// sa[i]排名第i位的是第几个后缀
// rk[i]第i个后缀排名是多少，在排序的过程中，rk是每个后缀用第一关键字的排名来离散化之后的值
// he[i]是sa[i]与sa[i - 1]的最长公共前缀的长度
// y是按第二关键字排的情况下每个后缀的排名
int sa[N], rk[N], y[N], c[N], he[N];

void get_sa() {
  // 将所有后缀按第一个字母排序，排序结果存入sa
  // 先将每个后缀离散化为其第一个字母的ASCII码值
  for (int i = 1; i <= n; i++) c[rk[i] = s[i]]++;
  for (int i = 2; i <= m; i++) c[i] += c[i - 1];
  for (int i = n; i; i--) sa[c[rk[i]]--] = i;

  // 每一轮按长2k的前缀来对所有后缀排序
  for (int k = 1; k < n; k <<= 1) {
    // 先按第二关键字排序
    int num = 0;
    // 长度不够k的那些后缀第二关键字为空，最小，先排它们
    for (int i = n - k + 1; i <= n; i++) y[++num] = i;
    // 按以长k前缀的字典序从小到大遍历所有后缀，只看第k + 1个及其以后的后缀，只有它们可以作为第二关键字
    for (int i = 1; i <= n; i++)
      if (sa[i] > k)
        // 第sa[i]个后缀是第sa[i] - k个后缀的第二关键字
        y[++num] = sa[i] - k;
    // 到此，y存的是所有后缀按第二关键字排好序的结果，即y[i]是排名第i的后缀是第几个后缀
    // 接下来要将所有后缀按第一关键字排序
    for (int i = 1; i <= m; i++) c[i] = 0;
    for (int i = 1; i <= n; i++) c[rk[i]]++;
    for (int i = 2; i <= m; i++) c[i] += c[i - 1];
    // rk[y[i]]是排名第i的后缀的第一关键字离散化之后的值
    for (int i = n; i; i--) sa[c[rk[y[i]]]--] = y[i];
    // 到此sa已经是两个关键字都排好序的结果
    // 接下来y没用了，将rk覆盖掉y，并且重新做离散化，此时是将每个后缀按照长2k的前缀来离散化
    swap(rk, y);
    rk[sa[1]] = num = 1;
    for (int i = 2; i <= n; i++)
      rk[sa[i]] = y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k] ? num : ++num;
    // 如果离散化后两两不同，说明本轮排好序后，已经没有排名一样的后缀了，说明已经整体排好序，直接退出
    if (num == n) break;
    // 更新离散化的最大值
    m = num;
  }
}

void get_height() {
  // 按排名枚举后缀
  for (int i = 1, k = 0; i <= n; i++) {
  	// 如果排名第1，那高度为0，略过
    if (rk[i] == 1) continue;
    // 找到排名少1位的后缀是第几个
    int j = sa[rk[i] - 1];
	  if (k) k--;
	  // 直接暴力枚举
    while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
    he[rk[i]] = k;
  }
}

int main() {
  scanf("%s", s + 1);
  
  n = strlen(s + 1), m = 'z';
  get_sa();
  get_height();

  for (int i = 1; i <= n; i++) printf("%d ", sa[i]);
  puts("");
  for (int i = 1; i <= n; i++) printf("%d ", he[i]);
  puts("");

  return 0;
}