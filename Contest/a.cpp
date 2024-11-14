#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {

    string sorted_word, unsorted_word, rev;
    cin >> sorted_word;

    for(int i = 0; i < sorted_word.length(); i++) {
        sorted_word[i] = tolower(sorted_word[i]);
    }

    unsorted_word = sorted_word;
    sort(sorted_word.begin(), sorted_word.end());
    rev = sorted_word;
    reverse(rev.begin(), rev.end());

    /*
    cout << "Unsorted:" << unsorted_word  << endl;
    cout << "Sorted: " << sorted_word << endl;
    cout << "Rev: " << rev << endl;
    */
    if(sorted_word.compare(unsorted_word) == 0 || unsorted_word.compare(rev) == 0) {
        cout << "yes" << endl;
    } 
    else {
        cout << "no" << endl;
    }



}

/*
3 1
150 150 140
*/