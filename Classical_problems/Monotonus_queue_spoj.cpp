#include<bits/stdc++.h>
using namespace std;

/***http://www.spoj.com/problems/PARSUMS/**/

int const MAXN = 1000002;

int a[MAXN * 2], n;
int sum[MAXN * 2];
int start_a, start_b;
int end_a, end_b;
int A[MAXN * 2], B[MAXN * 2];

void push(int v) {
    A[end_a++] = v;

    while (start_b != end_b && B[end_b - 1] > v) end_b--;

    B[end_b++] = v;
}

void pop() {
    if (start_a != end_a) {

        if (A[start_a] == B[start_b]) ++start_b;

        ++start_a;
    }
}

int get_min() {

    if (start_b == end_b) return -1;

    return B[start_b];
}

int main() {

    int i, j;

    while (scanf("%d", &n) && n != 0) {

        for (i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            a[i + n] = a[i];
        }
        sum[0] = 0;

        for (i = 1; i <= 2 * n; i++) sum[i] = sum[i - 1] + a[i];

        start_a = start_b = end_a = end_b = 0;

        for (i = 1; i <= n; i++) push(sum[i]);

        int res = 0; /// -1 2 1 0 -4 1

        for (i = n + 1; i <= 2 * n; i++) {

            cout<<get_min()<<" oka "<<sum[i-n-1]<<endl;

            if (get_min() - sum[i - n - 1] >= 0) ++res;

            pop();
            push(sum[i]);
        }

        printf("%d\n", res);
    }
     return 0;
}
