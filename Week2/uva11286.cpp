#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{

    // classes popularity
    int popularity = 0;

    // set of classes chosen by student
    string frosh;

    // identifier for each class
    int val;

    // n_cases
    int n_cases;
    cin >> n_cases;
    // cout << "N_cases: " << n_cases << endl;
    // cout << endl;

    int max_freq = 0;
    while (n_cases != 0)
    {
        // map for vector frequency
        map<vector<int>, int> freqs;

        for (int i = 0; i < n_cases; i++)
        {
            // vector to store classes
            vector<int> classes;

            for (int i = 0; i < 5; i++)
            {
                cin >> val;
                // cout << "Val:" << val << endl;
                classes.push_back(val);
            }
            // cout << endl;

            sort(classes.begin(), classes.end()); // É PRECISO DAR SORT PARA O MAP COMPARAR OS VALORES??

            // Increases the counter for each set of classes
            freqs[classes]++;
            // cout << "Frequencies of " << i << ":" << freqs[classes] << endl;
            // cout << endl;

            max_freq = max(max_freq, freqs[classes]);
            // cout << "Max. Freq.: " << max_freq << endl;
            // cout << endl;
        }

        for (auto it = freqs.begin(); it != freqs.end(); it++)
        {
            // cout << "Vector freq:" << (it->second) << endl;
            if (max_freq == it->second)
            {
                popularity += max_freq;
            }
        }
        cout << popularity << endl;
        // cout << "Popularity:" << popularity << endl;
        // cout << "----------------------------------------" << endl;
        // cout << endl;

        // Reset popularity and max_freq
        popularity = 0;
        max_freq = 0;

        cin >> n_cases;
        // cout << "N_cases: " << n_cases << endl;
        // cout << endl;
    }
}