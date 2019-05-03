#include <stdio.h>
#include <string.h>

void GetNext(char T[], int next[]) {
    int i, j, len;
    next[0] = -1;
    for (j = 1; T[j] != '\0'; j++) {
        for (len = j - 1; len >= 1; len--) {
            for (i = 0; i < len; i++) {
                if (T[i] != T[j - len + i])
                    break;  // for (i = 0; i < len; i++)
            }
            if (i == len) {
                printf("%d %d\n", j, len);
                next[j] = len;
                break;  // for (len = j - 1; len >= 1; len--)
            }
        }
        if (len < 1) {
            printf("%d %d\n", j, len);
            next[j] = 0;
        }
    }
}

int KMP(char S[], char T[], int next[]) {
    int i = 0;
    int j = 0;
   
    while (S[i] != '\0' && T[j] != '\0') {
        if (S[i] == T[j]) {
            i++; j++;
        } else {
            j = next[j];
            if (j == -1) {
                i++; j++;
            }
        }
    }
    if (T[j] == '\0') {
        return (i - strlen(T) + 1);
    } else {
        return 0;
    }
}

int main() {
    char S[] = "afvvfababcabafdv";
    char T[] = "ababcab";
    int next[80];

    GetNext(T, next);
    for (int i = 0; i < strlen(T); i++) {
        printf("%d ", next[i]);
    }

    printf("\n----------------------\n");
    printf("%d\n", KMP(S, T, next));

    return 0;
}

//  ~/Desktop  gcc /stringmatch-kmp-next.c -o next
//  ~/Desktop  ./next        Fri May  3 23:35:44 2019
// 1 0
// 2 0
// 3 1
// 4 2
// 5 0
// 6 1
// -1 0 0 1 2 0 1
// ----------------------
// 6