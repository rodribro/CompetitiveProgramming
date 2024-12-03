#include <iostream>
#include <vector>

using namespace std;

vector<long long> fen;

void update(int idx, int v) {
    while(idx < fen.size()) {
        fen[idx] += v;
        idx += (idx & -idx);
    }
}

long long sum(int idx) {
    long long sum = 0;
    while(idx >  0) {
        sum += fen[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void range_query(int p, int q) {

    cout << sum(q) - sum(p-1) << endl; // p-1 because we beed to include p in the range query

    
}
int main() {

    // test cases, n values, commands, flag, p, q, v
    int t, n, c, flag, p, q, v;

    cin >> t;
    while(t--) {
        cin >> n >> c;

        // resize fenwick tree to n+1 (index 0 is a dummy)
        fen.resize(n+1);

        while(c--) {
            cin >> flag;
            if(flag == 0) {
                cin >> p >> q >> v;
                update(p, v);
                update(q+1,-v);
            }
            else {
                cin >> p >> q;
                range_query(p,q);
            }
        }
        fen.clear(); //reset fenwick tree
    }
    
}