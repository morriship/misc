#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define swap(a,b) ( (a^=b) , (b^=a) , (a^=b) )
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
#define maxL (10000000>>5)+1
#define mod 1000000007
typedef long long ll;
using namespace std;

ll LIMIT = 45;
ll dp[46];

void buildDp() {
    dp[0] = 1;
    ll inc = 2, i;
    for (i = 1; i < LIMIT; i++) {
        dp[i] = dp[i-1] + dp[i-1] + inc;
        inc += inc;
    }
}

int main () {
    buildDp();
    ll n;
    cin >> n;
    ll x, xx;
    ll ans(0);
    --n;
    for (x = 0, xx = 1; xx <= n; xx += xx, x++);
    for (xx >>= 1, x--; n; xx >>= 1, x--) {
        if (xx & n) {
            ans += xx;  
            if (x > 0) { ans += dp[x-1]; }
            n -= xx;
        }
    }
    cout << ans << endl;
}
