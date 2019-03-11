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
typedef long long ll;
using namespace std;


int in[300100];
vi edge[300100];

int main() {
    int n, m, i, j;
    cin >> n >> m;
    rep(i, n) {
        scanf("%d", &in[i]);
    }
    int x, y;
    set<int> can;
    rep(i, m) {
        scanf("%d %d", &x, &y);
        edge[y].push_back(x);
        if (y == in[n - 1]) {
            can.insert(x);
        }
    }
    int ans(0);
    for (i = n - 2; i >= 0; i--) {
        int x = in[i];
        if (can.find(x) != can.end()) {
            ans++;
        } else {
            set<int> ncan;
            for (auto y: edge[x]) {
                if (can.find(y) != can.end()) {
                    ncan.insert(y);
                }
            }
            can = ncan;
        }
    }
    cout << ans << endl;
}
