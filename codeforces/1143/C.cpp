#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {

    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    vector<char> does_not_respect(n);

    for(int i = 0; i < n; ++i) {
        int p;

        cin >> p >> does_not_respect[i];

        if(p != -1) {
            adj[p - 1].push_back(i);
        }
    }


    for(int i = 0; i < n; ++i) {
        if(does_not_respect[i]) {

        }
    }

    return 0;
}