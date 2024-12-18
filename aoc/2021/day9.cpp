#include <bits/stdc++.h>
using namespace std;

//check if index is in bounds
bool isValidIndex(int i, int j, int n, int m){
    return (j<m && j>=0 && i<n && i>=0);
}

//check if element in i,j is a low point
bool isLow(vector<vector<int>> &heightmap, int i, int j, int n, int m){
    bool isLow = true;
    if(isValidIndex(i,j+1,n,m)) isLow = isLow && heightmap[i][j] < heightmap[i][j+1];
    if(isValidIndex(i,j-1,n,m)) isLow = isLow && heightmap[i][j] < heightmap[i][j-1];
    if(isValidIndex(i+1,j,n,m)) isLow = isLow && heightmap[i][j] < heightmap[i+1][j];
    if(isValidIndex(i-1,j,n,m)) isLow = isLow && heightmap[i][j] < heightmap[i-1][j];
    return isLow;
}

//------------------part 1-------------------
int partOne(vector<vector<int>> &heightmap){
    int riskLevel = 0, n=heightmap.size(), m=heightmap[0].size();
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(isLow(heightmap,i,j,n,m))
                riskLevel += heightmap[i][j]+1;
        }
    }
    return riskLevel;
}

//------------------part 2-------------------
//dsf that returns size of basin
int searchBasin(vector<vector<int>> &heightmap, vector<vector<bool>> &visited, int i, int j, int n, int m){
    int size = 1;

    if(heightmap[i][j] == 9 || visited[i][j])
        return 0;

    if(isValidIndex(i,j+1,n,m))
        if(heightmap[i][j] < heightmap[i][j+1]){
            size += searchBasin(heightmap,visited,i,j+1,n,m);
        } 

    if(isValidIndex(i,j-1,n,m))
        if(heightmap[i][j] < heightmap[i][j-1]){
            size += searchBasin(heightmap,visited,i,j-1,n,m); 
        } 

    if(isValidIndex(i+1,j,n,m))
        if(heightmap[i][j] < heightmap[i+1][j]){
            size += searchBasin(heightmap,visited,i+1,j,n,m);
        } 

    if(isValidIndex(i-1,j,n,m))
        if(heightmap[i][j] < heightmap[i-1][j]){
            size += searchBasin(heightmap,visited,i-1,j,n,m);
        }

    visited[i][j] = 1;
    return size;
}

int partTwo(vector<vector<int>> &heightmap){
    int n=heightmap.size(), m=heightmap[0].size();
    vector<vector<bool>> visited (n,vector<bool>(m,0)); 
    vector<int> maxBasins;

    int basinSize = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(isLow(heightmap,i,j,n,m)){  
                for(vector<bool> &v : visited) fill(begin(v),end(v),0);
                basinSize = searchBasin(heightmap,visited,i,j,n,m);
                maxBasins.push_back(basinSize);
            }
        }
    }

    sort(begin(maxBasins),end(maxBasins),greater<int>());
    return maxBasins[0]*maxBasins[1]*maxBasins[2];
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    vector<vector<int>> heightmap;

    freopen("data.in","r",stdin);

    string line;
    vector<int> lineV;
    while(getline(cin,line)){
        for(char c : line){
            lineV.push_back(c-48);
        }
        heightmap.push_back(lineV);
        lineV.clear();
    }

    cout<<partOne(heightmap)<<"\n"<<partTwo(heightmap);
    return 0;
}