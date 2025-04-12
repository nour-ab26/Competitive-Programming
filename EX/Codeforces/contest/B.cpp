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
const ll permlen = 3; 
bool chosen[permlen+1]; 
 
 
 
void generate_subset(ll from, ll to);
void generate_Permutations();
string bit_representation(ll n);
void str_permutation(string str, int i, int n);
 
struct point {
double x, y;                                  
point() { x = y = 0.0; }                          
point(double _x, double _y) : x(_x), y(_y) {}    
};

    
   
 
 
 
int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    #ifndef ONLINE_JUDGE
        freopen("In.txt", "r", stdin);
         freopen("Outp.txt", "w", stdout);
    #endif
  
  int t;
  cin>>t;
   vector<int> results;

  while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        int SuneetWins = 0;


        int suneet_rounds = 0;
        int slavic_rounds = 0;
        if (a1 > b1) suneet_rounds++;
        else if (a1 < b1) slavic_rounds++;
        if (a2 > b2) suneet_rounds++;
        else if (a2 < b2) slavic_rounds++;
        if (suneet_rounds > slavic_rounds) SuneetWins++;

        suneet_rounds = 0;
        slavic_rounds = 0;
        if (a1 > b2) suneet_rounds++;
        else if (a1 < b2) slavic_rounds++;
        if (a2 > b1) suneet_rounds++;
        else if (a2 < b1) slavic_rounds++;
        if (suneet_rounds > slavic_rounds) SuneetWins++;

        suneet_rounds = 0;
        slavic_rounds = 0;
        if (a2 > b1) suneet_rounds++;
        else if (a2 < b1) slavic_rounds++;
        if (a1 > b2) suneet_rounds++;
        else if (a1 < b2) slavic_rounds++;
        if (suneet_rounds > slavic_rounds) SuneetWins++;

        suneet_rounds = 0;
        slavic_rounds = 0;
        if (a2 > b2) suneet_rounds++;
        else if (a2 < b2) slavic_rounds++;
        if (a1 > b1) suneet_rounds++;
        else if (a1 < b1) slavic_rounds++;
        if (suneet_rounds > slavic_rounds) SuneetWins++;

        results.push_back(SuneetWins);
    }

    for (int result : results) {
        cout << result << endl;
    }

 
    return 0;
 
}
