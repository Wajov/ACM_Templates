#include <bits/stdc++.h>
using namespace std;
const int N = 1001, M = 10001;
int n, m, s, u, v, c, t, tmp, tot, d[N], Head[N], Next[M << 1], Link[M << 1], Cost[M << 1];
bool flag[N];
inline void AddEdge(int u, int v, int c) {
    Next[++tot] = Head[u];
    Link[tot] = v;
    Cost[tot] = c;
    Head[u] = tot;
}
int main() {
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &c);
        AddEdge(u, v, c);
        AddEdge(v, u, c);
    }
    for (int i = 1; i <= n; i++)
        d[i] = INT_MAX;
    d[s] = 0;
    for (int i = 1; i <= n; i++) {
        tmp = INT_MAX;
        for (int j = 1; j <= n; j++)
            if (!flag[j] && d[j] < tmp) {
                tmp = d[j];
                t = j;
            }
        flag[t] = true;
        for (int j = Head[t]; j; j = Next[j])
            d[Link[j]] = min(d[Link[j]], d[t] + Cost[j]);
    }
    for (int i = 1; i < n; i++)
        printf("%d ", d[i] == INT_MAX ? -1 : d[i]);
    printf("%d\n", d[n] == INT_MAX ? -1 : d[n]);
    return 0;
}
