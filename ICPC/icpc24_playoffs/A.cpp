#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool comp(const pair<string, string> &a, const pair<string, string> &b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int N;
    cin >> N;

    vector<pair<string, string>> dict;
    for(int i = 0; i < N; ++i) {
        
        pair<string, string> sp;

        string s;
        cin >> s;

        sp.second = s;
        sort(all(s));

        sp.first = s;

        dict.push_back(sp);

    }

    sort(all(dict), comp);

    int q;
    cin >> q;

    while(q--) {

        pair<string, string> sp;

        string s;
        cin >> s;

        sp.second = s;
        sort(all(s));

        sp.first = s;

        auto it = upper_bound(all(dict), sp, comp);

        cout << it - dict.begin() << '\n';

    }

    
    return 0;
}
