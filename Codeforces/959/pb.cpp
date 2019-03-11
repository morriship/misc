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

vector<int> cost;
vector<int> parent;
map<string, int> idx;

int getRoot(int index) {
    if (parent[index] == index) { return index; }
    int root = getRoot(parent[index]);
    parent[index] = root;
    return root;
}

int main () {
    int n, k, m, i;
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        idx[s] = i;
    }
    for (int i = 0; i < n; i++) {
        int sc;
        cin >> sc;
        cost.push_back(sc);
        parent.push_back(i);
    }
    rep(i, k) {
        int x, y, z;
        cin >> x;
        cin >> y;
        y--;
        while (--x) {
            cin >> z;
            z--;
            if (cost[z] >= cost[y]) { parent[z] = y; }
            else {
                parent[y] = z; 
                y = z;
            }
        }
    }
    ll ans = 0;
    while(m--) {
        string s;
        cin >> s;
        int index = idx[s];
        int root = getRoot(index);
        ans += cost[root];
    }
    cout << ans << endl;
}
