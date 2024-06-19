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

    set<char> left;
    set<char> right;

    string possible_left = "qwertasdfgzxcvb";
    for(char c : possible_left) {
        left.insert(c);
    }

    string possible_right = "yuiophjklnm";
    for(char c : possible_right) {
        right.insert(c);
    }

    string word;
    cin >> word;

    bool is_dickensian = true; 
    for(int i = 0; i < word.length() - 1; ++i) {

        if(left.count(word[i]) != right.count(word[i+1])){
            is_dickensian = false;
            break;
        }

    }

    if(is_dickensian) {
        cout << "yes" << '\n';
    } else {
        cout << "no" << '\n';
    }

    return 0;
}