#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 || m == 0) {
            cout << 0 << "\n";
            continue;
        }
        
        vector<string> g(n);
        for (int i = 0; i < n; ++i) cin >> g[i];
        
        vector<vector<int>> col(n + 1, vector<int>(m, 0));
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                col[i + 1][j] = col[i][j] + (g[i][j] - '0');
            }
        }
        
        vector<vector<int>> p(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                p[i + 1][j + 1] = p[i][j + 1] + p[i + 1][j] - p[i][j] + (g[i][j] - '0');
            }
        }
        
        auto sum = [&](int r1, int r2, int c1, int c2) {
            if (r1 > r2 || c1 > c2) return 0;
            return p[r2 + 1][c2 + 1] - p[r1][c2 + 1] - p[r2 + 1][c1] + p[r1][c1];
        };
        
        int ans = 0;
        for (int r1 = 0; r1 < n; ++r1) {
            for (int r2 = r1 + 2; r2 < n; ++r2) {
                int mw = 1e9;
                for (int c = 0; c < m; ++c) {
                    if (g[r1][c] == '1' && g[r2][c] == '1') {
                        if (col[r2 + 1][c] - col[r1][c] == r2 - r1 + 1) {
                            if (mw != 1e9) {
                                ans = max(ans, sum(r1 + 1, r2 - 1, 0, c - 1) - mw);
                            }
                            mw = min(mw, sum(r1 + 1, r2 - 1, 0, c));
                        }
                    } else {
                        mw = 1e9;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}