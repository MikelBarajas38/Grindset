#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool is_ordered(int *start, int *end) {
    for(int *p = start; p < (end - 1); p++){
        if(*p > *(p+1)) {
            return false;
        }
    }
    return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, k;
    cin >> n >> k;

    int bubbles[n];
    for(int i = 0; i < n; ++i) {
        cin >> bubbles[i];
    }

    int hours = 0;

    while(!is_ordered(bubbles, bubbles + n)) {
        for(int i = 0; i < n - k + 1; ++i) {
            sort(bubbles + i, bubbles + k + i);
        }
        hours++;
    }

    cout << hours << '\n';

    return 0;
}