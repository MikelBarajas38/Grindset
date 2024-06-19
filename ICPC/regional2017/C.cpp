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

    int k, n;
    cin >> k >> n;

    vector<int> freq(k);
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        freq[x-1]++;
    }

    int maxn = max_element(freq.begin(), freq.end()) - freq.begin();
    int minn = min_element(freq.begin(), freq.end()) - freq.begin();

    int test_min = *min_element(freq.begin(), freq.end());

    int test_freq_max = freq[maxn];
    int diff_max = 0, delta_max = 0;
    for(int i=0; i<k; ++i){
        if(freq[i] != test_freq_max) {
            delta_max = max(delta_max, test_freq_max - freq[i]);
            diff_max++;
        }
    }

    int test_freq_min = freq[minn];
    int diff_min = 0, delta_min = 0;
    for(int i=0; i<k; ++i){
        if(freq[i] != test_freq_min) {
            delta_min = max(delta_min, freq[i] - test_freq_min);
            diff_min++;
        }
    }

    if(delta_max > 2 || delta_min > 2) {
        cout << "*\n";
        return 0;
    }

    if(diff_min == k - 1 && diff_max == k - 1){
        cout << "-" << maxn + 1 << " +" << minn + 1 << "\n";
    } else if (diff_max == 1) {
        cout << "+" << minn + 1 << "\n";
    } else if (diff_min == 1) {
        cout << "-" << maxn + 1 << "\n";
    } else {
        cout << "*\n";
    }

    return 0;
}