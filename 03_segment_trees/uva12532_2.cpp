#include <iostream>
#include <vector>

using namespace std;

vector<long long> tree;

void update(int index, int v, int n) {
    if(v == 0) {
        tree[n+index] = v;
    }
    else if(v > 0) {
        tree[n+index] = 1;
    }
    else {
       tree[n+index] = -1;
    }


    for(int i = (n+index)/2; i >= 1; i/=2) {
        tree[i] = tree[2*i] * tree[2*i+1];
    }
}

long long product(int node /*root*/, int node_low /*0*/, int node_high /*2*n-1*/, int query_low, int query_high) {
    if(query_low <= node_low &&  node_high <= query_high) {
        return tree[node];    
    }

    if(node_high < query_low || query_high < node_low ) {
        return 1;
    }
    
    int middle = node_low + (node_high - node_low)/2;
    long long left = product(node*2, node_low, middle, query_low, query_high);
    long long right = product(node*2+1, middle+1, node_high, query_low, query_high);

    return left * right;

}

int main() {
    string result;
    int n, k;

    while(cin >> n >> k) {

    
        vector<int> a(n);
        int e;
        for(int i = 0; i < n; i++) {
            
            cin >> e;
            if(e == 0) {
                a[i]=0;
            }
            else if(e > 0) {
                a[i]=1;
            }
            else {
                a[i]=-1;
            }
            
           //cin >> a[i];
        }

        // pad a[] with 0s to make size a power of 2
        while(__builtin_popcount(n) != 1) { //__builtin_popcount(n) != 1, check if n is a power of 2
            a.push_back(1);
            n++;
        }

        // Build tree
        tree.resize(2*n);
        for(int i = 0; i < n; i++) {
            tree[n+i] = a[i];
        }
        for(int j = n-1; j >= 1; j--) {
            long long prod = tree[j*2] * tree[j*2+1];
            tree[j] = prod;
        }
        /*
        cout << "[SEG TREE]" << endl;
        for(int k = 1; k < 2*n; k++) {
            cout << "Index: " << k << " Value: " << tree[k] << endl;
        }
        cout << endl;
        */
        


        for(int j = 0; j < k; j++) {

            char c;
            int  a, b;

            // Change
            cin >> c >> a >> b;
            if(c=='C') {
                a--; // adjust to 0 index
                update(a, b, n);
                /*
                cout << "Updated Seg. Tree" << endl;
                for(int k = 1; k < 2*n; k++) {
                    cout << "Index: " << k << " Value: " << tree[k] << endl;
                }
                cout << endl;
                */
            }

            //Product
            else if (c=='P') {
                a--;
                b--;
                long long prod;
                prod = product(1, 0, (n-1), a, b);
                //cout << "Product: " << prod << endl;

                if(prod == 0) {
                    result += '0';
                }
                else if(prod == 1) {
                    result +=  '+';
                }
                else {
                    result +=  '-';
                }
            }
        }
        cout << result << endl;
        result.clear();

    }
}