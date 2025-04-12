#include <bits/stdc++.h>

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



void backtrack(string &digits, int k, string &maxNumber) {
    if (k == 0) {
        if (digits > maxNumber) {
            maxNumber = digits;
        }
        return;
    }

    int n = digits.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(digits[i], digits[j]);

            if (digits[0] != '0') {
                backtrack(digits, k - 1, maxNumber);  
            }
            swap(digits[i], digits[j]);
        }
    }
}

int main() {
    string N;
    int K;
    cin >> N >> K;
     #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string maxNumber = N;  
    backtrack(N, K, maxNumber);

    cout << maxNumber;  
    return 0;
}