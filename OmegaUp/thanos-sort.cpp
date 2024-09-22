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

    vector<int> arr(n);
    for(int &x : arr) {
        cin >> x;
    }

    int ordered_size = 1, valid_size = 1;
    for(int i = n - 2; i >= 0; i--) {

        if(arr[i] > arr[i + 1]) {
            break;
        }

        ordered_size++;
        if(ordered_size == 2 * valid_size) {
            valid_size = ordered_size;
        }

    }

    cout << valid_size << '\n';

    return 0;
}