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




bool bs(vi arr, int target, int ind){
    int s=0, e=arr.size()-1;
    while (s<=e){
        int md=(s+e)/2;
        if ((arr[md]==target)&&(md!=ind)) return true;
        else if (arr[md]>target) e=md-1;
        else s=md+1;
    }
    return false;
}





int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

   #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
         freopen("output.txt", "w", stdout);
    #endif
    
    int n, s=0;
    cin >> n;
    vi arr(n);
    FOR(n){
        cin >> arr[i];
        s+=arr[i];
    }
    if (s%2) cout << 0 << endl;
    else{
        int mid=s/2, ans=0;
        sort(arr.begin(), arr.end());
        for (int i=0; i<n; i++){
            if (arr[i]>mid)break;
            if (bs(arr, mid-arr[i], i)) ans++;
        }
        if (ans%2==0) ans/=2;
        cout << ans << endl;
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
