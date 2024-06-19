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

    string message;
    cin >> message;

    message.append(string(n*n - message.length(), '#'));
 
    int mid = n/2;
    int x = mid, y = mid;

    int c = 0;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    vector<vector<char>> map(n, vector<char>(n));

    for(int i = 1; i <= n; i += 2) {
        
        if(i==1) {
            map[y][x] = message[c];
            c++;
        } else {
            for(int k = 0; k < 4; ++k) {
                
                int j = 2;
                if(k!=0) {
                    y += dy[k];
                    x += dx[k];
                }

                for(; j<i; ++j) {
                        map[y][x] = message[c];
                        c++;
                        y += dy[k];
                        x += dx[k];
                }
                map[y][x] = message[c];
                c++;
            }
        }

        y--;

    }

    for(auto &string : map) {
        for(char &c : string) {
            if(c != '#') {
                cout << c;
            }
        }
    }
    cout << "\n";

    return 0;
}