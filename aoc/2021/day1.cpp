#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int prev, total=0, sum=0, x;
    vector<int> depths;
    
    freopen("data.in","r",stdin);
    //cin>>prev; Part 1
    while(cin>>x){ //ctrl+d = end of file
        /* Part 1
        if(x>prev)
            total++;
        
        prev=x;
        */

       //part 2
       depths.push_back(x);

        if(depths.size()==3){
            sum=depths[0]+depths[1]+depths[2];
        }
        else if(depths.size()>3){
            if(sum < sum-depths[prev]+x)
                total++;
            sum=sum-depths[prev]+x;
            prev++;
        }
    }

    cout<<total;
    return 0;
}