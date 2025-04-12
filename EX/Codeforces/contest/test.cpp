#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("In.txt", "r", stdin);
         freopen("Outp.txt", "w", stdout);
    #endif
    
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        int reducedSize = n / k;
        vector<vector<int>> reducedGrid(reducedSize, vector<int>(reducedSize));

        for (int i = 0; i < reducedSize; ++i) {
            for (int j = 0; j < reducedSize; ++j) {
                reducedGrid[i][j] = grid[i * k][j * k] - '0'; // Converting char to int
            }
        }

        for (int i = 0; i < reducedSize; ++i) {
            for (int j = 0; j < reducedSize; ++j) {
                cout << reducedGrid[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
