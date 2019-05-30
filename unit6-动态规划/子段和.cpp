#include <iostream>
using namespace std;

int maxSum(int a[], int n, int &begin, int &end) {
    int sum = 0;
    int tem = 0;
    for (int i = 0; i < n; i++) {
        if (tem > 0) {
            tem += a[i];
        } else {
            tem = a[i];
            begin = i;
        }
        if (tem > sum) {
            sum = tem;
            end = i;
        }
    }

    return sum;
}

int main(int argc, char const *argv[]) {

    int a[] = {-2, 2, 3, -4, 5};
    int n = 5;
    int begin = 0, end = 0;

    int res = maxSum(a, n, begin, end);
    cout << res << endl;
    cout << "begin subscript: " << begin << " && end subscript: " << end << endl;
    return 0;
}

// ~/Desktop  ./a.out   356ms  Thu May 30 11:10:31 2019
// int a[] = {2, 2, -3, 4, -5};
// 5
// begin subscript: 0 && end subscript: 3

// int a[] = {-2, -2, -3, -4, -5};
// 0