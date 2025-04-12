#include <iostream>
#include <vector>

using namespace std;

// Fenwick Tree class for range updates and range queries
class FenwickTree {
public:
    FenwickTree(int n) : data(n + 1, 0) {}

    // Adds `value` to element at index `idx`
    void add(int idx, long long value) {
        while (idx < data.size()) {
            data[idx] += value;
            idx += idx & -idx;
        }
    }

    // Gets the prefix sum up to index `idx`
    long long sum(int idx) const {
        long long result = 0;
        while (idx > 0) {
            result += data[idx];
            idx -= idx & -idx;
        }
        return result;
    }

    // Range update: adds `value` to all elements in [l, r]
    void range_add(int l, int r, long long value) {
        add(l, value);
        add(r + 1, -value);
    }

    // Gets the value at a specific index (point query)
    long long point_query(int idx) const {
        return sum(idx);
    }

private:
    vector<long long> data;
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> P(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> P[i];
    }
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    FenwickTree treeA(n);  // Fenwick Tree for the original array A
    FenwickTree treeP(n);  // Fenwick Tree for the permuted indices

    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        
        if (type == 0) {
            // Type 0: Direct range update
            long long c;
            cin >> c;
            treeA.range_add(l, r, c);
        }
        else if (type == 1) {
            // Type 1: Permuted range update
            long long c;
            cin >> c;
            for (int i = l; i <= r; ++i) {
                treeP.add(P[i], c);
            }
        }
        else if (type == 2) {
            // Type 2: Direct range sum query
            long long sum_r = treeA.point_query(r);
            long long sum_l = treeA.point_query(l - 1);
            cout << sum_r - sum_l << endl;
        }
        else if (type == 3) {
            // Type 3: Permuted range sum query
            long long result = 0;
            for (int i = l; i <= r; ++i) {
                result += treeP.point_query(P[i]);
            }
            cout << result << endl;
        }
    }

    return 0;
}
