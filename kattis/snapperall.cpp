
#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int n, k;
    cin >> n >> k;

    // bits before (position of less significative 0) -1
    // have power (the less significative 0 is the bulb)

    // find the lsz with (~x & (x+1))
    int lsz = ~k & (k+1);
    
    bool bulb_state = lsz>>n;

    cout << "Case #" << t << ": " << (bulb_state ? "ON\n" : "OFF\n");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
        solve(i);    

    return 0;
}