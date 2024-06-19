#include<bits/stdc++.h>

using namespace std;

int main() {

    string S;
    int k;

    cin >> S >> k;

    vector<priority_queue<char, vector<char>, greater<char>>> substr(k);

    for(int i = 0; i<S.length(); i++ ) {
        substr[i%k].push(S[i]);
    }

    string ans = "";
    for(int i = 0; i<S.length(); i++ ) {
        ans += substr[i%k].top();
        substr[i%k].pop();
    }

    cout << ans << '\n';

    return 0;
}