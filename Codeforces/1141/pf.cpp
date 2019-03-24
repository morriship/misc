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
#define si set<int>
#define MID 2001
#define pb push_back
typedef long long ll;
using namespace std;

map<int, pii> xmap;
int in[1510];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, i, j;

    cin >> n;
    rep(i, n) {
        cin >> in[i];
        int sum(0);
        for (j = i; j >= 0; j--) {
            sum += in[j];
            if (xmap.count(sum)) {
                if (xmap[sum].second < j) {
                    xmap[sum] = {xmap[sum].first + 1, i};
                }
            } else {
                xmap[sum] = {1, i};
            }
        }
    }
    int cnt(0), ans;
    for (auto iter: xmap) {
        if (iter.second.first > cnt) {
            cnt = iter.second.first;
            ans = iter.first;
        }
    }
    cout << cnt << endl;
    int prev(-1);
    rep(i, n) {
        int sum(0);
        for (j = i; j > prev; j--) {
            sum += in[j];
            if (sum == ans) {
                cout << j + 1 << ' ' << i + 1 << endl;
                prev = i;
                break;
            }
        }
    }
}
