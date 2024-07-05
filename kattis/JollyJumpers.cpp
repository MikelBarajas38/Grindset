#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	//cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);

    vector<char> done;
    vector<int> elements;
        
    int n;
    while(cin >> n) {

        if(n == 0) {
            cout << "Not jolly\n";
            continue;
        } 

        if(n == 1) {
            int x; cin >> x;
            cout << "Jolly\n";
            continue;
        }

        done.assign(n-1, false);
        elements.resize(n);

        for(int &x : elements) {
            cin >> x;
        } 

        bool valid = true;
        for(int i = 1; i < n; i++) {
            int diff = abs(elements[i] - elements[i-1]);
            if(diff < 1 || diff > n-1) {
                valid = false;
                break;
            }
            done[diff-1] = true; 
        }

        bool jolly = valid && all_of(all(done), [](bool x) { return x; });

        cout << (jolly ? "Jolly" : "Not jolly") << '\n';

    }

    return 0;
}