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
typedef long long ll;
using namespace std;

ll cnt[11];
ll ans;
ll fac[20];

void init() {
    fac[0] = 1;
    for (int i = 1; i < 20; i++) {
        fac[i] = fac[i - 1] * i;
    }
}

void dfs(int now) {
    if (now == -1) {
        ll x0 = cnt[0];
        ll xx = 0;
        for (int i = 1; i <= 9; i++) {
            xx += cnt[i];
        }
        ll tmp = xx * fac[xx-1 + x0];
        for (int i = 0; i <= 9; i++) {
            if (cnt[i] > 1) {
                tmp /= fac[cnt[i]];
            }
        }
        ans += tmp;
        return;
    }
    while (now && cnt[now] <= 1) {
        now--;
    }
    if (cnt[now] >= 1) {
        for (ll tmp = 0; tmp < cnt[now]; tmp++) {
            cnt[now] -= tmp;
            dfs(now - 1);
            cnt[now] += tmp;
        }
    } else {
        dfs(now - 1);
    }
}

int main() {
    init();
    ll n;
    cin >> n;
    while (n) {
        cnt[n % 10]++;
        n /= 10;
    }
    ans = 0;
    dfs(9);
    cout << ans << endl;
}
