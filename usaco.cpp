#include <bits/stdc++.h>

using namespace std ;
using int64 = long long ;
const int64 mod = 1e9+7 ;

struct attributes
{
    int64 h, w, s ;
};

void solve()
{
    int n, h ;
    cin >> n >> h ;

    vector<attributes> cow(n) ;
    for(attributes &cowi : cow)
        cin >> cowi.h >> cowi.w >> cowi.s ;

    attributes dp[1<<n] ;
    dp[0] = {0, 0, 100000000000} ;
    int64 mxS = -1 ;

    for(int mask = 1; mask < (1<<n); mask++)
    {
        dp[mask] = {0, 0, -1} ;
        for(int idx = 0; idx < n; idx++)
        {
            if(mask&(1<<idx))
            {
                dp[mask].h += cow[idx].h ;
                dp[mask].s = max(dp[mask].s, min(dp[mask^(1<<idx)].s-cow[idx].w, cow[idx].s)) ;
            }
        }
        if(dp[mask].h >= h)
            mxS = max(mxS, dp[mask].s) ;
    }
    if(mxS >= 0)
        cout << mxS ;
    else
        cout << "Mark is too tall" ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("guard.in", "r", stdin) ;
    freopen("guard.out", "w", stdout) ;

    int test = 1 ;
    // cin >> test ;
    for(int cas = 1; cas <= test; cas++)
    {
        solve() ;
        cout << '\n' ;
    }
    return 0 ;
}


