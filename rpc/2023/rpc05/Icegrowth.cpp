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

    int n, k;
    cin >> n >> k;

    vector<double> temp(n);
    for(double &t : temp){
        cin >> t;
    }

    vector<double> req(k);
    for(double &thickness : req){
        cin >> thickness;
    }

    double size = 0;
    vector<double> ice;
    for(int i = 0; i < n; ++i) {
        double curr_size = -temp[i] / 5.0; 
        size += curr_size;
        if(size < 0) {
            size = 0;
        }
        ice.push_back(size);
    }
    sort(all(ice));

    for(double thickness : req){

        int lesser = lower_bound(all(ice), thickness) - ice.begin();   

        cout << n - lesser << ' ';
    }

    return 0;
}