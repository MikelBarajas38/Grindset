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

    int n;

    cin >> n;
    set<string> setn;
    set<string> setuq;

    for(int i=0; i<n; ++i) {
        int x;
        cin >> x;
        string NAME = "";

        for(int j=0; j<x; ++j) {
            string test;
            cin >> test;
            NAME += test[0];
        }

        if(setn.count(NAME) == 0) {
            setuq.insert(NAME);
        } else {
            setuq.erase(NAME);
        }
                
        setn.insert(NAME);
    }

    cout << setuq.size() << "\n";

    return 0;
}