#include <bits/stdc++.h>
using namespace std;

int CountLower(const std::set<int>& set1, const std::set<int>& set2) {
    int total = 0;
    for (int num : set2) {
        auto it = set1.lower_bound(num);
        total += distance(set1.begin(), it); 
        }
    return total;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int l, n, m;
    cin >> l >> n >> m;

    int NaU = 0, NbU = 0, NaR = 0, NbL = 0;
    set<int> aU, bU;

    for (int i = 0; i < n ; i++) {
        char c;
        int coord;
        cin >> c >> coord;
        if (c == 'U') {
            NaU++;
            aU.insert(coord);
        } else if ( c == 'R') {
            NaR++;
        } 
    }
    
    for (int i = 0; i < m ; i++) {
        char c;
        int coord;
        cin >> c >> coord;
        if ( c == 'L') {
            NbL++;
        } else if ( c == 'U') {
            NbU++;
            bU.insert(coord);
        }
    }
   
    int uniqueHorizontalDivisions = NaU + NbU;
    int uniqueVerticalDivisions = NaR + NbL;
    int area = (uniqueHorizontalDivisions + 1) * (uniqueVerticalDivisions + 1);
    int intersect = CountLower(aU, bU);

    area -= intersect;

    cout << area << endl;

    return 0;
}
