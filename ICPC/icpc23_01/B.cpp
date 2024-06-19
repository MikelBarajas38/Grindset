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

    int n, k, l;

    cin >> n >> k >> l;

    int r = (n*k) / l;

    if ((n*k) % l) r++;

    cout << r << '\n';    

    return 0;
}