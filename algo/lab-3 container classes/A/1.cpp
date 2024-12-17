#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

void swap(vector <int> &v, int i, int j) {
  int buf = v[i];
  v[i] = v[j];
  v[j] = buf;
}

void Sort(vector <int> &v, int n) {
  int i, j;
  bool obmen;
  for (i = 0; i < n; i++) {
    obmen = false;
      for (j = 0; j < n - i - 1; j++) {
        if (v[j] > v[j + 1]) {
          swap(v, j, j+1);
          obmen = true;
          }
      }
      if (!obmen) break;
  }
}

int main(){
    ifstream in; in.open("input.txt");
    ofstream out; out.open("output.txt");
    vector<int> v;
    int x;
    while(!in.eof()){
        in >> x;
        if(x==0){break;}
        v.push_back(x);
    }
    //for(int i=0; i < v.size(); i++){cout<<v[i]<<" ";}cout<<endl;

    Sort(v,v.size());

    //for(int i=0; i < v.size(); i++){cout<<v[i]<<" ";}cout<<endl;

    for(int i=0; i < v.size(); i++){
        out<<v[i]<<" ";
    }

    in.close();
    out.close();
}