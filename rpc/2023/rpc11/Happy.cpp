#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct customer {
    int id;
    int arrival;
    int service;
    int patience;
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    list<customer> line;
    for(int i=0; i<n; ++i) {
        customer test;
        cin >> test.id >> test.arrival >> test.service >> test.patience;
        line.push_back(test);
    }

    auto it = line.begin();
    it = next(it, 1);

    while(it != line.end()) {
        auto p = prev(it);
        int prev_finish = (*p).arrival + (*p).service;
        int max_wait = (*it).arrival + (*it).patience;

        if(prev_finish > max_wait) {
            auto temp = it;
            it = next(it,1);
            line.erase(temp);
        } else {
            if((*it).arrival < prev_finish) {
                (*it).arrival = prev_finish;
            }
            it = next(it,1);
        }
    }

    for(auto &c : line) {
        cout << c.id << "\n";
    }

    return 0;
}