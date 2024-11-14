#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


bool b_check(vector<long double> vols, long double middle, int friends)
{

    int sum = 0;
    // for (const auto &v : vols)
    // {
    //     cout << v << " ";
    // }
    // cout << endl;
    int size = vols.size();
    // cout << "Size: " << size << endl;
    for (int i = 0; i < size; i++)
    {
        sum += static_cast<int>(vols[i] / middle);
        // cout << "Sum: " << sum << endl;
        if (sum >= friends)
        {
            // cout << "with mid = " << middle << ", the total (" << sum << ") surpasses the number of people (f+1 = " << friends << "), so low will be updated to mid" << endl;
            return true;
        }
    }
    // cout << "Sum: " << sum << endl;
    // cout << "with mid = " << middle << ", the total (" << sum << ") does not surpass the number of people (f+1 = " << friends << "), so high will be updated to mid" << endl;
    return false;
}

void b_search(long double low, long double high, vector<long double> vols, int friends)
{
    while (fabs(high - low) > 1e-5)
    {
        long double middle = low + (high - low) / 2;
        if (b_check(vols, middle, friends))
        {
            low = middle;
        }

        else
            high = middle;
    }

    cout << low << endl;
}

int main()
{
    int t, n, f;
    long double r;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        // vol.empty();
        cin >> n >> f;
        vector<long double> vol(n);
        f++;
        // cout << "Radius: ";
        for (int j = 0; j < n; j++)
        {
            cin >> r;
            // cout << r << " ";
            r = r * r * M_PI;
            vol.push_back(r);
        }
        cout << endl;
        sort(vol.begin(), vol.end());
        // cout << "Volumes: ";
        for (int j = 0; j < n; j++)
        {
            // cout << vol[j] << " ";
        }
        cout << endl;

        // for (const auto &v : vol)
        // {
        //     cout << v << " ";
        // }
        // cout << endl;

        long double low = 0;
        long double high = vol[vol.size() - 1];
        // long double middle = low + (high - low) / 2;
        // cout << "Middle: " << middle << endl;
        // cout << b_check(vol, middle , f) << endl;
        b_search(low, high, vol, f);
    }
}