#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    long long n, w;
    cin >> n >> w;
    //cout << "n: " << n << " w: " << w << endl;
    vector<long long> heights(n);

    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    sort(heights.begin(), heights.end());
    /*
    cout << "Array" << endl;
    for(int i = 0; i < n; i++) {
        cout << heights[i] << " ";
    }
    cout << endl; 
    */
    for(int i = 0; i < n-w+1; i++) {
        //cout << " Heights[i] "<< heights[i] << endl;
        //cout << " Heights[i+w] "<< heights[i+w] << endl;

        if(i==n-w){
            cout << "yes" << endl;
        } 

        if(heights[i+w] <= heights[i] && heights[i+w]!=0) {
            cout << "no" << endl;
            break;             
        }
        


    }

   
    
   


}
/*
5 3
180 160 200 190 150

3 1
150 150 140
*/