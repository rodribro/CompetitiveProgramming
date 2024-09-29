#include <iostream>
using namespace std;

int main()
{
    size_t n_moves = 0;
    int n;
    cin >> n;

    size_t prev;
    cin >> prev;

    size_t num;
    for (int i = 1; i < n; i++)
    {
        cin >> num;

        if (num < prev)
        {
            n_moves += (prev - num);
        }
        else
        {
            prev = num;
        }
    }

    cout << n_moves << endl;
}