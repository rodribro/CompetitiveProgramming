//uva 166
//Making Change

#include <iostream>
#include <climits>
#include <vector>
#include <cstdio>
#include <iomanip>

using namespace std;

int main(void)
{
    int coins[6] = {1, 2, 4, 10, 20, 40};//unit is cent
    int count[6];

    vector <int> sChange(101, INT_MAX);//for salesman
    sChange[0] = 0;

    for (int i = 0; i < 6; ++i)//for salesman
        for (int j = 1; j <= 100; ++j)
            if (j - coins[i] >= 0 && sChange[j - coins[i]] != INT_MAX)
                sChange[j] = min(sChange[j], sChange[j - coins[i]] + 1);

    while (1){
        cin >> count[0] >> count[1] >> count[2] >> count[3] >> count[4] >> count[5];
        if (!(count[0] | count[1] | count[2] | count[3] | count[4] | count[5]))
            break;

        int money = 0;
        int cent = 0;
        scanf("%d.%d", &money, &cent);
        money = money * 100 + cent;
        money /= 5;

        vector <int> allCoins;
        int sum = 0;

        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < count[i]; ++j){
                sum += coins[i];
                allCoins.push_back(coins[i]);
            }

        vector < vector <int> > cChange(allCoins.size() + 1, vector <int> (sum + 1, INT_MAX));//for us

        for (int i = 0; i <= allCoins.size(); ++i)
            cChange[i][0] = 0;

        for (int i = 1; i <= allCoins.size(); ++i){//for us
            for (int j = 1; j <= sum; ++j)
                if (j - allCoins[i - 1] >= 0 && cChange[i - 1][j - allCoins[i - 1]] != INT_MAX)
                    cChange[i][j] = min(cChange[i - 1][j], cChange[i - 1][j - allCoins[i - 1]] + 1);
                else
                    cChange[i][j] = cChange[i - 1][j];

            for (int j = 1; j < sum; ++j)
                for (int k = j + 1; k <= sum; ++k)
                    if (cChange[i][k] != INT_MAX && sChange[k - j] != INT_MAX)
                        cChange[i][j] = min(cChange[i][j], cChange[i][k] + sChange[k - j]);
        }

        cout << right << setw(3) << cChange[allCoins.size()][money] << endl;
    }

    return 0;
}

/*
My solution needs fixing
#include <iostream>
#define INF 505
using namespace std;

// Remember that coins are always multiples of five! Adjust the index for Dynamic Programming

void solve(vector<pair<int, int>> values, int my_coins[], int amount) {
    int max_amount = max_amount;

    /*
    //initial amount of coins for a given coin value
    int five_initial = values[0].second;
    int ten_initial = values[1].second;
    int twenty_initial = values[2].second;
    int fifty_initial = values[3].second;
    int hundred_initial = values[4].second;
    int two_hundred_initial = values[5].second;

    // i = 1 -> 5
    // i = 2 -> 10
    my_coins[0] = 0;
    for(int i = 1; i <= max_amount; i++) {
        my_coins[i] = INF;
        for(int j = 0; j < values.size(); j++) {
            if(values[j].first <= i && 1 + my_coins[i - values[j].first] < my_coins[i] && values[j].second > 0) {
                values[j].second -= 1;
                //cout << "Coin: " << values[j].first << " ,Amount: " << values[j].second << endl;
                my_coins[i] = 1 + my_coins[i - values[j].first];
                
            }
            else {continue;}
        }
        
        //cout << endl;
        // reset coin amounts
        //cout << "[RESETTING]" << endl;
        values[0].second = five_initial;
        //cout << "Reset 5: " << values[0].second << endl;
        values[1].second = ten_initial;
        //cout << "Reset five 10: " << values[1].second << endl;
        values[2].second = twenty_initial;
        //cout << "Reset 20: " << values[2].second << endl;
        values[3].second = fifty_initial;
        //cout << "Reset 50: " << values[3].second << endl;
        values[4].second = hundred_initial;
        //cout << "Reset 100: " << values[4].second << endl;
        values[5].second = two_hundred_initial;
        //cout << "Reset 200: " << values[5].second << endl;
        //cout << endl;
        
    }*/
/*
   // Initialize DP array with infinity
    for (int i = 0; i <= max_amount; i++) {
        my_coins[i] = INF;
    }
    my_coins[0] = 0; // Base case: 0 coins needed for amount 0

    // Dynamic Programming
    for (int j = 0; j < values.size(); j++) { // Iterate over each coin type
        int coin_value = values[j].first;     // Coin value in "5-cent units"
        int coin_count = values[j].second;   // Number of coins available

        // Process this coin type
        for (int i = max_amount; i >= coin_value; i--) { // Iterate backwards
            for (int k = 1; k <= coin_count; k++) { // Use up to `coin_count` of this coin
                if (i >= k * coin_value) {
                    my_coins[i] = min(my_coins[i], my_coins[i - k * coin_value] + k);
                }
            }
        }
    }

    for(int i = 0; i <= max_amount ; i++) {
        cout << "i:" << i << ", Value: " << i*5 << ", Num coins: " << my_coins[i] << endl;
    }
    cout << endl;

    cout << "Coins needed: " << my_coins[max_amount] << endl;
    cout << endl;
    //return my_coins[max_amount];

}
int main() {
    vector<pair<int, int>> values(6);
    int my_coins[101]; // space for one hundred 5 cent coins (including 0)
    int five, ten, twenty, fifty, hundred, two_hundred;

    cin >> five >> ten >> twenty >> fifty >> hundred >> two_hundred;
    while(!(five == 0 && ten == 0 && twenty == 0 && fifty == 0 && hundred == 0 && two_hundred == 0)) {
        

        // read and cast amount to int
        float amount;
        cin >> amount;
        amount = (int)(amount*100);

        //fill values vector
        //five
        values[0].first = 1; //5;
        values[0].second = five;
        //ten
        values[1].first = 2; //10
        values[1].second = ten;
        //twenty
        values[2].first = 4; //20
        values[2].second = twenty;
        //fifty
        values[3].first = 10; //50
        values[3].second = fifty;
        //one hundred
        values[4].first = 20; //100
        values[4].second = hundred;
        //two hundred
        values[5].first = 40; //200
        values[5].second = two_hundred;

        cout << "[VALUES VECTOR]" << endl;
        for(int i = 0; i <= 5; i++) {
            cout << "Coin: " << values[i].first * 5 << ", Num. coins: " << values[i].second << endl;
        }
        cout << endl;
        cout << "Amount to pay: " << amount << endl;
        cout << endl;

        cout << "[SOLVING]" << endl;
        solve(values, my_coins, amount);

        cin >> five >> ten >> twenty >> fifty >> hundred >> two_hundred;
    }





    return 0;
}
*/