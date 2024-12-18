#include <bits/stdc++.h>
using namespace std;

void printFloor(vector<vector<int>> &oceanFloor, int floorX, int floorY){
    for(int i=0;i<floorY;++i){
        for(int j=0; j<floorX; ++j)
            if(oceanFloor[i][j]>0)
                cout<<oceanFloor[i][j]; //y,x
            else
                cout<<".";
        cout<<"\n";    
    } 
}

int getOverlap(vector<vector<int>> &oceanFloor, int floorX, int floorY){
    int overlap = 0;
        for(int i=0;i<floorY;++i)
            for(int j=0; j<floorX; ++j)
                if(oceanFloor[j][i]>1)
                    ++overlap;
        
    return overlap;
}

void partOne(vector<pair<int,int>> &startPoints, vector<pair<int,int>> &endPoints, vector<vector<int>> &oceanFloor){
    
    int start, end, line, numLines = startPoints.size();
    
    for(int i=0; i<numLines; ++i){

        if(startPoints[i].first == endPoints[i].first){

            line = startPoints[i].first;
            start = min(startPoints[i].second, endPoints[i].second);
            end = max(startPoints[i].second, endPoints[i].second);

            for(int j=start; j<=end; ++j)
                ++oceanFloor[j][line];

        }
        else if(startPoints[i].second == endPoints[i].second){

            line = startPoints[i].second;
            start = min(startPoints[i].first, endPoints[i].first);
            end = max(startPoints[i].first, endPoints[i].first);

            for(int j=start; j<=end; ++j)
                ++oceanFloor[line][j];
        }
    }
}

void partTwo(vector<pair<int,int>> &startPoints, vector<pair<int,int>> &endPoints, vector<vector<int>> &oceanFloor){
    
    int distX, distY, x, y, 
    endX, endY, offsetX, offsetY, 
    numLines = startPoints.size();
    
    for(int i=0; i<numLines; ++i){

        distX = abs(startPoints[i].first - endPoints[i].first);
        distY = abs(startPoints[i].second - endPoints[i].second);
        
        if(distX == distY){
            x = startPoints[i].first;
            y = startPoints[i].second;
            endX = endPoints[i].first;
            endY = endPoints[i].second;

            if(x<endX) offsetX = 1;
            else offsetX = -1;

            if(y<endY) offsetY = 1;
            else offsetY = -1;
            
            for(int j=0;j<=distX;++j){
                ++oceanFloor[y][x];
                y+=offsetY;
                x+=offsetX;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    vector<pair<int,int>> startPoints;
    vector<pair<int,int>> endPoints;

    freopen("data.in","r",stdin);

    string line;
    int x1, y1, x2, y2, floorX=0, floorY=0;
    char extra;
    while(getline(cin,line)){
        stringstream ss(line);
        ss>>x1>>extra>>y1>>extra>>extra>>x2>>extra>>y2;
        startPoints.push_back({x1,y1});
        endPoints.push_back({x2,y2});

        floorX = max({floorX,x1,x2});
        floorY = max({floorY,y1,y2});
    }

    ++floorX; ++floorY;
    vector<vector<int>> oceanFloor(floorY,vector<int>(floorX));

    partOne(startPoints,endPoints,oceanFloor); 
    cout<<getOverlap(oceanFloor,floorX,floorY)<<"\n";
    //printFloor(oceanFloor,floorX,floorY);
    partTwo(startPoints,endPoints,oceanFloor);
    cout<<getOverlap(oceanFloor,floorX,floorY)<<"\n";     
    //printFloor(oceanFloor,floorX,floorY);
    return 0;
}