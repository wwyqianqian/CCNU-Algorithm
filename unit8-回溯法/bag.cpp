#include <iostream>
using namespace std;
#define MAX 10000
int N, W, bestV; // 物品个数 背包容量 最大价值
int val[MAX], weight[MAX], x[MAX], bestx[MAX]; // 物品价值数组 物品重量数组 物品的选中情况


void backtrack(int i, int currentVal, int currentWei) {
    if (i > N) {
        if(currentVal > bestV) {
            bestV = currentVal;
            for (i = 1; i <= N; i++) {
                bestx[i] = x[i];
            }
        }
    } else {
        for (int j = 0; j <= 1; j++) {
            x[i] = j;
            if (currentWei + x[i] * weight[i] <= W) {
                currentWei += weight[i] * x[i];
                currentVal += val[i] * x[i];
                backtrack(i + 1, currentVal, currentWei);
                currentWei -= weight[i] * x[i];
                currentVal -= val[i] * x[i];
            }
        }
    }
}

int main() {
    bestV = 0;

    cin >> N >> W;
    for (int i = 1; i <= N; i++) {
        cin >> weight[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> val[i];
    }

    backtrack(1, 0, 0);
    cout << bestV << endl;

    for (int i = 1; i <= N; i++) {
        cout << bestx[i] << " ";
    }
}


//  ~/Desktop  g++ /Users/qianqian/Desktop/bag.cpp
//  ~/Desktop  ./a.out                            352ms  Wed May 29 09:24:49 2019
// 6 20
// 2 4 2 3 5 10
// 15 12 6 8 11 8
// 52
// 1 1 1 1 1 0
