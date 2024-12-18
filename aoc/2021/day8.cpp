#include <bits/stdc++.h>
using namespace std;

int partOne(string entry){
    stringstream ss(entry);
    vector<string> signalPatterns(10);
    vector<string> digitOutput(4);
    char separator;

    //parse input
    for(int i=0;i<10;++i) ss>>signalPatterns[i];
    ss>>separator;
    for(int i=0;i<4;++i) ss>>digitOutput[i];

    //get no. of times 1,4,7 and 8 appear in the output
    int validDigits = 0;
    unordered_set<int> nSegments = {2,3,4,7}; 
    for(string str: digitOutput){
        if(nSegments.find(str.length()) != end(nSegments))
            ++validDigits;
    }

    return validDigits;
}

int partTwo(string entry){
    stringstream ss(entry);
    vector<pair<string,bool>> signalPatterns(10);
    vector<string> digitOutput(4);
    vector<set<char>> digits(10);
    char separator;

    //parse input
    for(int i=0;i<10;++i) ss>>signalPatterns[i].first;
    ss>>separator;
    for(int i=0;i<4;++i) ss>>digitOutput[i];

    //get which segments form 1,4,7 and 8
    for(pair<string,bool> &signal: signalPatterns){
        switch(signal.first.length()){
            case 2:
                for(char &c : signal.first) digits[1].insert(c);
                signal.second=true; 
                break;
            case 4:
                for(char &c : signal.first) digits[4].insert(c);
                signal.second=true;  
                break;
            case 3:
                for(char &c : signal.first) digits[7].insert(c);
                signal.second=true;  
                break;
            case 7:
                for(char &c : signal.first) digits[8].insert(c);
                signal.second=true;  
                break;
        }
    }

    //use known segments and digits to find the rest (6 and 5 -segmented digits)
    set<char> test;
    int digitsLeft = 6;
    while(digitsLeft > 0){
        for(pair<string,bool> &signal: signalPatterns){

            if(!signal.second){
                for(char &c : signal.first) test.insert(c);
                
                if(signal.first.length() == 6){
                    if(includes(begin(test),end(test),begin(digits[4]),end(digits[4]))){ //9 includes all segments from 4
                        digits[9] = test;
                        signal.second=true;
                        --digitsLeft; 
                    }
                    else if(includes(begin(test),end(test),begin(digits[7]),end(digits[7]))){//0 includes all segments from 7
                        digits[0] = test;
                        signal.second=true;
                        --digitsLeft;
                    }
                    else{
                        digits[6] = test;//6 is the only 6-segment digit that doesnt include the past two
                        signal.second=true;
                        --digitsLeft; 
                    }
                }
                else{
                    if(includes(begin(test),end(test),begin(digits[1]),end(digits[1]))){//3 includes all segments from 1
                        digits[3] = test;
                        signal.second=true;
                        --digitsLeft; 
                    }
                    else if(!digits[6].empty()){//segments that form 6 are needed to differentiate 5 from 6
                        if(includes(begin(digits[6]),end(digits[6]),begin(test),end(test))){ //6 includes all segments from 5
                            digits[5] = test;
                            signal.second=true;
                            --digitsLeft; 
                        }
                        else{//6 does not include all segments from 2
                            digits[2] = test;
                            signal.second=true;
                            --digitsLeft; 
                        }   
                    }
                }
            }
            test.clear();
        }
    }

    int out = 0, E=1000; //get the 4-digit output number
    for(string output : digitOutput){
        for(char &c : output) test.insert(c);

        for(int i=0;i<10;++i){
            if(test == digits[i])
                out += i*E;
        }
        E/=10;
        test.clear();
    }

    return out;
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);

    freopen("data.in","r",stdin);
    string line;
    int firstVal = 0, secondVal = 0;
    while(getline(cin,line)){
        firstVal += partOne(line);
        secondVal += partTwo(line);
    }

    cout<<firstVal<<"\n"<<secondVal;
    
    return 0;
}