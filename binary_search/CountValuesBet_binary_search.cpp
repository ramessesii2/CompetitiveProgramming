//Template
#include <bits/stdc++.h>
using namespace std;

#define ll              long long int
#define ld              long double
#define mod             1000000007
#define pb              push_back
#define ff              first
#define ss              second
#define inf             1e18
#define mid(l, r)       (l+(r-l)/2)
#define loop(i, a, b)   for(int i=(a); i<b; i++)
#define loopr(i, a, b)  for(int i=(a); i>b; i--)

#define sz(a)           int((a).size())
#define all(c)          c.begin(), c.end()
#define allr(c)         c.rbegin(), c.rend()

#define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define present(container, element) \
    (container.find(element) != container.end())
#define vpresent(container, element) \
        (find(all(container),element) != container.end())

#define print(dp, n); \
    loop(i, 0, n){cout << dp[i] << " ";}cout << endl; 
#define print2(dp, n, m); \
    loop(i, 0, n){loop(j, 0, m){cout << dp[i][j] << " ";}cout << endl;} 
#define countetbits(i)\
    __builtin_popcount(i)

typedef vector< long long int > vi;
typedef vector< string > vs;
typedef vector< vi > vvi;
typedef pair< ll,ll > pii;

template <class A, class B>
auto findMin(A a, B b) -> decltype(a < b ? a : b)
{
    return (a < b) ? a : b;
}
//Type Inference refers to automatic deduction of the data type of an expression in a programming language.
//Auto lets you declare a variable with particular type whereas decltype lets you extract the type from the variable so decltype is sort of an operator that evaluates the type of passed expression.

void file_i_o(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
            
/* bool compare(int a, int b){ */
/*     return a>b; */
/* } */
<<<<<<< HEAD
ll binary_search_cleft(vi arr, ll low , ll high , ll search_key){
    while(high>low+1){
        ll mid = mid(low, high);
        if(arr[mid] <= search_key){
            low = mid;
        }
        else high = mid;
    }
    
    return low+1;
}
ll binary_search_cright(vi arr, ll low, ll high, ll search_key){
    //-inf 23 54 56 67 +inf
    // ^                 ^
    // |(l)              |(r)
    // we've to maintain the invariant
    // a[l] < x and a[r] >= x
    while(high>low+1){
        ll mid = mid(low, high);
        if(arr[mid] < search_key){
            low = mid;
        }
        else high = mid;
    }
    
    return high+1;
}
=======

>>>>>>> b3f8940d63abb482d13def048981d2499351583e

void run_case(){
    ll n;
    cin >> n;
    vi arr(n);
    loop(i, 0, n) cin >> arr[i];
    sort(all(arr));
    ll k; 
    cin >> k;
    while(k--){
<<<<<<< HEAD
        ll l, r;
        cin >> l >> r;
        ll high = binary_search_cright(arr, -1LL,  n,  l);
        ll low = binary_search_cleft(arr, -1LL,  n,  r);
        if(low  >= high){
            cout << low - high + 1 << " ";
        }
        else cout << 0 << " ";
=======
        ll lv, rv;
        cin >> lv >> rv;
        // finding leftmost index >= lv
        ll high = n;
        ll low = -1;
        while(high > low +1){
            ll mid = mid(low, high);
            //finding the leftmost index
            // -inf 3 5 6 9 10 +inf
            //   ^               ^
            //   |(low)          |(high)
            //invariant a[low] < lv and a[high] >= lv
            if(arr[mid] < lv){
                low = mid;
            }
            else high = mid;
        }
        ll left = high;
        low = -1;
        high = n;
        // finding the rightmost index <= rv
        while(high > low +1){
            ll mid = mid(low, high);
            //invariant a[low] <= rv and a[high] > rv
            if(arr[mid] > rv){
                high = mid;
            }
            else  low = mid;
        }
        ll right = low ;
        /* print(arr, n); */
        /* cout << left << " " << right << endl; */
        cout << right - left + 1<< " ";
>>>>>>> b3f8940d63abb482d13def048981d2499351583e
    }
}

int main(){
    clock_t begin = clock();
    file_i_o();
    int tests = 1;
    /* int tests; */
    /* cin >> tests; */

    while(tests-- > 0)
        run_case();

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}


