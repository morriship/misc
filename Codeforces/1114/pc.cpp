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

ll p[500000], plen;

ll bf[500000];

void sieve(int n) {
    int i, ii(2), j;
    p[0] = 2, p[1] = 3;
    plen = 2;
    for (i = 5; i <= n; i += ii, ii ^= 6) {
        for (j = 0; p[j] * p[j] <= i; j++) { if (i % p[j] == 0) { break; } }
        if (i % p[j]) { p[plen++] = i; }
    }
}

ll solve(ll f, ll n) {
    ll ans = 0;
    // cout << f << ' ' << n << endl;
    while (n) {
        ans += n / f;
        n /= f;
    }
    // cout << ans << endl;
    return ans;
}

int main() {
	sieve(1e6 + 100);
    ll i, j, k;
    ll n, b;
    cin >> n >> b;
    ll bb = b;
    rep(i, plen) {
        auto x = p[i];
        while (bb % x == 0) {
            bf[i]++;
            bb /= x;
        }
    }
    ll ans = -1;
    if (bb > 1) {
        ans = solve(bb, n);
    }
    rep(i, plen) {
        if (bf[i]) {
            if (ans == -1) {
                ans = solve(p[i], n) / bf[i];
            } else {
                ans = min(ans, solve(p[i], n) / bf[i]);
            }
        }
    }
    cout << ans << endl;
}
