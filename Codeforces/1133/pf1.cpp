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

queue<int> que;

int main() {
    int n, m, i, j;
    cin >> n >> m;
    int x, y;
    rep(i, m) {
        scanf("%d %d", &x, &y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    int start = 0;
    int cnt = 0;
    rep(i, n + 1) {
        if (edge[i].size() > cnt) {
            cnt = edge[i].size();
            start = i;
        }
    }

    used[start] = 1;
    que.push(start);

    while (!que.empty()) {
        int now = que.front();
        que.pop();
        rep(i, edge[now].size()) {
            int x = edge[now][i];
            if (!used[x]) {
                used[x] = 1;
                cout << now << ' ' << x << endl;
                que.push(x);
            }
        }
    }
}
