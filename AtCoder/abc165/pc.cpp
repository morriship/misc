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

int r[10];
int n, m, q;
int qq[55][4];
ll ans(0);

void go(int idx, int cnt) {
    if (idx == n) {
        ll t(0);
        int i;
        rep(i, q) {
            if (r[qq[i][1]-1]-r[qq[i][0]-1]==qq[i][2]) {
                t += qq[i][3];
            }
        }
        ans = max(ans, t);
        return;
    }
    int i;
    xrep(i, cnt, m + 1) {
        r[idx] = i;
        go(idx+1, i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> q;
    int i;
    rep(i, q) {
        int j;
        rep(j, 4) cin >> qq[i][j];
    }
    go(0, 1);
    cout << ans << endl;
}
