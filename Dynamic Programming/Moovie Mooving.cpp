#include <bits/stdc++.h>

using namespace std ;
using int64 = long long ;
const int64 mod = 1e9+7 ;

void solve()
{
    int n, l ;
    cin >> n >> l ;

    vector<vector<int>> showtime(n+1) ;
    vector<int> duration(n+1) ;
    for(int movie = 0; movie < n; movie++)
    {
        cin >> duration[movie] ;
        int c ; cin >> c ;
        while(c--)
        {
            int time ; cin >> time ;
            showtime[movie].push_back(time) ;
        }
    }
    showtime[n].push_back(-1) ;
    duration[n] = 1 ;

    pair<int, int> dp[1<<n] ;
    dp[0] = {n, 0} ;
    int ans = 21 ;

    for(int mask = 1; mask < (1<<n); mask++)
    {
        dp[mask] = make_pair(-1, -1) ;
        for(int i = 0; i < n; i++)
        {
            if(mask&(1<<i))
            {
                int movie = dp[mask^(1<<i)].first, show = dp[mask^(1<<i)].second ;
                if(movie == -1)
                    continue ;
                int64 time = showtime[movie][show] + duration[movie] ;
                int lo = 0, hi = showtime[i].size()-1, next = -1 ;
                while(lo <= hi)
                {
                    int mid = lo+(hi-lo)/2 ;
                    if(showtime[i][mid] <= time)
                    {
                        next = mid ;
                        lo = mid+1 ;
                    }
                    else
                        hi = mid-1 ;
                }
                if(next != -1 and showtime[i][next] != showtime[movie][show])
                {
                    if(showtime[i][next]+duration[i] >= showtime[movie][show])
                    {
                        if(dp[mask] == make_pair(-1, -1) or (showtime[dp[mask].first][dp[mask].second] + duration[dp[mask].first] < showtime[i][next]+duration[i]))
                            dp[mask] = make_pair(i, next) ;
                    }
                }
            }
        }
        if(dp[mask].first != -1 and showtime[dp[mask].first][dp[mask].second] + duration[dp[mask].first] >= l)
            ans = min(ans, __builtin_popcount(mask)) ;
    }
    if(ans < 21)
        cout << ans ;
    else
        cout << -1 ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("movie.in", "r", stdin) ;
    freopen("movie.out", "w", stdout) ;

    int test = 1 ;
    // cin >> test ;
    for(int cas = 1; cas <= test; cas++)
    {
        solve() ;
        cout << '\n' ;
    }
    return 0 ;
}


