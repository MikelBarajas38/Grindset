#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int bin_to_dec (string bin) {
    int dec = 0;
    for (int i = 0; i < bin.size(); i++) {
        dec = dec * 2 + (bin[i] - '0');
    }
    return dec;
}

string dec_to_bin (int dec) {
    string bin = "";
    while(dec) {
        bin += (dec % 2) + '0';
        dec /= 2;
    }
    reverse(all(bin));
    return bin;
}

void div2(string &bin) {
    bin.pop_back();
    if(bin.empty()) bin.push_back('0');
}

void sum(string &a, string &b) {

    int na = a.size();
    int nb = b.size();

    if(nb > nb) {
        swap(a, b);
        swap(na, nb);
    }

    int carry = 0;
    int ia = na - 1;
    int ib = nb - 1;

    while(ia >= 0 || ib >= 0) {
        int sum = (a[ia] - '0') + carry;
        if(ib >= 0) {
            sum += (b[ib] - '0');
            ib--;
        } 
        a[ia] = (sum % 2) + '0';
        carry = sum / 2;
        ia--;
    }

    if(carry) {
        a = '1' + a;
    }

}

string unpad(string &a) {
    int i = 0;
    while(a[i] == '0') {
        i++;
    }
    return a.substr(i);
}

void solve() {
    
    string s, d, m, one = "1", zero = "0";
    cin >> s >> d >> m;

    set<string> balances;
    string day = zero, period = one;

    while(m > zero) {

        if(balances.count(m)) {
            cout << "Infinite money!\n";
            return;
        }

        balances.insert(m);
                
        div2(m);

        if(period == d) {
            sum(m, s);
            period = one;
        } else {
            sum(period, one);
        }

        sum(day, one);

    }

    cout << day << '\n';

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T = 1;
    //cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}