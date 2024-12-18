#include <bits/stdc++.h>
using namespace std;

int countTrees(vector<string> &grid,int r,int d){
    int totalTrees = 0;
    int col=0;
    int width=grid[0].length();

    for(int i=0;i<grid.size();i+=d){

        if(grid[i][col]=='#')
            ++totalTrees;
        
        col=(col+r)%width;
    }

    return totalTrees;
}
 
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    vector<string> grid;
    string row;

    freopen("data.in","r",stdin);
    while(cin>>row)
        grid.push_back(row);
    
    for(string &s:grid)
        cout<<s<<"\n";

    cout<<"\n";

    long long total;
    
    total = countTrees(grid,1,1);
    total *= countTrees(grid,3,1); 
    total *= countTrees(grid,5,1);
    total *= countTrees(grid,7,1);
    total *= countTrees(grid,1,2);

    cout<<total;
    return 0;
}