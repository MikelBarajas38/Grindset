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

    string journals;
    cin >> journals;

    vector<char> errors;

    int moves = 0;
    int lim = journals.size();
    for(int i=1; i < lim; ++i) {

        //cout << journals[i-1] << ' ' << journals[i] << '\n';

        if(journals[i-1] == journals[i]){
            errors.push_back(journals[i]);
        }

        if(errors.size() >= 2) {
            int end = errors.size()-1;
            if(errors[end] != errors[end-1]){
                moves++;
                errors.pop_back();
                errors.pop_back();
            }
        }

    } 

    if(errors.size() > 0){
        moves+=errors.size();
    }

    cout << moves << '\n';

    return 0;
}