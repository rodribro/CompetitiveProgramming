#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool b_check(int time, vector<int> times, int products) {
    int sum = 0;
    for(int i = 0; i < times.size(); i++) {
        sum += time / times[i];
        cout << "Cur. Sum: " << sum << endl;
    }
    cout << endl;
    cout << (products >= sum);
    cout << endl;
    return sum >= products;

}

int b_search(int v, int low, int high, int key) {

    int middle;
    while (low <= high)  {
        middle = low + (high-low) / 2;
    }
    if (key == middle) return middle;
    else if (key < middle) high = middle - 1;
    else low = middle + 1; 

    return -1;
}
int main() {
    int n, t, k;
    cin >> n >> t;
    cout << "Products: " << t << endl;
    vector<int> m_times;

    for(int i = 0; i < n; i++) {
        cin >> k;
        m_times.push_back(k);
    }



    //b_search(t, 0, 10e9, )

}