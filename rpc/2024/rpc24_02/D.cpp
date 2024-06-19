#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pair<int, int>>;



int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> x(m, vector<int>(26, 0));

    for (int i = 0; i < n; i++)
    {
        string c;
        cin >> c;

        for (int j = 0; j < m; j++)
        {
            x[j][c[j] - 'a']++;
        }    
    }

    string res = "";
    for (int j = 0; j < m; j++)
    {
        char best;
        int bc = 0;
        for (int i = 0; i < 26; i++)
        {
            if (x[j][i] > bc) {
                bc = x[j][i];
                best = i + 'a';
            }
        }
        res += best;
    }
    
    cout << res << '\n';

    return 0;
}