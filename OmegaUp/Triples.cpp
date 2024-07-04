#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    int n;
    cin >> n;

    set<int> triples;
    for(int i=0; i<n; ++i){
        long long x;
        cin >> x;

        if(x%3==0){
            triples.insert(i+1);
        }
    }

    if(triples.size()){
        cout << triples.size() << '\n';
        for(int i : triples){
            cout << i << ' ';
        }
    } else {
        cout << "No hay triples.";
    }
    return 0;
}