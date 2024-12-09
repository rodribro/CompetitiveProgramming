#include <iostream>
#include <vector>

using namespace std;

// Helpful video: https://www.youtube.com/watch?v=gaAdpq1IyCI

void update(vector<long long> &bit, long long idx, long long v) {
    while(idx < bit.size()) { // <= ou < ?
        bit[idx] += v;
        idx += (idx & -idx);
    }
}

void range_update(vector<long long> &bit1, vector<long long> &bit2, long long p, long long q, long long v) {

    // BIT1
    update(bit1, p, v);
    update(bit1, q+1, -v);

    //BIT2
    update(bit2, p, v*(p-1));
    update(bit2, q+1, -v*q);
}

long long sum(vector<long long> &bit, long long idx) {
    long long sum = 0;
    while(idx >0) {
        sum += bit[idx];
        idx -= (idx&-idx);
    }
    return sum;
}

long long prefix_sum(vector<long long> &bit1, vector<long long> &bit2, long long idx) {
    return sum(bit1, idx)*idx - sum(bit2, idx);
}

long long range_query(vector<long long> &bit1, vector<long long> &bit2, long long p, long long q) {
    return prefix_sum(bit1, bit2, q) - prefix_sum(bit1, bit2, p-1);
}
int main() {
    long long t, n, c, flag, p, q, v;
    cin >> t;
    while(t--) {
    
        cin >> n >> c;

        // 2 BIT (piece wise linear function)
        vector<long long> bit1(n+2,0); //declive
        vector<long long> bit2(n+2,0); //constante

        while(c--) {

            // (0 or 1) flag, p , q
            cin >> flag >> p >> q;

            if(flag == 0) {
                cin >> v;
                range_update(bit1, bit2,p, q, v);

            }
            else {
                cout << range_query(bit1, bit2, p, q) << endl;
            }


        }
    }
    return 0;
}