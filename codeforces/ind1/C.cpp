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

        int n;
        cin >> n;

        set<ll> s;
        ll smallest = 1000000001;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            s.insert(x);
            if(x < smallest){
                smallest = x;
            }
        }

        if(smallest != 0){
            cout << 0 << "\n";
            cout.flush();
        } else {
            while(s.find(smallest) != end(s)) smallest++;
            cout << smallest<< "\n";
            cout.flush();
        }

        
        ll y = 1;
        int turn = 1;
        while(turn < 2*n+1){

            cin >> y;

            if(y< 0){
                break;
            }

            cout << y << "\n";
            cout.flush();

            turn+=2;

        }


    }

    return 0;
}