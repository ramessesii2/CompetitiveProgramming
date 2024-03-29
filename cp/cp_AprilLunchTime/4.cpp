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

const int MAX = 300007;
int tests;
int n, k, a;
vi g[MAX];
int spc[MAX], has[MAX];
int dep[MAX], closest[MAX], spnode[MAX];

void prep(int x, int p){
    has[x] |= spc[x];
    int spn = 0;
    for( auto f : g[x] ){
        if( f == p ) continue;
        dep[f] = dep[x]+1;
        prep(f, x);
        has[x] |= has[f];
        if( has[f] ) spn = spnode[f];
    }
    if( spc[x] ) spnode[x] = x;
    else spnode[x] = spn;
}

void dfs(int x, int p){
    if( has[x] ) closest[x] = x;
    else closest[x] = closest[p];
    for( auto f : g[x] ){
        if( f == p ) continue;
        dfs(f, x);
    }
}
            
void run_case(){
    cin >> n >> k >> a;
    loop(i, 1, n+1){
        g[i].clear();
        spc[i] = dep[i] = closest[i] = has[i] = spnode[i] = 0;
    }
    loop(i, 1, k+1){
        int x;
        cin >> x;
        spc[x] = 1;
    }
    loop(i,1 , n){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dep[a] = 0;
    prep(a, 0);
    dfs(a, 0);

    for( int i = 1; i <= n; i++ ){
        int maxval = 2*dep[closest[i]]-dep[i];
        cout << maxval;
        if( i < n) cout << " " ;
        else cout << endl;
    }
    loop(i, 1, n+1){
        cout << spnode[closest[i]];
        if( i < n ) cout << " ";
        else cout << endl;
    }
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

