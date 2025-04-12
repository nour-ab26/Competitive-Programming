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

struct point {
double x, y;                                   // higher precision
point() { x = y = 0.0; }                          // default
point(double _x, double _y) : x(_x), y(_y) {}    // user-defined
};

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

float distance(int x1,int y1,int x2,int y2){
    float d=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    return d;
}







int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
         freopen("output.txt", "w", stdout);
    #endif
    
    
    int n;
    cin>>n;
    while(n--){
        int xi,yi;
        cin>>xi>>yi;

    }
    

    return 0;

}






















































void generate_subset(ll from, ll to){
    if (from==to+1){
        subsets.PB(subset);
        return;
    }
    subset.PB(from);
    generate_subset(from+1, to);
    subset.pop_back();
    generate_subset(from+1, to);
}




void generate_Permutations() {
    if (permutation.size() == permlen) {
        permutations.PB(permutation);
        return;
    } else {
        for (int i = 1; i <= permlen; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            generate_Permutations();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}



string bit_representation(ll n){
    ll highest_exp = log2(n);
    string ans=  "";
    for (int i=highest_exp; i>=0; i--){
        ans += (n&(1<<i)) ? "1" : "0"; 
    }
    return ans;
}


ll set_k_bit_to_one(ll n, ll k){
    return (n | (1<<k));
}

ll set_k_bit_to_zero(ll n, ll k){
    return (n & ~(1<<k));
}

ll invert_k_bit(ll n, ll k){
    return (n ^ (1<<k));
}

bool is_power_of_2(ll n){
    return (n & (n-1)) == 0;
}





void str_permutation(string str, int i, int n)
{
    if (i == n - 1)
    {
        for (auto p: str_perm){
            if (p == str) return;
        }
        str_perm.PB(str);
        return;
    }
 
    for (int j = i; j < n; j++)
    {
        swap(str[i], str[j]);       
 
        str_permutation(str, i + 1, n);
 
        swap(str[i], str[j]);
    }
}
