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
#define MID 2001
#define pb push_back
typedef long long ll;
using namespace std;

ll in[200100], sum[200100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll h, n;
    ll i, j;
    cin >> h >> n;
    rep(i, n) { cin >> in[i]; }
    ll total(0);
    sum[0] = in[0];
    xrep(i, 1, n) { sum[i] = sum[i-1] + in[i]; }
    rep(i, n) {
        total += in[i];
        if (h + total <= 0) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    if (total >= 0) {
        cout << -1 << endl;
        return 0;
    }
    ll ans(h * n + 1);
    rep(i, n) {
        ans = min(ans, i + 1 + (h + sum[i] + -total - 1) / -total * n);
    }
    cout << ans << endl;
}
