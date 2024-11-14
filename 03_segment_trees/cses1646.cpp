#include <iostream>

// Mostly focused on understanding how to implement a segment tree Recursively

using namespace std;

vector<long long> tree;

// IMPLEMENT F()
long long f()
int main() {
    int n, q; // n -> array size, q -> queries
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }  

    // pad a[] with 0s to make size a power of 2
    while(__builtin_popcount(n) != 1) { //__builtin_popcount(n) != 1, check if n is a power of 2
        a.push_back(0);
        n++;
    }
    tree.resize(2 * n); // if array a is of size n, tree will have 2 * n - 1 nodes (segment tree is 1 indexed!)

    // BUILD TREE
    /*The tree will be build bottom-up
    *We'll start by creating the last layer as the last n values of the tree array
    * that correspond to the original array.
    *The following values will be created based on their child nodes.
    *Each node has as child nodes, the node with the indexes: 2*n (left node) and 2*n + 1 (right node)
    */
   // Fill tree with nodes from the array a
   for(int i = 0; i < n; i++) {
    tree[n+i] = a[i];
   }
   // Fill the rest of the array with the nodes that represent sums from child nodes
   for(int j = n; j > 1; j--) {
    tree[j] = tree[2*j] + tree[2*j+1];
   }
    for(int i = 0; i < q; i++) {
        int low, high;
        cin >> low >> high;
        low--; // get indexes from 0 to n-1 of array
        high--;
        cout << f(1, 0, n-1, low, high) << endl;
    }


    

}