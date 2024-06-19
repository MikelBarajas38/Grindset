#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T;
    cin >> T;

    while(T--){
        vector<pair<int,int>> moves;
        int n;
        cin >> n;
    
        vector<pair<int, int>> elements(n);
        for(int i=0; i<n; ++i){
            cin >> elements[i].first;
            elements[i].second = i;
        }

        sort(all(elements));

        vector<int> permutation(n);
        int actual = n;
        for(int i=0; i<n; ++i){
            permutation[elements[i].second] = actual;
            actual--;
        }

        for(int &i: permutation){
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}