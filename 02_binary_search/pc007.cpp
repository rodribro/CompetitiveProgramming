#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool b_check(long long time, vector<long long> times, long long products) {
    long long sum = 0;
    for(int i = 0; i < times.size(); i++) {
        sum += time / times[i];
        //cout << "Cur. Sum: " << sum << endl;

        if(sum >= products) return true;
    }
    //cout << "Cond:" << (products <= sum) << endl;
    //cout << endl;
    return false;

}

long long b_search(long long low, long long high, long long key /*products*/, vector<long long> times) {
    long long middle;
    while (low < high)  {
        middle = low + (high-low) / 2;
        //cout << "Middle: " << middle << endl;
        if (b_check(middle, times, key)) high = middle;
        else low = middle + 1; 
    }

    return low;
}
int main() {
    int n, t, k;
    cin >> n >> t;
    //cout << "Products: " << t << endl;
    vector<long long> m_times;

    for(int i = 0; i < n; i++) {
        cin >> k;
        m_times.push_back(k);
    }
    long long low = 0;
    long long high = m_times[0] * t;
    cout << b_search(low, high, t, m_times) << endl;

}