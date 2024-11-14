#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

bool b_check(vector<long double> vols, long double middle, int friends) {

    int sum = 0;
    int size = vols.size();
    for(int i = 0; i < size; i++) {
        sum += floor(vols[i] / middle);
        if(sum >= friends) return true;
        //cout << "Cur. sum: " << sum << endl;
    }
    //cout << "Final Sum: " << sum << endl;
    //cout << endl;
    return false;
}

void b_search(long double low, long double high, vector<long double> vols, int friends) {
    while (fabs(high - low) > 1e-6) {
        long double middle = low + (high-low)/2;
        //cout << "Middle: " << middle << endl;
        if(b_check(vols, middle, friends)) {
            low = middle;
            //cout << "Cur. High: " << high << endl;
        } 
            
        else high = middle;
        //cout << "Cur. Low: " << low << endl;
    }
    
    cout << fixed << low << endl;
}

int main() {
   int t, n, f;
   long double r;
   vector<long double> vol;
   cin >> t;
   for(int i = 0; i < t; i++) {
        vol.clear();
        cin >> n >> f;
        f++;
        //cout << "Radius: " ;
        for(int j = 0; j < n; j++) {
            cin >> r;
            //cout << r << " ";
            r = r*r*M_PI;
            vol.push_back(r);
            
        }
        //cout << endl;
        sort(vol.begin(), vol.end());
        /*
        cout << "Volumes: ";
        for(int j = 0; j < n; j++) {
            cout << vol[j] << " ";
            
        }
        cout << endl;
        */
        long double low = 0;
        long double high = vol[vol.size() - 1];
        //long double middle = low + (high-low) / 2;
        //cout << "Initial High: " << high << endl;
        //cout << "Initial Low: " << low << endl;
        //cout << "Middle: " << middle << endl;
        //cout << b_check(vol, middle , f) << endl;
        b_search(low, high, vol, f);
   }
   
}