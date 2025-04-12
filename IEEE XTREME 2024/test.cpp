#include <bits/stdc++.h>
using namespace std;

class S {
    vector<long long> t, l;
    int s;

public:
    S(int n) {
        s = n;
        t.resize(4 * n, 0);
        l.resize(4 * n, 0);
    }

    void propagate(int n, int start, int end) {
        if (l[n] != 0) {
            t[n] += l[n] * (end - start + 1);
            if (start != end) {
                l[n * 2 + 1] += l[n];
                l[n * 2 + 2] += l[n];
            }
            l[n] = 0;
        }
    }

    void update(int a, int b, long long v, int n, int start, int end) {
        propagate(n, start, end);
        if (start > end || start > b || end < a) return;
        if (start >= a && end <= b) {
            l[n] += v;
            propagate(n, start, end);
            return;
        }
        int m = (start + end) / 2;
        update(a, b, v, n * 2 + 1, start, m);
        update(a, b, v, n * 2 + 2, m + 1, end);
        t[n] = t[n * 2 + 1] + t[n * 2 + 2];
    }

    long long query(int a, int b, int n, int start, int end) {
        propagate(n, start, end);
        if (start > end || start > b || end < a) return 0;
        if (start >= a && end <= b) return t[n];
        int m = (start + end) / 2;
        return query(a, b, n * 2 + 1, start, m) + query(a, b, n * 2 + 2, m + 1, end);
    }

    void update(int a, int b, long long v) {
        update(a, b, v, 0, 1, s);
    }

    long long query(int a, int b) {
        return query(a, b, 0, 1, s);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, q;
    cin >> n >> q;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    S s(n);

    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;

        if (t == 0) {
            int a, b, c;
            cin >> a >> b >> c;
            s.update(a, b, c);
        } else if (t == 1) {
            int a, b, c;
            cin >> a >> b >> c;
            // Collect all the indices to update based on the permutation
            for (int j = a; j <= b; ++j) {
                s.update(p[j], p[j], c);
            }
        } else if (t == 2) {
            int a, b;
            cin >> a >> b;
            cout << s.query(a, b) << endl;
        } else if (t == 3) {
            int a, b;
            cin >> a >> b;
            long long sum = 0;
            for (int j = a; j <= b; ++j) {
                sum += s.query(p[j], p[j]);
            }
            cout << sum << endl;
        }
    }

    return 0;
}
