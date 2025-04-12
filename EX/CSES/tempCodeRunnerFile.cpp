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

const int MOD=1000000007; 
long long int inverse(long long int i){   //The modular multiplicative inverse
    if(i==1) return 1;
    return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}


bool is_possible(int encoded, int a, int b, int c) {
    return encoded == a + b + c;
}



   void dfs(int encoded, int a, int b, int c, vector<char>& word, vector<string>& results) {
    if (a > 26 || b > 26 || c > 26) {
        return;