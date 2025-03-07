#include<iostream>
#include<fstream>
#include <string>
#include <map>
using namespace std;

int main(){
    ifstream in; in.open("input.txt");
    ofstream out; out.open("output.txt");

    string name;
    long long n, count;
    in>>n;

    map<int, string> mp;
    map<int, string>::iterator it;
    
    for(int i=0; i < n; i++){
        in>>count>>name;
        mp[count] = name;
    }

    // cout<<"TEAMS"<<endl;
    // for(it = mp.begin(); it!=mp.end(); it++){
    //     cout<<(*it).first <<" "<< (*it).second<<endl;
    // }

    map<int, string>::iterator max = mp.end();
    max--;
    for(it = mp.begin(); it != mp.end(); it++){
        if((*it).first > (*max).first){
            max = it;
        }
    }

    // cout<<endl<<"winners"<<endl;
    // cout<<(*max).first<<" "<<(*max).second<<endl;

    out<<(*max).second<<endl;
    in.close();
    out.close();
}
//maybe end?