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
ll dx[]={0, 1, 0, -1};
ll dy[]={1, 0, -1, 0};// right, down, left, up


class Solution {
private:
    vector<vector<int> > ans;
public:
    bool canMoveCell(ll x, ll y, ll di){
        x += dx[di];
        y += dy[di];
        if(x < 0 or x >= ans.size()) return false;
        if(y < 0 or y >= ans[0].size()) return false;
        if(ans[x][y] != 0) return false;
        return true;
    }
    vector<vector<int> > generateMatrix(int n) {
        ans.resize(n, vector<int>(n, 0));
        ll x = 0;
        ll y = 0;
        ll di = 0;

        rep(i, n * n){
            ans[x][y] = i + 1;
            if(!canMoveCell(x, y, di)){
                di ++;
                di %= 4;
            }
            x += dx[di];
            y += dy[di];
        }

        return ans;
    }
};
