#include <iostream>
#include <fstream>
#include <sstream>
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

vector<vector<ll> > inp;

void readValue(){
    // read inp.txt and set to inp
    ifstream infile("inp.txt");
    if(!infile){
        cerr << "file not found" << endl;
        return;
    }
    string line;
    while(getline(infile, line)){
        istringstream ss(line);
        vector<ll> tmp;
        ll num;

        while(ss >> num){
            tmp.pb(num);
        }
        inp.pb(tmp);
    }
    infile.close();


    cout << "the first value is: ";
    rep(i, inp[0].size()) cout << inp[0][i]<< ", "; cout << endl;
    cout << "the last value is: ";
    rep(i, inp[inp.size() - 1].size()) cout << inp[inp.size() - 1][i]<< ", "; cout << endl;

    cout << "-------" << endl;
}

bool isSafe(vector<ll>& inp){
    bool up = false, down = false, same = false;
    ll diff = 0;
    rep(j, inp.size() - 1){
        diff = max(diff, abs(inp[j] - inp[j + 1]));
        if(inp[j] == inp[j + 1]){
            same = true;
            break;
        }else if(inp[j] < inp[j + 1]){
            up = true;
        }else{
            down = true;
        }
    }

    if((up && down) || (!up && !down) || same || diff > 3) return false;
    return true;
}

ll solve1(){
    ll ans = 0;

    rep(i, inp.size()){
        if(isSafe(inp[i]))
        ans ++;
    }
    return ans;
}

ll solve2(){
    ll ans = 0;

    rep(i, inp.size()){
        if(isSafe(inp[i])){
            ans ++;
            continue;
        }
        rep(j, inp[i].size()){
            vector<ll> tmp;
            rep(k, inp[i].size()){
                if(k == j) continue;
                tmp.pb(inp[i][k]);
            }
            if(isSafe(tmp)){
                ans ++;
                break;
            }
        }
    }

    return ans;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    readValue();

    cout << "solve1: " << solve1() << endl;
    cout << "solve2: " << solve2() << endl;


    //cout << fixed << setprecision(16) << ans << endl;
    return 0;
}
