#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;


#define INF 1e9
#define epsilon 1e-9
#define PB push_back
#define FOR(n) for (ll i=0; i<n; i++)



vl subset;
vector<vl> subsets;
vl permutation;
vector<vl> permutations;
vector<string> str_perm;
const ll permlen = 3; //change it for each permutation
bool chosen[permlen+1]; 



void generate_subset(ll from, ll to);
void generate_Permutations();
string bit_representation(ll n);
void str_permutation(string str, int i, int n);



template <typename T>
T binpow(T a, T b, T m=INF) {
    a %= m;
    T res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}



bool canTransform(int a, int b) {
    if (a == b) return true;
    if (b == 1) return true;
    while (a > 1) {
        if (a % b == 0) return true;
        a /= a; // Keep dividing by its divisor until it becomes 1
    }
    return false;
}

int minOperationsToPalindrome(vector<int>& arr) {
    int n = arr.size();
    int operations = 0;
    
    for (int i = 0; i < n / 2; ++i) {
        if (arr[i] != arr[n - 1 - i]) {
            operations += 2;
        }
    }
    
    return operations;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        cout << minOperationsToPalindrome(arr) << "\n";
    }

    return 0;
}