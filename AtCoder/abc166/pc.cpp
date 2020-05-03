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

ll h[202000];
vector<ll> edge[200100];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int i;
    xrep(i, 1, n+1) cin >> h[i];
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
    int ans(0);
    xrep(i, 1, n+1) {
        int j;
        rep(j, sz(edge[i])) {
            int y = edge[i][j];
            if (h[y] >= h[i]) break;
        }
        if (j == sz(edge[i])) {
            ans++;
        }
    }
    cout << ans << endl;
}
