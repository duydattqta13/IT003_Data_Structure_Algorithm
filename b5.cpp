#include <bits/stdc++.h>

using namespace std;

int a[31];
long long f[10][31];
int m, n;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    f[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            if (a[i] > j) continue;
            for (int k = !(i == 1); k <= m; ++k){
                if (j - a[i] - k < 0) continue;
                f[i][j] += f[i-1][j - a[i] - k];
            }
        }
    long long res = 0;
    for (int i = 1; i <= m; ++i) res += f[n][i];
    cout << res;
    return 0;
}