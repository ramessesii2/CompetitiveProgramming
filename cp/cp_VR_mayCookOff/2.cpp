#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long long double
#define all(r)  (r.begin(), r.end())
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;

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

const int inf = INT_MAX;

int TC;
int main()
{
    file_i_o();
    cin >> TC;
    while (TC--)
    {
        int N, K;
        cin >> N >> K;
        vi arr(N);
        for( auto &x: arr ) cin >> x;
        if( N == K ){
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        for( int i = 0; i < K; i++){
            map<int, int> mp;
            int count = 0;
            for( int j = i; j < N; j+=K ){
                mp[arr[j]]++;
                count = max(count, mp[arr[j]]);
            }
            ans += count;
        }
        cout << N-ans << endl;
    }
    return 0;
}


