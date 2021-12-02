// author : sahil sharma

#include<bits/stdc++.h>
using namespace std;

//=============================================CONSTANTS=============================================
const long long SZ = 1e5 + 7;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
const long long PI = 3.1415926535897932384;
//=============================================MACROS=============================================
#define FastIO                  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define kitnalega               long long ___tc=1; cin >> ___tc; while (___tc-- )

#define rep(i,x,y)              for(int i=x;i<y;i++)
#define repr(i,x,y)          for(int i=x-1;i>=y;i--)

#define ll                      long long
#define lli                     long long int

#define ci(X)                   ll X;              cin >> X
#define cii(X, Y)               ll X, Y;           cin >> X >> Y
#define ciii(X, Y, Z)           ll X, Y, Z;        cin >> X >> Y >> Z
#define ciiii(A,X,Y,Z)          ll A,X,Y,Z;        cin >> A >> X >> Y >> Z

#define cs(s)                   string s;           cin>>s;

#define ff                      first
#define ss                      second

#define pb                      push_back
#define pf                      push_front

#define endl                    "\n"
#define nl                      cout<<"\n";
#define sep                     cout<<"-----------------"<<endl;

#define Max(a,b)                ((a > b) ? a : b)
#define Min(a,b)                ((a < b) ? a : b)
#define all(x)                  (x).begin(),(x).end()

typedef vector<int>             vi;
typedef vector<string>          vs;
typedef vector<char>            vc;
typedef vector<vi>              vvi;

typedef vector<ll>              vll;
typedef pair<int, int>          pii;
typedef pair<ll, ll>            pll;
typedef vector<pii>             vpii;
typedef vector<pll>             vpll;
typedef pair<lli, lli>          pll;


//=============================================Functions=============================================

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void google(int t) {cout << "Case #" << t << ": ";}
#define mylb(a,val)             lower_bound(a.begin(),a.end(),val)
#define myub(a,val)             upper_bound(a.begin(),a.end(),val)
//=============================================MAIN CODE=============================================
#define pr cout<<

void code_start2()
{
    pr "Enter how many Grammer you have :";
    ci(n);
    pr n<<"\n";
    vector<pair<string,string>>vvp;
    rep(i,0,n)
    {
        cs(a);
        cs(rule);
        vvp.push_back(make_pair(rule,a));
    }
    pr "\nOur production rules are: \n";
    for(auto i:vvp)
    {
        pr i.second<<" ";
        pr i.first<<"\n";
    }
    
    stack<string>stk;
    deque<char>dq;
    pr "\nEnter Input: ";
    cs(input);
    for(auto i:input){
        dq.push_back(i);
    }
    string ans ="",empty_str="",res="";
    dq.push_back('$');
    for(auto i:dq)
    {
        pr i;
    }
    
    //pr "\n\nElement\t\tstack\t\t\tInput Buffer\t\t\tAction\n";
    pr "\n\nElement\t\tstack\t\tAction\n";
    for(auto i:dq)
    {
        char pick = dq.front();
        string picked = to_string(pick-'0');
        if(picked!="-12")
        {
            pr picked<<"\t\t\t";
        }
        else
        {
            pr "$\t\t\t";
        }
        
        ans+=pick,stk.push(ans);
        
        string element = stk.top();
        reverse(element.begin(),element.end());
        //pr element<<"\t\t\t\t";
        pr element<<"\t";
        //for(auto i:dq)  pr i;
        
        cout<<"\t\t";
        bool check_update = false;
        string new_string ="";
        for(auto j:vvp)
        {
            string empty_string="";
            string pattern=j.first, pattern_change=j.second;
            string element_changer=element;
            if(pattern.size()<=element_changer.size())
            {
                bool check_correct = true;
                for(int k=0;k<pattern.size();k++)
                {
                    if(pattern[k]==element[k])
                    {
                        check_correct=true;
                    }
                    else
                    {
                        check_correct=false;
                        break;
                    }
                }
                if(check_correct)
                {
                    string last ="";
                    empty_string+=pattern_change;
                    for(int k=pattern.size();k<element.size();k++)
                    {
                        empty_string+=element[k];
                    }
                    new_string = empty_string;
                    pr "Reduce "<<pattern<<" by "<<pattern_change<<"";
                    check_update=true;
                }
            }
            cout<<" ";
        }
        if(!check_update)
        {
            pr "Shift";
        }
        else
        {
            ans=empty_str;
            element=new_string;
            reverse(all(element));
            ans+=element;
            res=element;
        }
        dq.pop_front();
        pr "\n";
    }
    nl;
    pr "Last Action: "<<res<<"\n";
    pr "Last Element in Stack: "<<stk.top()<<"\n";

    if(stk.top()[0]=='S' or stk.top()=="S$" or stk.top()=="$S" or res =="S$" or res =="$S")
    {
        pr "Accepted";
    }
    else
    {
        pr "Rejected";
    }
    return;
}

int32_t main()
{
    FastIO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    bool check = false;
    if (check)
    {
        kitnalega
        {
            code_start2();
            nl
        }
    }
    else
    {
        code_start2();
    }

    return 0;
}