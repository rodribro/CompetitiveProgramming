#include <iostream>
#include <memory.h>

using namespace std;

#define N 1030

// Global BIT
int bit[N][N];
// Value Matrix
int matrix[N][N];

// input for matrix size
int m_size;

void update(int x, int y, int num) {
    for(int i = x; i <=m_size; i+=(i & -i)) {
        for(int j = y; j <= m_size; j+=(j&-j)) {
            bit[i][j] += num;
        }
    }
    /*
    while(x <= n) {
        int y1 = y;
        while(y1 <= n) {
            bit[x][y1] += num;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
    */
}

int sum(int x, int y) {
    int sum = 0;
    for(int i = x; i > 0; i-=(i&-i)) {
        for(int j = y; j > 0; j -= (j&-j)) {
            sum += bit[i][j];
        }
    }
    /*
    while(x > 0) {
        int y1 = y;
        while(y1 > 0) {
            sum += bit[x][y1];
            y1 -= (y1&-y1);
        }
        x -= (x&-x);
    }
    */
    return sum;
}


int main() {

    int t, n, x1, y1, num, x2, y2;
    char flag[10];

    // test cases
    scanf("%d", &t);
    while(t--) {

        // size
        scanf("%d", &n);
        m_size = n;

        // Reset bit and matrix
        memset(bit, 0, sizeof(bit));
        memset(matrix, 0, sizeof(matrix));

        //flag
        while(scanf("%s", flag) && flag[0] != 'E') {

            //cout << flag << endl;

            if(flag[2] =='T') {
                scanf("%d %d %d", &x1, &y1, &num);
                x1++; // bit is 1-indexed
                y1++; // bit is 1-indexed
                
                //cout << "(" << x1 << "," << y1 << ") " << num << endl;
                update(x1, y1, num - matrix[x1][y1]);
                matrix[x1][y1] = num;


                /*           
                cout << "[BIT]" << endl;
                for(int i = 0; i <= n; i++) {
                    for(int j = 0; j <= n; j++) {
                        cout << bit[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
                cout << "[MATRIX]" << endl;
                for(int i = 0; i <= n; i++) {
                    for(int j = 0; j <= n; j++) {
                        cout << matrix[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
                */
            }
            else if(flag[2] == 'M') {
                
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

                x1++, y1++, x2++, y2++;
                int ans = sum(x2, y2) - sum(x1-1, y2) -  sum(x2, y1-1) + sum(x1-1, y1-1);
                //cout << "(" << x1 << "," << y1 << ") " << "(" << x2 << "," << y2 << ")" << endl;
                //cout << "Result: " << sum(x2, y2) - sum(x1-1, y2) -  sum(x2, y1-1) + sum(x1-1, y1-1) << endl;
                //cout << endl;
            
               printf("%d\n", ans);
                
            }
        }
    }
    return 0;
}
