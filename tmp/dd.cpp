#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, l;
vector<int> a(110);
ll c[110][110];
ll ans = INT_MAX;


void dfs(int i, int pre_col, int groups, ll cost) {
    if (groups > l) return;
    if (i > n) {
        if (groups < l) return;
        // groups == l;
        ans = min(ans, cost);
        // cout << ans << ':';
        // for (int j = 1; j <= n; j++)
        //     cout << a[j];
        // cout << '\n';
        return;
    }

    // has color
    if (a[i] != 0) {
        // has color
        dfs(i+1, a[i], groups + (a[i] != pre_col ? 1 : 0), cost);
        return;
    }

    // no color
    for (int col = 1; col <= m; col++) {
        // a[i] = col;
        if (cost + c[i][col] > ans) return;
        dfs ( i+1, col, groups + (col != pre_col ? 1 : 0), cost + c[i][col]);
        // a[i] = 0;
    }

}

int main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        // memset(c, 0, sizeof(c));
        ans = INT_MAX;
        cin >> n >> m >> l;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> c[i][j];
            }
        }

        dfs(1, -1, 0, 0);

        if (ans == INT_MAX) ans = -1;
        cout << ans << '\n';

    }
}
