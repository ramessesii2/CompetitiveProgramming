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
const string YES = "YES";
const string NO = "NO";
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

const int modd = 1000000009;
const int MAX = 1000007;
int n, m, i, j, k, l, K;
vvl grid;
            
void run_case(){
    cin >> n >> m >> K;
    n++;
    m++;
    grid.resize(n);
    loop(i, 1, n){
        grid[i].resize(m);
        loop(j, 1, m)cin >> grid[i][j];
    }
    ll sum = 0;
    ll ans = 0;
    loop(i, 1, n){
        sum = 0;
        loop(j, 1, m){
            grid[i][j] += sum;
            sum = grid[i][j];
        }
    }
    loop(i, 1, m){
        sum = 0;
        loop(j, 1, n){
            grid[j][i] += sum;
            sum = grid[j][i];
        }
    }
    loop(i, 1, min(n, m)){
        loop(j, i, n){
            loop(k, i, m){
                if( (grid[j][k] + grid[j-i][k-i] - grid[j-i][k] - grid[j][k-i])/(i*i) >= K) ans++;
            }
        }
    }
    cout << ans << endl;
}

int main(){
    clock_t begin = clock();
    // sieve(P_MAX);
    file_i_o();
    // int tests = 1;
    int tests;
    cin >> tests;

    while(tests-- > 0)
        run_case();

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
        cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}

