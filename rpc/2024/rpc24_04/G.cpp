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

    int n, a;
    cin >> n >> a;

    map<string, ll> employees;
    map<ll, set<string>> sorted_salaries;

    for(int i = 0; i < n; ++i){
        string n;
        ll s;
        cin >> n >> s;
        employees[n] = s;
        sorted_salaries[s].insert(n);
    }

    for(int i = 0; i < a; ++i){
        int q;
        cin >> q;

        if(q == 1) {

            string n;
            ll s;
            cin >> n >> s;

            auto employee = employees.find(n);

            ll current_salary = employee->second;

            auto it = sorted_salaries.find(current_salary);
            if(it->second.size() == 1) {
                sorted_salaries.erase(it);
            } else {
                it->second.erase(n);
            }

            ll ns = current_salary + s;
            employee->second = ns;

            sorted_salaries[ns].insert(n);

        } else if(q == 2) {
            
            auto max_sal = prev(sorted_salaries.end());
            ll max_sal_val = max_sal->first;
            auto employee_to_delete = max_sal->second.begin();

            cout << *employee_to_delete << " " << max_sal_val << "\n";

            employees.erase(*employee_to_delete);

            if(max_sal->second.size() == 1) {
                sorted_salaries.erase(max_sal);
            } else {
                max_sal->second.erase(employee_to_delete);
            }    

        }   

    }

    return 0;
}