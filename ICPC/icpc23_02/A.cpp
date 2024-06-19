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

    int n;
    string num;

    cin >> n >> num;

    int count = n;

    for (char d : num) {
        if (d == '6' or d == '8' or d == '0') count --;
    }

    cout << count << '\n';  

    return 0;
}