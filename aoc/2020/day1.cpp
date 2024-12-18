#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int x;
    vector<int> expense;

    freopen("data.in","r",stdin);
    while(cin>>x){ //ctrl+d = end of file
        expense.push_back(x);
    }

    sort(begin(expense),end(expense));

    for(auto &i:expense)
        cout<<i<<" ";

    int l=0,r=expense.size()-1;

    for(auto &i:expense){
        while(l<r && expense[l]!=i && expense[r]!=i){
            if(i+expense[l]+expense[r]==2020){
                cout<<"\n\n"<<expense[l]<<" "<<expense[r]<<" "<<i;
                return 0;
            }
            else if(i+expense[l]+expense[r]>2020)
                --r;
            else if(i+expense[l]+expense[r]<2020)
                ++l;
        }
    }

   /*
    for(int i=0;i<expense.size();++i)
        for(int j=i+1;j<expense.size();++j)
            for(int k=j+1;k<expense.size();++k)
                if(expense[i]+expense[j]+expense[k]==2020)
                    cout<<expense[i]*expense[j]*expense[k];

    */

    //cout<<"\n"<<expense[l]<<" "<<expense[r];
    return 0;
}