#include <bits/stdc++.h>
using namespace std;

int partOne(vector<int> crabsPos){
    sort(begin(crabsPos), end(crabsPos));

    //get the median and calculate total fuel spent
    int mid = crabsPos.size()/2, fuel=0;
    for(int &i:crabsPos)
        fuel += abs(i - crabsPos[mid]);

    return fuel;
}

int partTwo(vector<int> crabsPos){
    int mean, fuel=0;
    float sumVal = 0;
    
    //get the mean (-1, +1)
    for(int &i:crabsPos) sumVal+=i;
    mean = ceil(sumVal / crabsPos.size()) - 1;

    //calculate total fuel spent
    int triNum;
    for(int &i:crabsPos){
        triNum = abs(i - mean);
        fuel += triNum*(triNum+1)/2;
    }

    return fuel;
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    vector<int> crabsPos;

    freopen("data.in","r",stdin);

    string num;
    while(getline(cin,num,',')){ 
        crabsPos.push_back(stoi(num));
    }

    cout<<partOne(crabsPos)<<"\n"<<partTwo(crabsPos);

    return 0;
}