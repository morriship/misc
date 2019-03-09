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
typedef long long ll;
using namespace std;

int in[1101][1001];
int x[1001][1001];
int mx[1001];
int y[1001][1001];
int my[1001];

int main() {
    int n, m, i, j;
    cin >> n >> m;
    rep(i, n) {
        rep(j, m) {
            scanf("%d", &in[i][j]);
        }
    }
    rep(i, n) {
        set<int> t;
        pair<int, int> tt[1011];
        rep(j, m) {
            tt[j] = {in[i][j], j};
            t.insert(in[i][j]);
        }
        sort(tt, tt + m);
        int pre = -1;
        int cnt(0);
        rep(j, m) {
            if (tt[j].first != pre) {
                cnt++;
                pre = tt[j].first;
            }
            x[i][tt[j].second] = cnt;
        }
        mx[i] = t.size();
    }
    rep(i, m) {
        set<int> t;
        pair<int, int> tt[1011];
        rep(j, n) {
            tt[j] = {in[j][i], j};
            t.insert(in[j][i]);
        }
        sort(tt, tt + n);
        int pre = -1;
        int cnt(0);
        rep(j, n) {
            if (tt[j].first != pre) {
                cnt++;
                pre = tt[j].first;
            }
            y[tt[j].second][i] = cnt;
        }
        my[i] = t.size();
    }
    rep(i, n) {
        rep(j, m) {
            int ans = max(my[j] - y[i][j], mx[i] - x[i][j]) + max(y[i][j], x[i][j]);
            cout << ans << ' ';
        }
        cout << endl;
    }
}
