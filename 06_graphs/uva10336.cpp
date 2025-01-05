#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// DFS function
void dfs(int x, int y, char letter, vector<vector<bool>> &visited, vector<vector<char>> &matrix) {
    
    int h = matrix.size();
    int w = matrix[0].size();

    // Return conditions
    if(!(x >= 0 && x < h && y >= 0 && y < w)) return;
    if(visited[x][y] || matrix[x][y] != letter) return;

    visited[x][y] = true;

    //printf("Cur. position: (%d,%d) | Cur. char %c\n", x, y, letter);

    dfs(x+1, y, letter, visited, matrix);
    dfs(x-1, y, letter, visited, matrix);
    dfs(x, y+1, letter, visited, matrix);
    dfs(x, y-1, letter, visited, matrix);

}

// Connected components function
void connected_components(vector<vector<bool>> &visited, vector<vector<char>> &matrix, map<char, int> &dict) {

    int h = matrix.size();
    int w = matrix[0].size();
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(!visited[i][j]) {
                char cur_letter = matrix[i][j];
                dfs(i,j, cur_letter, visited, matrix);
                dict[cur_letter]++;
            }
        }
    }
}

// sorting function previously used in PC006
bool special_sort(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

// Sorting function inspired by Geeks for Geeks (https://www.geeksforgeeks.org/sorting-a-map-by-value-in-c-stl/)
void map_sort(map<char, int> &dict) 
{ 
 
    // Declare vector of pairs 
    vector<pair<char, int> > a; 
 
    // Copy key-value pair from map to vector of pairs 
    for (auto it : dict) { 
        a.push_back(it); 
    } 
 
    // Sort using comparator function 
    sort(a.begin(), a.end(), special_sort); 
 
    // Print the sorted value 
    for (auto it : a) { 
 
        printf("%c: %d\n", it.first, it.second);
    } 
} 

int main() {
    int t, h, w;
    cin >> t;

    for(int i = 1; i <= t; i++) {
        cin >> h >> w;

        // Create and resize matrix
        vector<vector<char>> matrix;
        matrix.resize(h, vector<char>(w));

        // Create and resize visited matrix 
        vector<vector<bool>> visited;
        visited.resize(h, vector<bool>(w));

        // Fill chat matrix
        for(int i = 0; i < h; i++) {
            for(int j  = 0; j < w; j++) {
                cin >> matrix[i][j];
            }
        }

        // Map for letter cluster's number
        map<char, int> dict;

        // Function calls
        connected_components(visited, matrix, dict);
        printf("World #%d\n", i);
        map_sort(dict);
    }
    return 0;
}