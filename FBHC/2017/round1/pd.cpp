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
int mark[1000];
typedef long long ll;
using namespace std;

ll r[2001];
ll prime[500], plen(0);
ll nump[2001][500];
ll nums[2001];
ll tp[2001][500];

void sieveOfEratosthenes(int n) {
    register int i, j, k;
    SET(1);
    for (i = 2; i <= n; i++) {
        if (!GET(i)) {
            prime[plen++] = i;
            for (k = n/i, j = i*k; k >= i; k--, j -= i) { SET(j); }
        }
    }
}

void init() {
	sieveOfEratosthenes(2000);
    memset(nump, 0, sizeof(nump));
    memset(nums, 0, sizeof(nums));
    int i, j;
    xrep(i, 2, 2001) {
        int tmp(i), index(0);
        while (tmp > 1) {
            while (tmp % prime[index] == 0) {
                nump[i][index]++;
                tmp /= prime[index];
                nums[i]++;
            }
            index++;
        }
        nums[i] += nums[i - 1];
        rep(j, plen) { nump[i][j] += nump[i - 1][j]; }
    }
}

void solve(int caseID) {
    int i, j, n, a;
    ll k;
    ll m;
    map<ll, ll> xmap;
    cin >> n >> m;
    rep(i, n) { cin >> r[i]; }
    if (n == 1) {
        cout << "Case #" << caseID << ": " << m << endl;
        return;
    }
    ll ans(0);
    ll sum(0);
    rep(i, n) { sum += r[i]; }
    sum *= 2;
    rep(i, n - 1) xrep(j, i + 1, n) {
        ll tmp(m - (sum + 1 - r[i] - r[j]) + n);
        ll preCal = xmap[tmp];
        // cout << "tn: " << tmp << ' ' << n << endl;
        // cout << tmp << endl;
        if (tmp <= 0) { continue; }
        else if (preCal != 0) { ans = (ans + preCal) % mod; }
        else {
            memcpy(&tp[n], &nump[n], sizeof(nump[n]));
            int tps(nums[n]);
            ll multi(1);
            for (k = tmp; k > tmp - n; k--) {
                ll kk = k;
                // cout << kk << endl;
                for (a = 0; tps && a < plen; a++) {
                    while (tps && tp[n][a] && kk % prime[a] == 0) {
                        --tps;
                        --tp[n][a];
                        kk /= prime[a];
                    }
                }
                multi = multi * kk % mod;
                // cout << "multi: " << multi << ' ' << kk << endl;
            }
            for (k = 2; k < n - 1; k++) {
                ll kk = k;
                // cout << kk << endl;
                for (a = 0; tps && a < plen; a++) {
                    while (tps && tp[n][a] && kk % prime[a] == 0) {
                        --tps;
                        --tp[n][a];
                        kk /= prime[a];
                    }
                }
                multi = multi * kk % mod;

            }
            xmap[tmp] = multi;
// cout << "multi: " << multi << endl;
            // cout << multi << endl;
            ans = (ans + multi) % mod;
        }
    }
    ans = (ans + ans) % mod;
    cout << "Case #" << caseID << ": " << ans << endl;
}

int main() {
    init();
    int t, tt;
    cin >> t;
    for (tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
