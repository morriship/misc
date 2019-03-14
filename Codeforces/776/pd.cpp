// 2-sat
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


int used[100010];
int w[100010];
int id[200010];
int door[100010];
vi sw[100010];
vi edge[200010];


void dfs(int x, int cnt) {
    id[x] = cnt;
    int y;
    for (auto y: edge[x]) {
        if (!id[y]) {
            dfs(y, cnt);
        }
    }
}

int main() {
    int n, m, i, j, k;
    cin >> n >> m;
    xrep(i, 1, n + 1) {
        cin >> door[i];
    }
    xrep(i, 1, m + 1) {
        int num, y;
        cin >> num;
        rep(j, num) {
            cin >> y;
            sw[y].pb(i);
        }
    }
    xrep(i, 1, n + 1) {
        int x, y;
        rep(j, sw[i].size()) xrep(k, j + 1, sw[i].size()) {
            if (door[i] == 0) {
                edge[sw[i][j]].pb(sw[i][k] + m);
                edge[sw[i][k]].pb(sw[i][j] + m);
                edge[sw[i][j] + m].pb(sw[i][k]);
                edge[sw[i][k] + m].pb(sw[i][j]);
            } else {
                edge[sw[i][j]].pb(sw[i][k]);
                edge[sw[i][k]].pb(sw[i][j]);
                edge[sw[i][j] + m].pb(sw[i][k] + m);
                edge[sw[i][k] + m].pb(sw[i][j] + m);
            }
        }
    }
    // xrep(i, 1, m + m + 1) {
    //     cout << i << ": ";
    //     rep(j, edge[i].size()) {
    //         cout << edge[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    int cnt(1);
    xrep(i, 1, m + m + 1) {
        if (!id[i]) {
            dfs(i, cnt++);
        }
    }
    xrep(i, 1, m + 1) {
        if (id[i] == id[i + m]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}
