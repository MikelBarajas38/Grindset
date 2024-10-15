#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int X = 160;
int Y = 260;
int knapsack(const vi &w, const vi &v) {
    vector<vi> M(v.size(), vi(Y+1, 0));
    for (int i = 1; i < w.size(); i++) {
        for (int j = 1; j <= Y; j++) {
            int value = 0;
            if (j - w[i] >= 0 and j - w[i] <= X) {
                value = v[i] + M[i-1][j-w[i]];
            }
            M[i][j] = max(value, M[i][j-1]);
            M[i][j] = max(M[i][j], M[i-1][j]);
        }
    }

    return M[w.size() - 1][Y];
}

int main() {

    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    vector<int> pages(n+1, 0);
    for (int i = 1; i < n+1; i++) {
        cin >> pages[i];
    }
    

    vector<int> pleasure(n+1, 0);
    for(int i = 1; i < n+1; i++) {
        cin >> pleasure[i];
    }

    vector<int> fame(n+1, 0);
    for(int i = 1; i < n+1; i++) {
        cin >> fame[i];
    }

    int bestPleasure = knapsack(pages, pleasure);
    int bestFame = knapsack(pages, fame);

    if (bestPleasure > bestFame) {
        cout << "PLEASURE\n";
    } else if (bestPleasure < bestFame) {
        cout << "FAME\n";
    } else {
        cout << "EITHER\n";
    }
    
    return 0;
}
