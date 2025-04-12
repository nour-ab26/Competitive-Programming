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


int largestDivisor(int n) {
    for (int i = n / 2; i >= 2; i--) {
        if (n % i == 0) {
            return i;
        }
    }
    return 1;
}

int tournamentWinner(int n) {
    int winner = 1;
    int maxDiv = 1;
    for (int i = 2; i <= n; i++) {
        int div = largestDivisor(i);
        if (div > maxDiv) {
            maxDiv = div;
            winner = i;
        }
    }
    return winner;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << tournamentWinner(n) << "\n";
    }
    return 0;
}

