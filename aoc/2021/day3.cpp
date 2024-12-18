#include <bits/stdc++.h>
#include <cmath>
using namespace std;

//----------Helper Functions--------------
int boolVecToDec(vector<bool> &bin){
    int dec=0;

    for(int i=0;i<bin.size();i++)
        if(bin[i])
            dec+=pow(2,bin.size()-1-i);

    return dec;
}

int boolStrToDec(string &bin){
    int dec=0;

    for(int i=0;i<bin.length();i++)
        if(bin[i]=='1')
            dec+=pow(2,bin.length()-1-i);

    return dec;
}

//------------------Puzzle-------------------
int partOne(vector<string> &report, int binSize){
    vector<int> Tru(binSize,0);
    vector<int> Fal(binSize,0);
    vector<bool> gammaRate; //most common bit in each position
    vector<bool> epsilonRate; //least common bit in each position

    for(auto bin: report) //check every bit in each position
        for(int i=0;i<binSize;i++){
            if(bin[i]=='1')
                Tru[i]++;
            else
                Fal[i]++;
        }
    
    for(int i=0;i<binSize;i++){ //check which bits are the most common in each position and store in a vector
        if(Tru[i]>Fal[i]){
            gammaRate.push_back(1);
            epsilonRate.push_back(0);
        }
        else{
            gammaRate.push_back(0);
            epsilonRate.push_back(1);
        }
    }

    //return the power consumption of the submarine
    return boolVecToDec(gammaRate)*boolVecToDec(epsilonRate);
}

int getRating(vector<string> &report, int binSize, bool caseVal){
    int Tru;
    int Fal;
    bool mostCommon;
    vector<bool> criteria(report.size(),1);

    for(int i=0;i<binSize;i++){ //check every position
        Tru = 0;
        Fal = 0;

        //check every bit in position-i to find most common
        for(int j=0;j<report.size();j++){ 
            if(criteria[j]){ //discard numbers
                if(report[j][i]=='1')
                    Tru++;
                else
                    Fal++;
            }
        }

        if(Tru < Fal)
            mostCommon = 0;
        else
            mostCommon = 1;
            
        char mostComChar;    

        //check case (1 = oxygen generator rating, 0 = CO2 scrubber rating)
        if(caseVal)
            mostComChar = mostCommon ? '1' : '0';
        else
            mostComChar = !mostCommon ? '1' : '0';

        for(int j=0;j<report.size();j++){
            if(report[j][i] != mostComChar)
                criteria[j] = 0;
        }

        //count the numbers that satisfy the criteria
        int binLeft = count(begin(criteria),end(criteria),1);
        if(binLeft == 1)
            break;
    }     
    
    //return rating
    for(int j=0;j<report.size();j++){
        if(criteria[j])
            return boolStrToDec(report[j]);
    }
}

int partTwo(vector<string> &report, int binSize){
    return getRating(report, binSize, 1) * getRating(report, binSize, 0);
}
 
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    string bin;
    vector<string> report;

    freopen("data.in","r",stdin);
    while(cin>>bin)
        report.push_back(bin);

    int binSize = report[0].length();

    cout<<partOne(report, binSize) << "\n";
    cout<<partTwo(report, binSize);

    return 0;
}