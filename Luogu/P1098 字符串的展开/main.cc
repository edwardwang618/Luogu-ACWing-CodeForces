#include <iostream>
#include <cctype>
using namespace std;

// 遇到'-'，需要输出什么
void extend(int p1, int p2, int p3, char begin, char end) {
	// 此时不用输出
    if (end == begin + 1) return;
	
	// begin代表要输出的开始字母，end表示结束字母。
    begin++, end--;
    bool xiaoxie, xinghao, nixu;
    xiaoxie = p1 == 1;
    xinghao = p1 == 3;
    nixu = p3 == 2;

    if (xinghao) {
    	// 输出星号
        for (int i = 0; i < (end - begin + 1) * p2; ++i) cout << "*";
    } else {
        if (!xiaoxie) 
        	// 如果要求大写，就转为大写
            begin = toupper(begin), end = toupper(end);
        if (!nixu) {
            while (begin <= end) {
                for (int i = 0; i < p2; ++i)
                    cout << begin;
                begin++;
            }
        } else {
            while (begin <= end) {
                for (int i = 0; i < p2; ++i)
                    cout << end;
                end--;
            }
        }
    }
}

int main() {
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    string in;
    cin >> in;

    for (int i = 0; i < in.length(); ++i) {
        if (in[i] != '-') {  // 不是'-'就直接原样输出
            cout << in[i];
        } else if (in[i] == '-' && (i == 0 || i == in.length() - 1)) {  // 是'-'但在开头或者结尾，就直接输出'-'
            cout << "-";
        } else {
            bool isxiaoxie = isalpha(in[i - 1]) && isalpha(in[i + 1])
                    && islower(in[i - 1]) && islower(in[i + 1]);
            bool isshuzi = isdigit(in[i - 1]) && isdigit(in[i + 1]);

            if ((isxiaoxie || isshuzi) && in[i - 1] < in[i + 1]) {  // 如果两边都是小写字母或都是数字，并且左边严格小于右边，才进入函数
                extend(p1, p2, p3, in[i - 1], in[i + 1]);
            } else {  // 否则原样输出'-'
                cout << "-";
            }
        }
    }

    return 0;
}