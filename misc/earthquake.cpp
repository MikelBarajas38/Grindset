#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void generate_one_coffe_stain(string number, map<string,int> &possible_stained_numbers) {
    for(int i = 0; i < 9; ++i) {
        string stained = number;
        stained[i] = '?';
        //cout << stained << '\n';
        possible_stained_numbers[stained]++;
    }
}

void generate_two_coffee_stains(string number, map<string,int> &possible_stained_numbers) {
    for(int i = 0; i < 9; ++i) {
        for(int j = i + 1; j < 9; ++j) {
            string stained = number;
            stained[i] = '?';
            stained[j] = '?';
            //cout << stained << '\n';
            possible_stained_numbers[stained]++;
        }
    }
}

void generate_juice_stains(string number, map<string,int> &possible_stained_numbers) {
    for(int i = 0; i < 9; ++i) {
        for(int j = 1; j <= 9; ++j) {
            if(i + j > 9) continue;
            string stained = number.substr(0,i) + '*' + number.substr(j+i,9);
            //cout << stained << '\n';
            possible_stained_numbers[stained]++;
        }
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    map<string, int> possible_stained_numbers; 

    int N, Q;

    cin >> N;

    string number;
    for(int i = 0; i < N; ++i) {
        cin >> number;
        possible_stained_numbers[number]++;
        generate_one_coffe_stain(number, possible_stained_numbers);
        generate_two_coffee_stains(number, possible_stained_numbers);
        generate_juice_stains(number, possible_stained_numbers);
    }

    cin >> Q;

    string stained;
    for(int i=0; i < Q; ++i) {
        cin >> stained;
        cout << possible_stained_numbers[stained] << '\n';
    }

    return 0;
}