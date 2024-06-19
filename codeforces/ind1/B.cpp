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

    int T;
    cin >> T;

    while(T--){

        int n;
        cin >> n;

        string bin;
        cin >> bin;

        int palin_dist = 0;
        for(int i=0; i<n/2; ++i){
            if(bin[i] != bin[n - i - 1]){
                palin_dist++;
            }
        }

        string ans = "";
        for(int i=0; i<=n; ++i){
            if(i >= palin_dist){
                int extra = i - palin_dist;
                int already_done = n - (palin_dist*2);

                if(already_done >= extra && (already_done - extra)%2 == 0){
                    ans += "1";
                } else if(already_done >= extra && n%2){
                    ans += "1";
                }else {
                    ans += "0";
                }
                
            } else {
                ans += "0";
            }
        }

        cout << ans << "\n";

    }

    return 0;
}