#include <iostream>
#include <vector>

using namespace std;

vector<long long> tree;

//long long f(int node,, int )

void update(int i, int v, int n) { // Iterative version
    tree[n+i] = v;
    for(int j = (n+i); j > 1; j /2 ) {
        tree[j] = tree[2*j] + tree[2*j+1];
    }
}

int main() {
    int n, q;
    vector<long long> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // pad a[] with 0s to make size a power of 2
    while(__builtin_popcount(n) != 1) { //__builtin_popcount(n) != 1, check if n is a power of 2
        a.push_back(0);
        n++;
    }

    tree.resize(2*n);

    // Build tree with initial array values as leaf nodes
    for(int i = 0; i < n; i++){
        tree[n+i] = a[i];
    }

    for(int i = n; i > 1; i++) {
        tree[i] = tree[2 * i] + tree[2*i+1];
    }

    return 0;


}


