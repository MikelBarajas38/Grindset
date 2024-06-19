#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
 
    ll N;
	cin>>N;
 
	cout<<N<<" ";
	while(N>1){
 
		if(N%2==0) {
            N/=2;
        } else{
			N=N*3+1;
        }
 
        cout<<N<<" ";
    }
 
    return 0;
}