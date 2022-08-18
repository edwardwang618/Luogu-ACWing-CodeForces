#include <iostream>
using namespace std;

int main() {
    int n, hour;
    double salary;
    cin >> n >> hour >> salary;
    printf("NUMBER = %d\n", n);
    printf("SALARY = U$ %.2lf\n", hour * salary);

    return 0;
}