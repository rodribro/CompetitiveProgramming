#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    long long e;
    map<long long, int> ev_map;

    cin >> n;
    for(int i = 0; i < n; i++) {

        cin >> e;

        if((ev_map.find(e) == ev_map.end())) {
            ev_map[e] = i+1;
            if(i==0) {
                cout << -1;
            }
            else {
                cout << " " << -1;
            }
        }
        else {
            cout << " " << ev_map[e];
            ev_map[e] = i+1;
            
        }
    }
    cout << endl;

}