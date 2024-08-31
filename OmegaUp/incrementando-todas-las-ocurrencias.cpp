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

    vector<int> final_val(10);
    iota(all(final_val), 0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; i++) {

        int d;
        cin >> d;

        for(int j = 0; j < 10; j++) {
            if(final_val[j] == d) {
                final_val[j]++;
            }
        }

    }

    for(int &x : a) {
        cout << final_val[x] << " ";
    }
    
        
    return 0;

}