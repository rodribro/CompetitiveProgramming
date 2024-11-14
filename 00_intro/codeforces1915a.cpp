#include <iostream>
using namespace std;

int main()
{
    int num_cases;
    int a;
    int b;
    int c;
    int ans;

    cin >> num_cases;

    for (int i = 0; i < num_cases; i++)
    {
        cin >> a;
        cin >> b;
        cin >> c;

        if (a == b)
        {
            ans = c;
        }
        else if (a == c)
        {
            ans = b;
        }
        else
        {
            ans = a;
        }

        cout << ans << "\n";
    }
}
