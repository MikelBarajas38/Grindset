#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n,x,acum=0,acumN=0;
  cin >>n;
 
	for(int i=1;i<n;++i){
		cin>>x;
		acum+=i;
		acumN+=x;
	}
 
	acum+=n;
	cout<<acum-acumN;
 
}