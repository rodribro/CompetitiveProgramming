#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// Useful link:  http://www.algorithmist.com/index.php/UVa_10003

int solve(vector<vector <int>> &dp, vector<int> &cuts, int left, int right) {

    int ans = INT_MAX;

    /* Base case: nothing to cut
    cuts = {0, 25, 50,75,100}
    if left = 1 and right = 2 we have:
        {25,50}, hence we can't cut anything
        there's no middle point to cut further
    */
    if(left+1 == right) {
        return dp[left][right] = 0;
    }
    // Use value saved in memo table (dp)
    if(dp[left][right] != -1) {
        return dp[left][right];
    }
    
    for(int i = left+1; i < right; i++) {
        ans = min(ans, cuts[right] - cuts[left] + solve(dp, cuts, left, i) + solve(dp, cuts, i, right));
    }
    return dp[left][right] = ans;
    
}
int main() {
    int length, n_cuts;
    vector<int> cuts;
    vector<vector<int>> dp;
    cin >> length;
    //int counter = 0;
    while(length != 0) {
        //counter ++;
        //cout << "Case: " << counter << endl;
        // [FILL IN CUTS VECTOR]
        /*
         * We'll use the indices of this array instead 
         * of the actual value to solve the problem using DP
         */
        cin >> n_cuts;
        cuts.resize(n_cuts+2);
        for(int i = 1; i <= n_cuts; i++) {
            cin >> cuts[i];
        }
        // [SET MIN (0) AND LENGTH AS PART OF ARRAY]
        cuts[0] = 0; 
        cuts[n_cuts+1] = length; 
        
        // [RESIZE DP VECTOR] 
        dp.resize(n_cuts+2, vector<int>(n_cuts+2, -1));

        cout << "The minimum cutting is " << solve(dp, cuts, 0, n_cuts+1) << "." << endl;
        /*
        for(int i = 0; i < n_cuts+2; i++) {
            for(int j = 0; j < n_cuts+1; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        */




        cuts.clear();
        dp.clear();
        cin >> length;
    }

    return 0;
}