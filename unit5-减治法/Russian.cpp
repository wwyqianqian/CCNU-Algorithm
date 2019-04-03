#include <iostream>
#include <cmath>
using namespace std;

int multi (int n, int m) {
    int sum = 0;
    while (n > 1) {
        if (n % 2 == 1) {
            sum += m;
        }
        m = m * 2;
        n = n / 2;
        cout << n << " " << m << endl;
    }
    sum += m;
    cout << "----------" << endl;
    return sum;
}

int main() {
    int n, m;
    cout << "请输入两个数：";
    cin >> n;
    cin >> m;
    cout << multi(n, m) << endl;

    return 0;
}