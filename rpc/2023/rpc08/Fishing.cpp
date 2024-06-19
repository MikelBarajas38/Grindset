#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct point {
    int x;
    int y;
};

int check_net(int x, int y, int s, vector<point> fishes){
    int count = 0;
    for(point &fish : fishes){
        if((fish.x >= x and fish.x <= x+s) && 
           (fish.y >= y and fish.y <= y+s)) {
                count++;
           }
    }
    return count;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int s, n;
    cin >> s >> n;

    vector<vi> pond(100, vi(100));

    vector<point> fishes;
    for(int i=0; i<n; ++i) {
        point f;
        cin >> f.x >> f.y;
        fishes.push_back(f);
    }

    int max_catch = 0;
    for(int net_x=0; net_x <= 100; net_x++){
        for(int net_y=0; net_y <= 100; net_y++){
            max_catch = max(max_catch, check_net(net_x, net_y, s, fishes));
        }
    }
    
    cout << max_catch << '\n';

    return 0;
}