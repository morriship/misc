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
#define vi vector<int>
#define pii pair<int, int>
#define mii map<int, int>
#define si set<int>
#define pb push_back
typedef long long ll;
using namespace std;


ll a[200100], b[200100], n, k;
ll cnt[200010];

multimap<ll, pair<ll, ll> > xmap;

int can(ll power) {
    ll i, j, quota(k);
    memset(cnt, 0, sizeof(cnt));
    rep(i, n) {
        if (b[i] * k > a[i]) {
            if (power == 0) { return 0; }
            ll need = (b[i] * k - a[i] + (power - 1)) / power;
            quota -= need;
            if (quota < 0) { return 0; }
        }
    }
    rep(i, n) {
        ll addi(0);
        while (a[i] + addi < k * b[i]) {
            cnt[(a[i] + addi) / b[i]]++;
            addi += power;
        }
    }
    ll sum(0);
    rep(i, k + 1) {
        sum += cnt[i] - 1;
        if (sum > 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    ll i, j;
    cin >> n >> k;
    --k;
    rep(i, n) { cin >> a[i]; }
    rep(i, n) { cin >> b[i]; }
    ll now = 1LL << 45;
    ll xx = 1LL << 45;
    while (xx) {
        if (now >= xx && can(now-xx)) {
            now -= xx;
        }
        xx >>= 1;
    }
    if (!can(now)) {
        cout << -1 << endl;
    } else {
        cout << now << endl;
    }
}
