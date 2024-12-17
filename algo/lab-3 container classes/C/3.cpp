#include<iostream>
#include<fstream>
#include <iterator>
#include <set>
using namespace std;

int main(){
    ifstream in; in.open("input.txt");
    ofstream out; out.open("output.txt");
    
    // ms - должен содержать количество жажды каждого ученика
    multiset<int> ms;
    
    //auto it = ms.begin();
    int n; // n - count of paczans
    int m; // m - count of glotkow
    in >> n >> m;
    
    // input -> ms
    int temp=0;
    for(int i=0; i < n; i++){
        in >> temp;
        ms.insert(temp);
    }
    temp=0;

    // console output

    // cout<<"Before reverse iter algorythm"<<"\n";
    // for (auto it = ms.begin(); it != ms.end(); ++it){
    //     cout<<*it<<" ";
    // }
    // cout<<endl;

    for(m; m!=0; m--){
        multiset <int> :: reverse_iterator ri = ms.rbegin();
		ms.insert((*ri) / 10);
		ms.erase(--ms.end());
	}

    // console output

    // cout<<"After reverse iter algorythm"<<"\n";
    // for (auto it = ms.begin(); it != ms.end(); ++it){
    //     cout<<*it<<" ";
    // }
    // cout<<endl;

    for (auto it = ms.begin(); it != ms.end(); ++it){
        temp+=(*it);
    }
    
    //cout << temp;
    out<<temp;

    in.close();
    out.close();
}
//maybe end?