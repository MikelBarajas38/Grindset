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

    int n;
    cin >> n;

    vector<int> points(n);
    for(int &i : points) {
        cin >> i;
    }

    vector<string> increasing(n);
    increasing[0] = to_string(points[0]);
    for(int i = 1; i < n; i++) {
        if(points[i] >= points[i-1]){
            increasing[i] = increasing[i-1] + to_string(points[i]);
        } else {
            increasing[i] = to_string(points[i]);
        }
    }

    vector<string> decreasing(n);
    decreasing[n-1] = to_string(points[n-1]);
    for(int i = n-2; i >= 0; i--) {
        if(points[i] >= points[i+1]){
            decreasing[i] = decreasing[i+1] + to_string(points[i]);
        } else {
            decreasing[i] = to_string(points[i]);
        }
    }

    int max_len = -1;
    for(int i = 1; i < n-1; i++) {
        if(increasing[i] == substr(decreasing[i])){
            int len = increasing[i].length() * 2 - 1;
            max_len = max(max_len, len);
        }else if(increasing[i + 1] == decreasing[i]){
            int len = increasing[i].length() * 2;
            max_len = max(max_len, len);
        }
    }

    cout << max_len << '\n';

    return 0;
}