//===============Template==================
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define endl            '\n' 
#define ll              long long int
#define ld              long double
#define pb              push_back
#define ff              first
#define ss              second
#define infl             1e18
#define inf              1e9
#define mid(l, r)       (l+(r-l)/2)
#define loop(i, a, b)   for(int i=(a); i<b; i++)
#define loopr(i, a, b)  for(int i=(a); i>b; i--)
#define sz(a)           int((a).size())
#define all(c)          c.begin(), c.end()
#define allr(c)         c.rbegin(), c.rend()
#define print(dp, n); \
    loop(i, 0, n){cerr << dp[i] << " ";}cerr << endl; 
#define countsetbits(i)\
    __builtin_popcount(i)
typedef pair< ll,ll > pll;
typedef pair< int, int> pii;
typedef pair< double, double> pdd;
typedef vector< long long int > vl;
typedef vector< int > vi;
typedef vector< pii > vpii;
typedef vector< pll > vpll;
typedef vector< string > vs;
typedef vector< double > vd;
typedef vector< vi > vvi;
typedef vector< vl > vvl;
const string YES = "YES\n";
const string NO = "NO\n";
void file_i_o(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("cerr.txt", "w", stderr);
#endif
}

int tests;
            
void run_case(){
    vi row[3], col[3]; 
    int n, m, q, a, b;
    string ro, co;
    cin >> ro  >> co;
    m = sz(ro);
    n = sz(co);
    cin >> q;
    loop(i, 1, 3) row[i].assign(m+1, -1);
    loop(i, 1, 3) col[i].assign(n+1, -1);
    row[1][1] = col[1][1] = min((ro[0]-'0'), (co[0]-'0'));
    loop(i, 2, m+1){
        row[1][i] = min(1-row[1][i-1], (ro[i-1]-'0'));
    }
    loop(i, 2, n+1){
        col[1][i] = min(1-col[1][i-1], (co[i-1]-'0'));
    }
    // loop(i, 1, 3){
    //     loop(j, 1, n+1)cerr << col[i][j] << " ";
    //     cerr << endl;
    // }
    map<int, int> mp;
    mp[0] = row[2][2] = col[2][2] = min(1-row[1][2], 1 - col[1][2]);
    loop(i, 3, m+1){
        row[2][i] = min(1-row[1][i], 1-row[2][i-1]);
        mp[2-i] = row[2][i];
    }
    loop(i, 3, n+1){
        col[2][i] = min(1-col[1][i], 1-col[2][i-1]);
        mp[i-2] = col[2][i];
    }
    // loop(i, 1, 3){
    //     loop(j, 1, m+1)cerr << row[i][j] << " ";
    //     cerr << endl;
    // }
    string ans;
    while( q-- ){
        cin >> a >> b;
        if( a == 1 ) ans += to_string(1-row[1][b]);
        else if ( b == 1 ) ans += to_string(1-col[1][a]);
        else ans += to_string(1-mp[a-b]);
    }
    cout << ans << endl;
}

int main(){
    clock_t begin = clock();
    // sieve(P_MAX);
    file_i_o();
    cin >> tests;
    for(int it = 1; it <= tests; it++ )
        run_case();

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
        cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}

