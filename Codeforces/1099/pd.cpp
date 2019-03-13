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
#define pb push_back
typedef long long ll;
using namespace std;


int p[100010];
int s[100010];
int a[100010];
int tmp[100010];
int used[100010];

vi edge[100010];
vi topo;
queue<int> q;


int check(int now, int sum) {
    if (s[now] != -1) {
        if (s[now] < sum) {
            return 0;
        }
        sum = s[now];
    }
    for (auto v : edge[now]) {
        if (!check(v, sum)) {
            return 0;
        }
    }
    return 1;
}

void build_topo(int now) {
    for (auto v : edge[now]) {
        build_topo(v);
    }
    topo.pb(now);
}

void dfs(int x) {
    if (s[x] == -1) {
        s[x] = tmp[x];
    }
    s[x] = max(s[x], s[p[x]]);
    int now = s[x];
    a[x] = now - s[p[x]];
    for (auto y : edge[x]) {
        dfs(y);
    }
}

int main() {
    int n, i, j;
    memset(tmp, -1, sizeof(tmp));
    cin >> n;
    rep(i, n - 1) {
        int x(i + 2), y;
        scanf("%d", &y);
        p[x] = y;
        edge[y].pb(x);
    }
    rep(i, n) {
        scanf("%d", &s[i + 1]);
    }
    if (!check(1, 0)) {
        cout << -1 << endl;
        return 0;
    }
    build_topo(1);
    for (auto x : topo) {
        int now = s[x];
        if (now == -1) { now = tmp[x]; }
        int y = p[x];
        if (now != -1 && s[y] == -1) {
            if (tmp[y] == -1) {
                tmp[y] = now;
            } else {
                tmp[y] = min(now, tmp[y]);
            }
        }
    }
    s[0] = 0;
    tmp[0] = 0;
    dfs(1);
    ll ans(0);
    rep(i, n + 1) {
        ans += a[i];
    }
    cout << ans << endl;
}
