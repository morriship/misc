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


char ina[151000], inb[151000];
vector<int> chb[30];
int idxb[30];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, i, j;
    cin >> n;
    cin >> ina >> inb;
    rep(i, n) {
        if (inb[i] != '?') {
            chb[inb[i] - 'a'].pb(i + 1);
        } else {
            chb[26].pb(i + 1);
        }
    }
    vi rest;
    vi ques;
    vector<pii> ans;
    rep(i, n) {
        if (ina[i] == '?') {
            ques.pb(i + 1);
        } else {
            int idx = ina[i] - 'a';
            // cout << idx << ' ' << idxb[idx] << ' ' << chb[idx].size() << endl;
            if (idxb[idx] < chb[idx].size()) {
                // cout << i + 1 << ' ' << chb[idx][idxb[idx]] << endl;
                ans.pb({i + 1, chb[idx][idxb[idx]++]});
                // cout << i + 1 << ' ' << chb[idx][idxb[idx]++] << endl;
            } else {
                rest.pb(i + 1);
            }
        }
    }
    rep(i, min(chb[26].size(), rest.size())) {
        ans.pb({rest[i], chb[26][i]});
        // cout << rest[i] << ' ' << chb[26][i] << endl;
    }
    idxb[26] = min(chb[26].size(), rest.size());
    int now = 0;
    rep(j, ques.size()) {
        while (now < 27) {
            if (idxb[now] < chb[now].size()) {
                break;
            }
            now++;
        }
        if (now >= 27) { break; }
        ans.pb({ques[j], chb[now][idxb[now]++]});
    }
    cout << ans.size() << endl;
    rep(i, ans.size()) {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
}
