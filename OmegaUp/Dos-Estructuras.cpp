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
    cin.ignore();

    queue<int> q;
    stack<int> s;

    for(int i = 0; i < n; ++i) {

        string op;
        getline(cin, op);

        if(op[0] == 'm') {

            int x;
            cin >> x;
            cin.ignore();

            q.push(x);
            s.push(x);

        } else {

            cout << s.top() << ' ' << q.front() << '\n';
            q.pop();
            s.pop();

        }

    }

    return 0;
}