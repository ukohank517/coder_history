#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <complex> // complex<double> a(1.2 , 2.3);// real(): 1.2, imag()2.3
using namespace std;

#define MOD 1000000007
#define EPS 1e-10
#define ll long long
#define ld long double
#define FOR(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rmsame(a) sort(all(a)),a.erase(unique(all(a)), a.end())
#define rmvector(a,b) rep(i,a.size())rep(j,b.size())if(a[i]==b[j]){a.erase(a.begin()+i);i--;break;}
#define first_more_idx(ve, num) upper_bound(all(ve), num)-ve.begin() // idx = first_more_idx(ve,num); if(idx = ve.size()) , then not exist
#define first_lessequal_idx(ve, num) lower_bound(all(ve), num)-ve.begin()
#define pq_pair_tB priority_queue <pair<ll,ll>, vector<pair<ll,ll> > , greater<pair<ll,ll> > >
#define pq_pair_ts priority_queue <pair<ll,ll> > // only sort first param
template<typename X> bool exist(vector<X> vec, X item){return find(all(vec), item)!=vec.end();}
ll gcd(ll a, ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
ll power(ll x, ll n){if(n == 0) return 1;return  (n%2)? x*power(x, n-1)%MOD : power(x*x%MOD, n/2);}
ll dx[]={0, 0, -1, 1};
ll dy[]={1, -1, 0, 0};// up,down,left right

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        rep(i, S.size()){
            if('A' <= S[i] and S[i] <= 'Z') S[i] -= 'A' - 'a';
        }
        vector<string> ans;

        if(S.size() == 0) {
            ans.pb("");
            return ans;
        }

        string now = "";
        rep(i, S.size()){
            if('a' <= S[i] and S[i] <= 'z') break;
            now += S[i];
        }

        if(now.size() == S.size()){
            ans.pb(now);
            return ans;
        }

        vector<string> R = letterCasePermutation(S.substr(now.size() + 1));

        rep(i, R.size()){
            char smallch = S[now.size()];
            char bigch = smallch + ('A' - 'a');
            ans.pb(now + smallch + R[i]);
            ans.pb(now + bigch + R[i]);
        }
        return ans;
    }
};