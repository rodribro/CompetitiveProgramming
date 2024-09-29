#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n_cases;
    string first;
    string second;
    string line;

    cin >> n_cases;
    for (int i = 0; i < n_cases; i++)
    {
        cin >> first >> second;

        reverse(first.begin(), first.end());
        reverse(second.begin(), second.end());

        int reverse_first = stoi(first);
        int reverse_second = stoi(second);

        int sum = reverse_first + reverse_second;
        string reverse_sum = to_string(sum);
        reverse(reverse_sum.begin(), reverse_sum.end());

        int final = stoi(reverse_sum);

        cout << final << endl;
    }
}