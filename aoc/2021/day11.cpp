#include <bits/stdc++.h>
using namespace std;

bool isValidIndex(int i, int j){
    return (j<10 && j>=0 && i<10 && i>=0);
}

void printOctopuses(vector<vector<int>> &octopuses){
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j)
            cout<<octopuses[i][j];
        cout<<"\n";
    }
    cout<<"\n";
}

int flashOct(vector<vector<int>> &octopuses, vector<vector<bool>> &flashed, int n, int m){
    int nFlashes = 1;
    octopuses[n][m] = 0;
    flashed[n][m] = true;

    for(int i=n-1;i<n+2;++i){
        for(int j=m-1;j<m+2;++j){
            if(isValidIndex(i,j)){
                if(!flashed[i][j]) ++octopuses[i][j];
                else octopuses[i][j]=0;
                
                if(octopuses[i][j]>9) nFlashes += flashOct(octopuses,flashed,i,j);
            }
        }
    }
    return nFlashes;
}

int partOne(vector<vector<int>> octopuses, int steps){
    int flashes = 0;
    vector<vector<bool>> flashed(10,vector<bool>(10));

    for(int k=0;k<steps;++k){
        for(vector<bool> &v : flashed) fill(begin(v),end(v),0);

        for(int i=0;i<10;++i)
            for(int j=0;j<10;++j)
                ++octopuses[i][j];    

        for(int i=0;i<10;++i){
            for(int j=0;j<10;++j){
                if(octopuses[i][j]>9 && !flashed[i][j])
                    flashes += flashOct(octopuses,flashed,i,j);
            }
        }

        printOctopuses(octopuses);
    }   

    return flashes;
}

int partTwo(vector<vector<int>> octopuses){
    int stepFlashes, k=0;
    vector<vector<bool>> flashed(10,vector<bool>(10));

    while(stepFlashes!=100){
        stepFlashes = 0;
        for(vector<bool> &v : flashed) fill(begin(v),end(v),0);

        for(int i=0;i<10;++i)
            for(int j=0;j<10;++j)
                ++octopuses[i][j];
            
        for(int i=0;i<10;++i){
            for(int j=0;j<10;++j){
                if(octopuses[i][j]>9 && !flashed[i][j])
                    stepFlashes += flashOct(octopuses,flashed,i,j);
            }
        }

        ++k;
    }   

    return k;
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    vector<vector<int>> octopuses;

    freopen("data.in","r",stdin);
    string line;
    vector<int> lineV;
    while(getline(cin,line)){
        for(char c : line){
            lineV.push_back(c-48);
        }
        octopuses.push_back(lineV);
        lineV.clear();
    }

    cout<<partOne(octopuses,100)<<"\n"<<partTwo(octopuses);
    return 0;
}