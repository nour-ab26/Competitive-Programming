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










int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(15);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        int arr[n];
        double x=0;
        FOR(n){
            cin >> arr[i];
            x+=arr[i];
        }
        int y=x;
        sort(arr, arr+n);

        int i=n-1, s1=0;
        int zid=1;
        while(c>100){
            if (i==0){
                zid=0;
                break;
            }
            c-=100;
            s1+=(100*arr[i]);
            y-=arr[i];
            i--;
        }
        if (zid){
            s1 += arr[i]*(c-i-1);
            s1 += (y-arr[i]);
            double ans = s1/x;
            cout << ans;
        }
        else cout << (double) 100;
        cout << endl;
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
