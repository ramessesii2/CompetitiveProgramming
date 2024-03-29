//===============Template==================
#include <bits/stdc++.h>
#include <vector>
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

const int MAX = 1007;
int n, m;
int b;
vector<int> c;
ll dp[MAX][MAX];

void run_case(){
    cin >> m >> n >> b;
    // m++; n++;
    c.resize(n);
    for( auto &x : c ) cin >> x;

    dp[0][b] = 1;
    for( int i = 1 ; i <= n; i++ ){
        for( int j = 0; j <= m; j++){
            if( dp[i-1][j] ){
                if( j + c[i-1] <= m )
                    dp[i][j+c[i-1]] = 1;
                if( j - c[i-1] >= 0)
                    dp[i][j-c[i-1]] = 1;
            }
        }
    }
    ll count = 0;
    for( int i = 0; i <= m; i++ ){
        if( dp[n][i] == 1 ) count++;
    }
    if( count == 0 ) cout << -1;
    else cout << count;
    cout << endl;
}


int main(){
    clock_t begin = clock();
    // sieve(P_MAX);
    file_i_o();
    int tests = 1;

    while(tests-- > 0)
        run_case();

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
        cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}

