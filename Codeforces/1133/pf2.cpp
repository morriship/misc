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


vector<int> edge[200001];

int used[200001];
int low[200001];
int dfn[200001];
int idx = 1;

int n, m, d;

queue<int> que;

void scc(int now, int parent) {
    dfn[now] = idx++;
    int i;
    rep(i, edge[now].size()) {
        int y = edge[now][i];
        if (y == parent) continue;
        if (dfn[y] == 0) {
            scc(y, now);
        }
        else if (dfn[y] < low[now]) {
            low[now] = dfn[y];
        }
    }
}


int main() {
    cin >> n >> m >> d;
    int x, y, i, j;

    rep(i, m) {
        scanf("%d %d", &x, &y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    int now = 1;
    dfn[now] = idx++;
    vector<int> need;
    rep(i, edge[now].size()) {
        int y = edge[now][i];
        if (dfn[y] == 0) {
            scc(y, now);
            need.push_back(y);
        }
    }

    if (need.size() <= d && edge[1].size() >= d) {
        used[1] = 1;
        cout << "YES" << endl;
        rep(i, need.size()) {
            cout << 1 << ' ' << need[i] << endl;
            used[need[i]] = 1;
            que.push(need[i]);
            d--;
        }
        rep(i, edge[now].size()) {
            if (d <= 0) {
                break;
            }
            int y = edge[now][i];
            if (!used[y]) {
                cout << now << ' ' << y << endl;
                used[y] = 1;
                que.push(y);
                d--;
            }
        }
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            rep(i, edge[x].size()) {
                int y = edge[x][i];
                if (!used[y]) {
                    cout << x << ' ' << y << endl;
                    used[y] = 1;
                    que.push(y);
                }
            }
        }
    }
    else {
        cout << "NO" << endl;
    }
}
