//===============Template==================
#include <bits/stdc++.h>
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

const int modd = 1000000007;
const int MAX = 1e3+5;
int tests;
int n, m;
int x, y;
int a, b;
int q;
ll grid[MAX][MAX];
            
void run_case(){
    cin >> n >> m;
    loop(i, 1, n+1){
        loop(j, 1, m+1){
            cin >> grid[i][j];
        }
    }
    loop(i, 1, n+1){
        loop(j, 1, m+1){
            grid[i][j] += grid[i-1][j];
            grid[i][j] += grid[i][j-1];
            grid[i][j] -= grid[i-1][j-1];
        }
    }

    cin >> q;
    loop(i, 0, q){
        cin >> a >> b >> x >> y;
        ll ans = grid[x][y];
        ans -= grid[a-1][y];
        ans -= grid[x][b-1];
        ans += grid[a-1][b-1];
        cout << ans << endl;
    }
}

int main(){
    clock_t begin = clock();
    // sieve(P_MAX);
    file_i_o();
    tests = 1;
    for(int it = 1; it <= tests; it++ )
        run_case();

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
        cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}

