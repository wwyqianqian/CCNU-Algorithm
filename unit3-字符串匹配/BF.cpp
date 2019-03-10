#include <iostream>
using namespace std;

int BF(char S[], char T[]) {
    int i = 0; int j = 0;
    while (S[i] != '\0' && T[j] != '\0') {
        if (S[i] == T[j]) {
            i++; j++;
        } else {
            i -= j - 1;
            j = 0;
        }
    }
    if (T[j] == '\0') {
        return i - j + 1; // 返回匹配成功的位置（不是下标，区分于 0）
    } else {
        return 0;
    }
}

int main() {
    char S[] = "aaaabvcfagfg";
    char T[] = "bvc";
    cout << BF(S, T);
    return 0;
}