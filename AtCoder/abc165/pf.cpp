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

vector<ll> edge[200100];
ll in[200100];
int used[200100];
vector<ll> lis;
ll ans[200100];

void go(int x) {
    int y, i;
    used[x] = 1;
    ll st(0), ed(sz(lis));
    while (st != ed) {
        ll mi = (st + ed) / 2;
        if (lis[mi] >= in[x]) {
            ed = mi;
        } else {
            st = mi + 1;
        }
    }
    ll prev(-1);
    if (st == sz(lis)) {
        lis.pb(in[x]);
    } else {
        prev = lis[st];
        lis[st] = in[x];
    }
    ans[x] = sz(lis);
    rep(i, sz(edge[x])) {
        y = edge[x][i];
        if (used[y]) continue;
        go(y);
    }
    if (prev == -1) {
        lis.pop_back();
    } else {
        lis[st] = prev;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    int i;
    cin >> n;
    rep(i, n) cin >> in[i+1];
    rep(i, n-1) {
        ll x, y;
        cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
    go(1);
    xrep(i, 1, n + 1) {
        cout << ans[i] << endl;
    }
}
