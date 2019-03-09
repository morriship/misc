#include <bits/stdc++.h>
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

void solve(int caseID) {
    int ans(0);
    int i, j, k, l, n, z;
    ll x[51], y[51], r;
    cin >> n >> r;
    rep(i, n) { cin >> x[i] >> y[i]; }
    rep(i, n) rep(j, n) rep(k, n) rep(l, n) {
        int num(0);
        rep(z, n) {
            ll zx(x[z]), zy(y[z]);
            if ((zx >= x[i] && zx <= x[i] + r && zy >= y[j] && zy <= y[j] + r) ||
                    (zx >= x[k] && zx <= x[k] + r && zy >= y[l] && zy <= y[l] + r)) {
                ++num;
            }
        }
        ans = max(ans, num);
    }
    cout << "Case #" << caseID << ": " << ans << endl;
}

int main() {
    int t, tt;
    cin >> t;
    for (tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
