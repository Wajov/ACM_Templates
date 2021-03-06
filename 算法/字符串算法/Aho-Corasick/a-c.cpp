#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int n, t, now, pos, ans, son[N][26], num[N], p[N];
char a[N + 10], b[N + 10];
queue<int> q;
void Insert(char s[]) {
    int p = 1, t;
    for (int i = 0; s[i]; i++) {
        t = s[i] - 97;
        if (!son[p][t])
            son[p][t] = ++pos;
        p = son[p][t];
    }
    num[p]++;
}
int main() {
    pos = 1;
    scanf("%s%d", a, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", b);
        Insert(b);
    }
    for (int i = 0; i < 26; i++)
        son[0][i] = 1;
    q.push(1);
    while (!q.empty()) {
        now = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
            if (son[now][i]) {
                p[son[now][i]] = son[p[now]][i];
                q.push(son[now][i]);
            } else
                son[now][i] = son[p[now]][i];
    }
    t = 1;
    for (int i = 0; a[i]; i++) {
        t = son[t][a[i] - 97];
        for (int j = t; j > 1 && num[j] > -1; j = p[j]) {
            ans += num[j];
            num[j] = -1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
