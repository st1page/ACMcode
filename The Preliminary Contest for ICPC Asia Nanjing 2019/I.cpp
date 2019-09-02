#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000010;

int n, y;
int a[MAXN];
int ans[MAXN];

int main() {
    while (scanf("%d%d", &n, &y) == 2) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        int now = n - 1;
        ans[y] = a[n-1] + y;
        for (int x = y - 1; x >= 1; x--) {
            for (; a[now-1] + x <= a[now] && now > 0; now--);
            ans[x] = a[n-1] + x;
            if (now > 0) ans[x] = max(ans[x], a[now-1]+y);
        }
        for (int i = 1; i <= y; i++) {
            printf("%d%c", ans[i], " \n"[i==y]);
        }
    }

}
