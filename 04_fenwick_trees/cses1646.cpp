#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> values(n);
    vector<long long> prefix(n+1);

    // fill values vector
    for(int i = 0; i < n; i++) {
        cin >> values[i];
    }

    /*
    for(int i = 0; i < n; i++) {
        cout << values[i] << " ";
    }
    */

    // fill prefix sum vector
    for(int i = 1; i <= n; i++) {
        prefix[i] += prefix[i-1] + values[i-1];
    }

    /*
    for(int i = 0; i < n+1; i++) {
        cout << prefix[i] << " ";
    }
    */

   // queries
   for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a-1] << endl;
   }



}