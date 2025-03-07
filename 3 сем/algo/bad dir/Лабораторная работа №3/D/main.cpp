#include <fstream>
#include <map>
#include <string>

using namespace std;

string input = "input.txt", output = "output.txt";

int main() {
    map <string, int> mp;
    long long l, max = 0;
    string k, s;
    
    ifstream in(input);
    size_t n;
    in >> n;
    for (size_t i = 0; i < n; i++) {
        in >> l;
        in >> k;
        mp[k] = mp[k] + l;
        if (mp[k] > max) {
        	max = mp[k];
        	s = k;
        }
    }


    ofstream out;        
    out.open(output); 
    out << s;

    in.close();
    out.close();
}