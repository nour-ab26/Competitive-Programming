#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 200000;
const int MOD = 1e9 + 7;

vector<int> dp(MAXN + 1, 0);
vector<long long> prefixSum(MAXN + 1, 0);

void precompute() {
    for (int i = 1; i <= MAXN; ++i) {
        int operations = 0;
        int num = i;
        while (num > 0) {
            num /= 3;
            operations++;
        }
        dp[i] = operations;
    }
    
    for (int i = 1; i <= MAXN; ++i) {
        prefixSum[i] = (prefixSum[i - 1] + dp[i]) % MOD;
    }
}

long long rangeSum(int l, int r) {
    if (l > r) return 0;
    return (prefixSum[r] - prefixSum[l - 1] + MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << rangeSum(l, r) << endl;
    }

    return 0;
}