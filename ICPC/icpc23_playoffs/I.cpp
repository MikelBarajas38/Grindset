#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    
    vector<long long> pt(n + 1);
    bool inv = false;
    
    for(long long i=1; i<=n; i++) {
        long long c;
        cin >> c;
        
        if (c) {
            pt[i] = i - pt[i-1];
        } else {
            pt[i] = pt[i-1];
        }
        
    }

    long long total = 0;
    for(long long i=1; i<=n; i++) {
        total += pt[i];
    }
    
    cout << total << '\n';
    
}