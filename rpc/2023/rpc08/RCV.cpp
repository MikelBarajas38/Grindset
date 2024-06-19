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

    ll n;
    cin >> n;

    map<string,ll> votes;
    for(ll i=0; i<n; ++i) {
        string name;
        cin >> name;
        votes[name]++;
    }

    vector<pair<ll,string>> order;
    for(const pair<string,ll> &v : votes){
        order.push_back({v.second, v.first});
    }

    sort(all(order));

    set<string> eliminated;
    ll votes_left = 0;

    for(ll i = 0; i<order.size(); ++i){
        ll current_min = order[i].first;
        double current_percent = (current_min + votes_left) * 100ll / n;
        
        if(current_percent >= 51.0) {
            break;
        }

        int elim_count = 0;
        while(i<order.size() && order[i].first == current_min){
            eliminated.insert(order[i].second);
            i++;
            elim_count++;
        }

        votes_left += (current_min * elim_count);

    }

    cout << eliminated.size() << '\n';
    for(const string &s : eliminated) {
        cout << s << '\n';
    }

    return 0;
}