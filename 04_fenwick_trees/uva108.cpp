#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    int v;


    //vector<vector<int>> values;
    vector<vector<long long>> prefix;

    //values.resize(n, vector<int>(n));
    prefix.resize(n+1, vector<long long>(n+1));

    // https://www.youtube.com/watch?v=Hyr3VrgJD2g

    /*
    cout << "[VALUES MATRIX]" << endl;
    // fill matrix of values
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> values[i][j];        
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << values[i][j] << " ";        
        }
        cout << endl;
    }
    
    cout << endl;
    */

    //cout << "[PREFIX SUM MATRIX]" << endl;
    // fill prefix sum matrix, it is padded by a row and column of 0 and indexed at 1 to avoid border checks
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> v;
            prefix[i][j] = v /*values[i-1][j-1]*/ + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];       
        }
    }

    /*
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            cout << prefix[i][j] << " ";       
        }
        cout << endl;
    }
    */

    long long sum;
    long long max_sum = LLONG_MIN; // smallest long long as defined in <climits>

    //cout << "[KADANE]" << endl;
    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <=n; j++) {
            for(int k = i; k <= n; k++) {
                for(int l =j; l <= n; l++) {
                    
                    sum = prefix[k][l] - prefix[i-1][l] - prefix[k][j-1] + prefix[i-1][j-1];
                    max_sum = max(max_sum, sum);
                }
            }
        }
    }
    cout << max_sum << endl;

/*
    -- -- -- -- --
    -- ZZ ZZ XX XX
    -- ZZ ZZ XX XX
    -- YY YY 11 12
    -- YY YY 15 16
*/






    
}