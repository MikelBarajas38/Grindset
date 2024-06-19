#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, k;

    cin >> n >> k;
    k--;

    int map[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
        
    }
    

    int count = 0;
    for (int i = 0; i < n - k; i++)
    {
        for (int j = 0; j < n - k; j++)
        {
            if (map[i][j] == map[i][j+k]
            and map[i+k][j] == map[i+k][j+k]
            and map[i][j+k] == map[i+k][j+k])
            {
                count ++;
            }
        }
        
    }
    
    cout << count << '\n';

    return 0;
}