#include <iostream>
using namespace std;

int match (char* P, char* T, int* buildNext (char* P)) {
    int* next = buildNext(P);
    int n = (int)strlen(T), i = 0;
    int m = (int)strlen(P), j = 0;

    while (j < m && i < n) {
        if (j < 0 || T[i] == P[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }

    delete [] next;
    cout << i - j;
}

int* buildNext (char* P) {
    int m = (int)strlen(P), j = 0;
    int* N = new int[m];
    int t = N[0] = -1;

    while (j < m - 1) {
        if (t < 0 || P[j] == P[t]) {
            j++;
            t++;
            N[j] = t;
        } else {
            t = N[t];
        }
    }

    return N;
}

int main() {
    char T[] = "ababcabccabccacaab";
    char P[] = "abccac";
    match(P, T, buildNext);

    return 0;
}

//Users/qianqian/Desktop/alg/cmake-build-debug/kmp
//9
//Process finished with exit code 0