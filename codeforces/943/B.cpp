    #include <bits/stdc++.h>
    using namespace std;
     
    #define rep(i, a, b) for(int i = a; i < (b); ++i)
    #define all(x) begin(x), end(x)
    #define sz(x) (int)(x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;
     
    void solve() {

        int n, m;
        cin >> n >> m;

        string a, b;
        cin >> a >> b;

        int size = 0;
        for(int i = 0; i < m; ++i){
            if(b[i] == a[size]) size++;
        }

        cout << size << "\n";

    }
     
    int main() {
    	cin.tie(0)->sync_with_stdio(0);
    	cin.exceptions(cin.failbit);
     
        vector<pair<int,int>> moves;
        int T;
        cin >> T;
     
        while(T--) {
            solve();
        }
     
        return 0;
    }