#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map <char, int> value = {{'A', 3}, {'T', 2}, {'G', 1}, {'C', 0}};

bool comp(pair<char,int> a, pair<char,int> b){
    if(a.second == b.second) {
        return value[a.first] > value[b.first];
    }
    return a.second > b.second;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    string strand;
    cin >> strand;

    vector<int> A_count(sz(strand)+1, 0);
    vector<int> T_count(sz(strand)+1, 0);
    vector<int> G_count(sz(strand)+1, 0);
    vector<int> C_count(sz(strand)+1, 0);

    for(int i = 1; i < sz(strand) + 1; i++){
        A_count[i] = A_count[i-1] + (strand[i - 1] == 'A');
        T_count[i] = T_count[i-1] + (strand[i - 1] == 'T');
        G_count[i] = G_count[i-1] + (strand[i - 1] == 'G');
        C_count[i] = C_count[i-1] + (strand[i - 1] == 'C');
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        
        vector<pair<char,int>> counts = {{'A', A_count[r] - A_count[l-1]}, {'T', T_count[r] - T_count[l-1]}, {'C', C_count[r] - C_count[l-1]}, {'G', G_count[r] - G_count[l-1]}};
        sort(all(counts), comp);

        cout << counts[0].first << counts[1].first << counts[2].first << counts[3].first << "\n";

    }

    return 0;
}