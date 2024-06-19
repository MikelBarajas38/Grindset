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

    set<int> elements;
    int negatives = 0;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if(x < 0) {
            negatives++;
        }

        elements.insert(x);
    }

    if(negatives) return 0;

    for(const int &i : elements) {
        cout << i << '\n';
    }

    return 0;
}