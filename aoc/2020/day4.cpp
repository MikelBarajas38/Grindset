#include <bits/stdc++.h>
#include <sstream>
using namespace std;

bool checkSize(map <string,string> &pass){
    if(pass.size()==8)
        return true;
    else if(pass.size()==7 && pass.find("cid") == end(pass))
        return true;   
    
    return false;
}

bool checkYear(string yearStr, int minY, int maxY){
    int year = stoi(yearStr);

    if(year>=minY && year<=maxY)
        return true;
    
    return false;
}

bool checkHeight(string height){
    string unit = height.substr(height.length()-2);
    if(unit=="in" || unit=="cm"){
        int val = stoi(height.substr(0,height.length()-2));
        if(unit=="in"){
            if(val>=59 && val<=76) return true;
        }
        else{
            if(val>=150 && val<=193) return true;
        }
    }
    return false;
}

bool checkHairColor(string hairColor){
    if(hairColor[0]=='#' && hairColor.length()==7){

        int validChar=0;
        for(char &c:hairColor){

            if((c>='a' && c<='f') || (c>='0'&& c<='9')) 
                validChar++;

        }

        if (validChar==6) return true;
    }
    return false;
}

bool checkEyeColor(string eyecolor){
    unordered_set<string> validColors={"amb","blu","brn","gry","grn","hzl","oth"};

    if(validColors.find(eyecolor) != end(validColors))
        return true;
    
    return false;
}

bool checkPassportID(string ID){
    if(ID.length()==9){

        int validDigits=0;
        for(char &c:ID){

            if(c>='0' && c<='9') 
                validDigits++;
                
        }
        if (validDigits==9) return true;

    }
    return false;
}

int validatePassport(map <string,string> &passport){

    if(!checkSize(passport))
        return 0;
    
    if(!checkYear(passport["byr"],1920,2002))
        return 0;
    
    if(!checkYear(passport["iyr"],2010,2020))
        return 0;
    
    if(!checkYear(passport["eyr"],2020,2030))
        return 0;
    
    if(!checkHeight(passport["hgt"]))
        return 0;

    if(!checkHairColor(passport["hcl"]))
        return 0;
    
    if(!checkEyeColor(passport["ecl"]))
        return 0;
    
    if(!checkPassportID(passport["pid"]))
        return 0;

    return 1;
}
 
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    map<string,string> passport;
    string line;
    int validPassports=0;

    freopen("data.in","r",stdin);
    
    while(getline(cin,line)){

        if(line==""){
            cout<<"checking...\n\n";
            validPassports+=validatePassport(passport);
            passport.clear();
        }
        else{
            stringstream ss(line);
            string data;

            while(ss>>data){
                string key=data.substr(0,3);
                string val=data.substr(4);
                passport.insert({key,val});
                cout<<data<<"\n";
            }
        }
    }
    cout<<validPassports;
}