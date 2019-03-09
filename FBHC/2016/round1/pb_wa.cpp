#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define readi(a) scanf("%d", &a)
#define swap(a,b) ( (a^=b) , (b^=a) , (a^=b) )
#define min(a,b) ( a < b ? a : b )
#define max(a,b) ( a > b ? a : b )
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
#define maxL (10000000>>5)+1
#define mod 1000000007
typedef long long ll;
using namespace std;

multimap<ll, ll> w;
multiset<ll> dryer;
ll wait[1000010];

int main() {
    int t, tt, i;
    ll l, n, m, d, in;
    ll ans;
    readi(tt);
    xrep(t, 1, tt+1) {
        scanf("%lld%lld%lld%lld", &l, &n, &m, &d);
        w.clear();
        ans = 0;
        rep(i, n) {
            scanf("%lld", &in);
            w.insert({in, in});
        }
        rep(i, l) {
            auto it = w.begin();
            wait[i] = it->first;
            w.insert({it->first + it->second, it->second});
            w.erase(it);
        }
        rep(i, min(l, m)) { dryer.insert(0); }
        rep(i, l) {
            auto it = dryer.begin();
            auto val = max(*it, wait[i]) + d;
            dryer.erase(it);
            dryer.insert(val);
            ans = max(ans, val);
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}
