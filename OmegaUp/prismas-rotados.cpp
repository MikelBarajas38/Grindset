
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

    vector<int> dim1, dim2;
    
    for(int i=0; i<3; ++i){
        int d1;
        cin >> d1;
        dim1.push_back(d1);
    }

    for(int i=0; i<3; ++i){
        int d2;
        cin >> d2;
        dim2.push_back(d2);
    }

    if(is_permutation(begin(dim1), end(dim1), begin(dim2))){
        cout << 1;
    } else {
        cout << 0;
    }

    return 0;
}