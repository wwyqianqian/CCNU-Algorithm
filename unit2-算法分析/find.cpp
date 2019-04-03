// P16第四题：
// 设数组 a[n]中的元素均不相等，设计算法找出 a[n]中一个既不是最大也不是最小的 元素，并说明最坏情况下的比较次数。要求分别给出伪代码和 C++描述。

#include <iostream>
using namespace std;

int main() {
//  int a[] = {1, 3, 2, 4, 5, 0};
//  int a[] = {1, 1, 1, 2};
    int a[] = {5, 3, 2, 0, 4};

    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n);

    int mid_value = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i+1] > a[i] && a[i+1] < a[i+2]) {
            mid_value = a[i+1];
            cout << mid_value << endl;
            break;
        } else {
            cout << "NULL" << endl;
        }
    }
    return 0;
}


