#include<iostream>
#include<fstream>
#include <list>
using namespace std;

int main(){
    ifstream in; in.open("input.txt");
    ofstream out; out.open("output.txt");
    list<int> n;
    int x;
    while(!in.eof()){
        in >> x;
        if(x==0){break;}
        n.push_back(x);
    }
    
    //here bug 
    //2 element of list not deleted, but this num equal -133
    for (auto it = n.begin(); it != n.end(); it++){
        if(*it < 0){
            n.erase(it);
            it = n.begin(); //i think bug here
        }     
    }
    for (auto it = n.begin(); it != n.end(); ++it){
        out<<*it<<" ";
    }
    in.close();
    out.close();
}
//maybe end?