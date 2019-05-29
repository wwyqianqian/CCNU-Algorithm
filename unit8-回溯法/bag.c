#include <stdio.h>
#define n 6

int c = 20;
int w[] = {2, 4, 2, 3, 5, 10};
int v[] = {15, 12, 6, 8, 11, 8};
int cw;
int cv;
int bestv;
int X[n];

void getBest(int i) {
    if (i >= n) {
        if (cv > bestv) {
            bestv = cv;
        }
        return;
    }
    if (cw + w[i] <= c) {
        X[i] = 1;
        cw += w[i];
        cv += v[i];
        getBest(i + 1);
        cw -= w[i];
        cv -= v[i];
    }

    X[i] = 0;
    getBest(i + 1);
}

int main() {
    getBest(0);
    printf("%d",bestv);

    return 0;
}

//  ~/Desktop  gcc /Users/qianqian/Desktop/bag.c          Wed May 29 09:39:42 2019
//  ~/Desktop  ./a.out                                    Wed May 29 09:40:27 2019
// 52