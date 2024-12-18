#include <bits/stdc++.h>
using namespace std;

unsigned long long int getFish(vector<int> &initialFish, int days){
    //map<int,unsigned long long int> lanternHash;
    unsigned long long int lanternHash[9];

    //initialize no. lanternfish based on their internal timer
    for(int i=0; i<=8; ++i) lanternHash[i] = 0; //0-8 (0)
    for(int &i : initialFish) ++lanternHash[i]; //initial State (day 0)
    
    //simulation
    bool newBorn = false;
    unsigned long long int newFish;
    for(int i=0; i<days; ++i){

        for(int j=0; j<=8; ++j){
            if(lanternHash[j]){
                if(j == 0){
                    newBorn = true;
                    newFish = lanternHash[0];
                    lanternHash[0] = lanternHash[1];
                }
                else{
                    lanternHash[j-1] = lanternHash[j];
                    lanternHash[j] = 0;
                }
            }
        }

        if(newBorn){
            lanternHash[8] += newFish;
            lanternHash[6] += newFish;
            newBorn = false;
        }

    }

    //sum all lanternfish
    unsigned long long int nFish = 0;
    for(int i=0; i<=8; ++i) nFish += lanternHash[i];
    return nFish;
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    vector<int> initialState;

    freopen("data.in","r",stdin);

    string num;
    while(getline(cin,num,',')){
        initialState.push_back(stoi(num));
    }

    cout<<getFish(initialState, 80) << "\n" << getFish(initialState, 256);
    
    return 0;
}