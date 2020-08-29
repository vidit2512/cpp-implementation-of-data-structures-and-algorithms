/*author : vidit shukla
           (valiant_vidit)*/
#include <bits/stdc++.h>
#define ll               long long int
#define loop(a,b,i)      for(ll i=a;i<b;i++)
#define loop1(a,b,i)     for(ll i=a;i>b;i--)
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
#define endl              '\n'
#define fix(f,n) std::fixed<<std::setprecision(n)<<f
const double pi = std::acos(-1);
using namespace std;
const ll mod = 1000000000+7;

ll power(ll x,ll y,ll md)  
{ll res=1;x=x%md;if(x==0)return 0;while(y>0){if(y&1)res=(res*x)%md;y=y>>1;x=(x*x)%md;}return res;} 

ll m_mul(ll a, ll b){a=a%mod;b=b%mod;return (a*b+mod)%mod;}
ll m_add(ll a,ll b){a=a%mod; b=b%mod;return (a+b+mod)%mod;}

ll spf[(ll)1e7+2]={0};
void siv()
{
spf[1]=1;
loop(1,1e7+2,i)
spf[i]=i;

loop(2,1e7+2,i)
spf[i]=2,i++;
for(ll i=3;i*i<(ll)1e7+2;i++)
{  
   if( spf[i]==i)
    for(ll j=i*i;j<(ll)1e7+2;j=j+i)
    if(spf[j]==j)spf[j]=i;
}

}
void sparse(ll dp[][5],ll arr[],ll n)
{
    if(i+(ll)powl(2,j))
    if(j==0)
    dp[i][j]=arr[i];
    else
    dp[i][j]=min(dp[i][j-1],dp[i+1][j]);
    
}
int main() {
      // freopen("@iin.txt","r",stdin);
      // freopen("@output.txt","w",stdout);
    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll n=9;
        ll arr[]={7, 2, 3, 0, 5, 10, 3, 12, 18};

        ll dp[n][5]={0};
        sparse(dp,arr,n);


    //  cout<<n<<endl;
        
    }
	// your code goes here
	return 0;
}
