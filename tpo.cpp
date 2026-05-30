#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    if (cin >> s) {
        int u = 0, p[26] = {0};
        for (char x : s) {
            if (!p[x - 'a']) {
                p[x - 'a'] = 1;
                u++;
            }
        }
        
        int n = s.size(), l = 0, ml = n, c = 0, f[26] = {0};
        for (int r = 0; r < n; r++) {
            if (f[s[r] - 'a']++ == 0) c++;
            while (c == u) {
                ml = min(ml, r - l + 1);
                if (--f[s[l++] - 'a'] == 0) c--;
            }
        }
        cout << ml << "\n";
    }
    return 0;
}