#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solveHanoi(int size, int start, int end, int aux, vector<pair<int,int>>  &moves)
{
    if(size == 1){
        moves.push_back({start, end});
        return;
    }
 
    solveHanoi(size-1, start, aux, end, moves);
    moves.push_back({start, end});
    solveHanoi(size-1, aux, end, start, moves);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, k;
    cin >> n >> k;

    vector<int> participants(n);
    for(int &p : participants) {
        cin >> p;
    }

    k--;
    int count = 0;
    for(int &p : participants) {
        if(p >= participants[k] && p > 0) count++;
    }

    cout << count;

    return 0;
}