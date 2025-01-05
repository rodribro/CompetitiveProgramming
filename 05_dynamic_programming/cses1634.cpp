#include <iostream>
#include <vector>
#define INF 1000005
using namespace std;

int solve(vector<int> coins, int sum, vector<int> values) {
    coins[0] = 0;
    for(int i = 1; i <= sum; i++) {
        coins[i] = INF;
        for(int j = 0; j < values.size(); j++) {
            if(values[j] <= i && 1 + coins[i-values[j]] < coins[i]) {
                coins[i] = 1 + coins[i-values[j]];    
            }
        } 
    }

    for(int i = 0; i <= sum; i++) {
        if(coins[i] == INF) {
            coins[i] = -1;
        }
    }
    /*
    for(int i = 0; i <= sum; i++) {
        cout << coins[i] << " ";
    }
    cout << endl;
    */
    return coins[sum];
}

int main() {
    int n_coins;
    int sum;
    vector<int> values;
    vector<int> coins;
    cin >> n_coins >> sum;

    values.resize(n_coins);
    coins.resize(sum+1);

    // fill values array
    for(int i = 0; i < n_coins; i++) {
        cin >> values[i];
    }

    cout << solve(coins, sum, values) << endl;





    
    return 0;
}