#include <iostream>
#include <vector>

using namespace std;


// Global BIT Tree
vector<int> bit;

void update(int idx, int val) {

    //cout << "Updating" << endl;
    while (idx < bit.size()) { 
        bit[idx] += val;       
        //cout << "curr idx:" << idx << ", Value: " << bit[idx] << endl;  
        idx += (idx & -idx);       
    }
    //cout << endl;
}

void query(int idx) {
    
    long long sum = 0; // range sum up until index
    while (idx > 0) { 
        sum += bit[idx];
        //cout << "curr idx:" << idx << ", Cur Sum: " << bit[idx] << endl; 
        idx -= (idx & -idx);
            
    }
    
    cout << sum << endl;
}



int main() {
    
    int t, n, u, q, idx, l, r, val;;

    // test cases
    cin >> t;

    while(t--) {
        
        // bit tree values and updates
        cin >> n >> u;

        // Tree resize
        bit.resize(n+1);
        /*
        cout << "Fenwick Tree: " << endl;
        for(int i = 1; i < n+1; i++) {
            cout << "i:" << i << ", Value: " << bit[i] << endl;  
        }
        cout << endl;
        */

        while(u--) {
            cin >> l >> r >> val;
            //cout << "l: " << l << " r: " << r << " val: " << val << endl;
            l++;
            r++;
            
            update(l, val);
            update(r+1, -val);
        
            /*
            cout << "Updated Fenwick Tree: " << endl;
            for(int i = 1; i < n+1 ; i++) {
                cout << "i:" << i << ", Value: " << bit[i] << endl;  
                 
            }
            cout << endl;
            */   
        }
        

        // queries
        cin >> q;
        while(q--) {
            cin >> idx;
            idx++;
            query(idx);
        }
        bit.clear();
    }


}