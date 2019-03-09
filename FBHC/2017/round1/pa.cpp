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

int square[350];

void init() {
    int i;
    rep(i, 350) { square[i] = i * i; }
}

void solve(int caseID) {
    int n, m, i, j, k;
    ll sum[350], tmp[350];
    ll cost[350];
    memset(sum, 0x2F, sizeof(sum));
    sum[0] = 0;

    cin >> n >> m;
    rep(i, n) {
        xrep(j, 1, m + 1) {
            cin >> cost[j];
        }
        memset(tmp, 0x2F, sizeof(tmp));
        sort(cost + 1, cost + m + 1);
        int now = 0;
        xrep(j, 1, m + 1) {
            now += cost[j];
            xrep(k, i + j, n + 1) {
                tmp[k] = min(tmp[k], sum[k - j] + now + square[j]);
            }
        }
        rep(j, n + 1) { sum[j] = min(sum[j], tmp[j]); }
        // rep(j, n + 1) cout << sum[j] << ' ';
        // cout << endl;
    }
    cout << "Case #" << caseID << ": " << sum[n] << endl;
}

int main() {
    init();
    int t, tt;
    cin >> t;
    for (tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
