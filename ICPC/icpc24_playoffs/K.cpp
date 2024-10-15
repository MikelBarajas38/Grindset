#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define readv(v) for(auto &i : v) cin >> i
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int N, M, O;
    cin >> N >> M >> O;

    vi vN(N);
    readv(vN);
    
    vector<vector<pii>> d(M, vector<pii>());

    for (int j = 0; j < M; j++)
    {
        int m;
        cin >> m;

        d[j].resize(m);
        readv(d[j]).first >> i.second;
    }

    int possible = 0;
    //bool isPossible = true;

    for (int j = 0; j < O; j++)
    {
        int o;
        cin >> o;

        for (int k = 0; k < o; k++)
        {
            int x;
            cin >> x;

            x--;

            for (auto &p : d[x]) {
                // p.first-1 type
                // p.second amount
                vN[p.first-1] -= p.second;
                if (vN[p.first-1] < 0) {
                    goto exit;
                }
            }
        }
        possible ++;
    }
    
exit:
    cout << possible << '\n';
    
    
    return 0;
}
