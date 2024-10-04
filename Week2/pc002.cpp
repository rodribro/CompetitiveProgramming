#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int num;

    map<int, int> map;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        map[num]++;
    }

    int to_rem = 0;
    for (auto it = map.begin(); it != map.end(); ++it)
    {
        if (it->first != it->second)
        {
            if (it->first < it->second)
            {
                to_rem += (it->second - it->first);
            }
            else
                to_rem += it->second;
        }
    }
    cout << to_rem << endl;
}