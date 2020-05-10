#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) ((a)<<(b))
#define Rshift(a,b) ((a)>>(b))
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define sz(a) int(a.size())
#define mset(x) memset(x, 0, sizeof(x))
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


int c[13];
int in[13][13];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, m, x;
    cin >> n >> m >> x;
    int i, j;
    rep(i, n) {
        cin >> c[i];
        rep(j, m) {
            cin >> in[i][j];
        }
    }
    ll s[m], k;
    ll ans(LINF);
    rep(i, two(n)) {
        ll t(0);
        memset(s, 0, sizeof(s));
        rep(j, n) {
            int tj = two(j);
            if (tj & i) {
                t += c[j];
                rep(k, m) s[k]+=in[j][k];
            }
        }
        rep(j, m) {
            if (s[j] < x) break;
        }
        if (j == m) {
            ans = min(ans, t);
        }
    }
    if (ans == LINF) ans = -1;
    cout << ans << endl;
}
