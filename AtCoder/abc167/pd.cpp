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
#define mset(x) memset(x, 0, sizeof(x))
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

ll in[200100];
ll dist[200100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    int i;
    memset(dist, 0x3f, sizeof(dist));
    xrep(i, 1, n + 1) cin >> in[i];
    dist[1] = 0;
    ll d(0);
    ll now(1);
    while (1) {
        d++;
        ll next = in[now];
        if (dist[next] < d) {
            ll cyc = d - dist[next];
            k %= cyc;
            ll st = dist[next];
            while (k < st) k += cyc;
            xrep(i, 1, n + 1) if (dist[i] == k) cout << i << endl;
            break;
        }
        else {
            if (d == k) {
                cout << next << endl;
                return 0;
            }
            dist[next] = d;
            now = next;
        }
    }
}
