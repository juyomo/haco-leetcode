#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string new_id) {
    
    // step 1
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);    
    
    // step 2
    string tmp="";
    string allowed="abcdefghijklmnopqrstuvwxyz0123456789-_.";
    for (int i = 0; i<new_id.length(); i++){
        bool check=0;
        for (int j = 0; j<allowed.length(); j++){
            if (new_id[i]==allowed[j]){
                check=1;
                break;
            }
        }
        if (check) tmp+=new_id[i];
    }
    new_id=tmp;
    
    // cout << "step 2 :" << new_id << '\n';
    
    // step 3
    tmp=new_id[0];
    for (int i = 1; i<new_id.length(); i++){
        if (new_id[i]=='.' && new_id[i-1]=='.') continue;
        tmp+=new_id[i];
    }
    new_id=tmp;
    
    // cout << "step 3 :" << new_id << '\n';

    
    // step 4
    if (new_id[0]=='.')
        new_id=new_id.substr(1,new_id.length()-1);
    if (new_id[new_id.length()-1]=='.') 
        new_id=new_id.substr(0,new_id.length()-1);
    
    // cout << "step 4 :" << new_id << '\n';

    // step 5
    if (new_id=="") new_id="a";
    
    // step 6
    if (new_id.length()>=15) {
        new_id=new_id.substr(0,15);
        if (new_id[14]=='.') new_id=new_id.substr(0,14);
    }

    // step 7
    if (new_id.length()<=2){
        while (new_id.length()<3) new_id+=new_id[new_id.length()-1];
    }
    
    return new_id;
}
