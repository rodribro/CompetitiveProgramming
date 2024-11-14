#include <iostream>
#include <vector>

using namespace std;

vector<long long> tree;

void update(int index, int v, int n) {
    tree[n+index] = v;
    for(int i = (n+index)/2; i >= 1; i/=2) {
        tree[i] = tree[2*i] * tree[2*i+1];
    }
}

long long product(int node /*root*/, int node_low /*0*/, int node_high /*2*n-1*/, int query_low, int query_high) {
    if(query_low <= node_low &&  node_high <= query_high) {
        return tree[node];    
    }

    if(node_high < query_low || query_high < node_low ) {
        return 0;
    }
    
    int middle = node_low + (node_high - node_low)/2;
    return product(node*2, node_low, middle, query_low, query_high) 
        * product(node*2+1, middle+1, node_high, query_low, query_high);

}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // pad a[] with 0s to make size a power of 2
    while(__builtin_popcount(n) != 1) { //__builtin_popcount(n) != 1, check if n is a power of 2
        a.push_back(0);
        n++;
    }

    // Buil tree
    tree.resize(2*n);
    for(int i = 0; i < n; i++) {
        tree[n+i] = a[i];
    }
    for(int j = n-1; j >= 1; j--) {
        long long prod = tree[j*2] * tree[j*2+1];
        tree[j] = prod;
    }

    cout << "Seg. Tree" << endl;
    for(int k = 1; k < 2*n; k++) {
        cout << "Index: " << k << " Value: " << tree[k] << endl;
    }
    cout << endl;

    for(int j = 0; j < k; j++) {

        char c;
        int  a, b;

        // Change
        cin >> c >> a >> b;
        if(c=='C') {
            a--; // adjust to 0 index
            update(a, b, n);

            cout << "Updated Seg. Tree" << endl;
            for(int k = 1; k < 2*n; k++) {
                cout << "Index: " << k << " Value: " << tree[k] << endl;
            }
            cout << endl;

        }

        //Product
        else if (c=='P') {
            a--;
            b--;
            long long prod;
            prod = product(1, 0, (2*n-1), a, b);

            if(prod == 0) {
                cout << "Prod:" << 0 << endl;
            }
            else if(prod > 0) {
                cout << "Prod:" << '+' << endl;
            }
            else {
                cout << "Prod:" << '-' << endl;
            }
        }
    }
    
}