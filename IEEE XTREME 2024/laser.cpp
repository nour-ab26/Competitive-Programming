#include <bits/stdc++.h>
typedef long long ll;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ull unsigned long long
#define endl "\n"
using namespace std;

template <typename T>
void pop_front(std::vector<T> &v)
{
    if (v.size() > 0)
    {
        v.erase(v.begin());
    }
}

long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
bool sortFirst(const pair<ll, ll> &a, const pair<ll, ll> &b)
{

    return a.first < b.first && a.second < b.second;
}
const int MOD = 998244353;

pair<long long, long long> getIntersection(long long l1, long long r1, long long l2, long long r2)
{
    long long l_intersection = max(l1, l2);
    long long r_intersection = min(r1, r2);

    if (l_intersection <= r_intersection)
    {
        return {l_intersection, r_intersection};
    }
    else
    {
        return {-1, -1};
    }
}

void solve()
{
    ll l, n, m;
    cin >> l >> n >> m;

    vector<ll> uppera; // stores laser A's upper intersections
    vector<ll> upperb; // stores laser B's upper intersections
    vector<ll> righta; // stores laser A's right intersections
    vector<ll> leftb;  // stores laser B's left intersections

    for (int i = 0; i < n; i++)
    {
        char c;
        ll a;
        cin >> c >> a;

        if (c == 'U')
            uppera.pb(a);
        else
            righta.pb(a);
    }

    for (int i = 0; i < m; i++)
    {
        char c;
        ll a;
        cin >> c >> a;

        if (c == 'U')
            upperb.pb(a);
        else
            leftb.pb(a);
    }

    sort(all(upperb));
    sort(all(uppera));

    ll ans = ((righta.size() + uppera.size()) + 1) * (leftb.size());

    ll prev = (righta.size() + uppera.size()) + 1;
    for (int i = 0; i < upperb.size(); i++)
    {
        int idx = upper_bound(all(uppera), upperb[i]) - uppera.begin();
        ll curr = uppera.size() - idx;

        if (curr > 0)
        {
            ll current = uppera.size() - idx + righta.size() + 1;
            ans += prev;

            prev = current;
        }
        else
        {
            ans += prev;
            prev = righta.size() + 1;
        }
    }

    cout << ans + prev << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}