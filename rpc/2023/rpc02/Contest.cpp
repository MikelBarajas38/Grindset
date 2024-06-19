// AC

#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(0);

    double n,k,d,s;
    cin >> n >> k >> d >> s;

    double total_diff = n*d;
    double solved_diff = k*s;

    double rem_diff = (total_diff - solved_diff) / (n-k);
    
    if(rem_diff > 100 || rem_diff < 0){
        cout << "impossible\n";
    } else {
         cout << fixed << setprecision(7) << rem_diff << '\n';
    }

    return 0;
}
