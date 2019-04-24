#include <iostream>
#include <string>
using namespace std;
#define MAXLEN 100

char _x[MAXLEN] = "0";
char _y[MAXLEN] = "0";
char X[MAXLEN] = "0";
char Y[MAXLEN] = "0";

void initArrs(char* X, char* Y, int M, int N, int(&L)[MAXLEN][MAXLEN], int(&S)[MAXLEN][MAXLEN]) {
    for (int i = 0; i <= M; i++) {
        L[i][0] = 0;
        S[i][0] = 0;
    }
    for (int j = 0; j <= N; j++) {
        L[0][j] = 0;
        S[0][j] = 0;
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (X[i] == Y[j]) {
                L[i][j] = L[i-1][j-1] + 1;
                S[i][j] = 1;
            }
            if (X[i] != Y[j] && L[i][j-1] >= L[i-1][j]) {
                L[i][j] = L[i][j-1];
                S[i][j] = 2;
            }
            if (X[i] != Y[j] && L[i][j-1] <  L[i-1][j]) {
                L[i][j] = L[i-1][j];
                S[i][j] = 3;
            }
        }
    }    
}

void printArrs(int M, int N, int arr[MAXLEN][MAXLEN]) {
    for (int i = -1; i <= M; i++) {
        for (int j = -1; j <= N; j++) {
            if (i == -1 && j == -1)
                printf("  ");
            if (i >= 0 && j == -1)
                printf("%c ", X[i]);
            if (i == -1 && j >= 0)
                printf("%c ", Y[j]);
            if (i >= 0 && j >= 0)
                printf("%d ", arr[i][j]);
        }
        printf("\n");
    }    
}

int main(int argc, char *argv[]) {
    scanf("%s", _x);
    scanf("%s", _y);
    sprintf(X, "_%s", _x);
    sprintf(Y, "_%s", _y);
    int M = strlen(_x);
    int N = strlen(_y);

    int L[MAXLEN][MAXLEN] = {0};
    int S[MAXLEN][MAXLEN] = {0};

    initArrs(X, Y, M, N, L, S);
    
    printf("========= L =========\n");
    printArrs(M, N, L);

    printf("========= S =========\n");
    printArrs(M, N, S);


    return 0;
}


// ~/Desktop  g++ -o lcs lcs.cpp           287ms  Wed Apr 24 21:48:13 2019
// ~/Desktop  ./lcs                         312ms  Wed Apr 24 21:48:59 2019
// xzyzzyx zxyyzxz
// ========= L =========
//   _ z x y y z x z
// _ 0 0 0 0 0 0 0 0
// x 0 0 1 1 1 1 1 1
// z 0 1 1 1 1 2 2 2
// y 0 1 1 2 2 2 2 2
// z 0 1 1 2 2 3 3 3
// z 0 1 1 2 2 3 3 4
// y 0 1 1 2 3 3 3 4
// x 0 1 2 2 3 3 4 4
// ========= S =========
//   _ z x y y z x z
// _ 0 0 0 0 0 0 0 0
// x 0 2 1 2 2 2 1 2
// z 0 1 2 2 2 1 2 1
// y 0 3 2 1 1 2 2 2
// z 0 1 2 3 2 1 2 1
// z 0 1 2 3 2 1 2 1
// y 0 3 2 1 1 2 2 3
// x 0 3 1 2 3 2 1 2