#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int count_ones(int n) {

    int count = 0;

    while (n) {

        n &= (n - 1);
        count++;

    }

    return count;

}

int main() {

	//cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);

    vector<int> S(101);

    for (int i = 1; i <= 100; i++) {

        if(i % 2) {
            S[i] = S[i-1];
        } 

        cout << i << ": " << count_ones(i) << '\n';

        S[i] = S[i-1] + count_ones(i);

    }

    vector<int> TS(101);
    for(int i = 1; i <= 100; i++) {
        TS[i] = S[i / 2];
    }


    for(int i = 2; i <= 100; i+=2) {
        cout << i << ": " << TS[i] << '\n';
    }

    return 0;



    
}