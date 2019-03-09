/********************************************************
*                   Wrong answer                        *
*********************************************************/

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

int dist[110][110];
pair<int, int> status[5010][4];


void solve(int caseID) {
    int i, j, k, n, m, fn, a, b, g;
    memset(dist, 0x2f, sizeof(dist));
    vector<pair<int, int> > fs;

    cin >> n >> m >> fn;
    rep(i, m) {
        cin >> a >> b >> g;
        a--,b--;
        if (g < dist[a][b]) { dist[a][b] = dist[b][a] = g; }
    }
    rep(i, n) { dist[i][i] = 0; }
    rep(i, n) rep(j, n) rep(k, n) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
        }
    }

    rep(i, fn) {
        int s, d;
        cin >> s >> d;
        s--,d--;
        fs.push_back({s, d});
    }
    fs.push_back(fs.back());  // prevent re

    for (auto f: fs) {
        if (dist[f.first][f.second] > INF) {
            cout << "Case #" << caseID << ": -1" << endl;
            return;
        }
    }
    rep(i, n + 1) rep(j, 4) { status[i][j] = {INF, 0}; }
    status[0][0] = {0, 0};
    rep(i, fn) {
        auto f = fs[i];
        auto nf = fs[i + 1];

        int oneFam = status[i][0].first + dist[status[i][1].second][f.first];
        if (oneFam < INF) { status[i][2] = {oneFam, f.first}; }

        int twoFam = min(status[i][1].first + dist[status[i][1].second][nf.first],
                         status[i][2].first + dist[status[i][2].second][nf.first]);
        if (twoFam < INF) { status[i][3] = {twoFam, nf.first}; }

        int nextDist = min(status[i][1].first + dist[status[i][1].second][f.second],
                           status[i][2].first + dist[status[i][2].second][f.second]);
        if (nextDist < INF) { status[i + 1][0] = {nextDist, f.second}; }

        int nextOneFam = status[i][3].first + dist[status[i][3].second][f.second];
        if (nextOneFam < INF) { status[i + 1][1] = {nextOneFam, f.second}; }
    }
    cout << "Case #" << caseID << ": " << status[fn][0].first << endl;
}

int main() {
    int t, tt;
    cin >> t;
    for (tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
