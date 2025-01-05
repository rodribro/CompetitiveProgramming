#include <iostream>

using namespace std;

int main() {

    int t;
    cin >> t;

    string v;

    vector<int> missiles;
    while(t) {
        while(getline(cin, v) && v!="") {
            
            //cout <<"v: " << v << endl;
            cout << stoi(v) << endl;
            missiles.push_back(stoi(v)); //cast string to int
                
        }
        

        
    }


    return 0;
}