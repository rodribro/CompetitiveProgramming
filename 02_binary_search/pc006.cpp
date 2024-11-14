#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

bool specialSort(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

int main()
{
    int n;
    cin >> n;
    int number;
    pair<int, int> n_represent;
    vector<pair<int, int>> ordered_nums;

    for (int i = 0; i < n; i++)
    {
        cin >> number;

        n_represent.first = number;
        n_represent.second = bitset<30>(number).count(); // we need 30 bits to represent up to 10⁹, count gives us the set bits (number of 1s)
        // cout << "Number: " << n_represent.first << endl;
        // cout << "Number of 1s: " << n_represent.second << endl;
        // cout << endl;

        ordered_nums.push_back(n_represent);
    }

    /*
    cout << "Unorder vector: ";
    for (auto pair : ordered_nums)
    {
        cout << pair.first << " ";
    }
    cout << endl;
    */
    sort(ordered_nums.begin(), ordered_nums.end(), specialSort);
    // cout << "Ordered vector: ";
    for (int i = 0; i < n - 1; i++)
    {
        cout << ordered_nums[i].first << " ";
    }
    cout << ordered_nums[n - 1].first << endl;
}