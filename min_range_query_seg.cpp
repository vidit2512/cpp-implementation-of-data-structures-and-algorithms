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

void build(ll left,ll right,ll tree[],ll arr[],ll index)
{
    if(left==right)
    {tree[index]=arr[left]; return;}
    else
    {
        ll mid=(left+right)/2;
        build(left,mid,tree,arr,2*index+1);
        build(mid+1,right,tree,arr,2*index+2);
        tree[index]=min(tree[2*index+1],tree[2*index+2]);
        return;
    }

}
void update(ll left,ll right,ll tree[],ll arr[],ll index,ll ind,ll value)
{
    if(right<ind||left>ind)
    return;

    if(left==right&&left==ind)
    {tree[index]=value;return ;}

    ll mid=(left+right)/2;
    update(left,mid,tree,arr,2*index+1,ind,value);
    update(mid+1,right,tree,arr,2*index+2,ind,value);
    tree[index]=min(tree[2*index+1],tree[2*index+2]);

}
ll ans(ll left,ll right,ll initial,ll final,ll tree[],ll arr[],ll index)
{
    if(left<=initial&&right>=final)
    return tree[index];
    if(right<initial||left>final)
    return INT_MAX;
    
    ll mid=(initial+final)/2;
    return min( ans(left,right,initial,mid,tree,arr,2*index+1) , ans(left,right,mid+1,final,tree,arr,2*index+2) ) ;
}
int main() {
    //   freopen("@input.txt","r",stdin);
    //   freopen("@output.txt","w",stdout);
    ll tc=1;
    //cin>>tc;
    while(tc--)
    {
        ll n;
        cin>>n; ll arr[n];
        cout<<"Enter the given array"<<endl;
        loop(0,n,i)
        cin>>arr[i];
        ll a1=(ll)powl(2,log2(n));
        ll tree[2*a1+4]={0};
        build(0,n-1,tree,arr,0);

        ll q;
        cout<<"enter the total number of queries"<<endl;
        cin>>q;
        cout<<"now enter 3 space separated integers :"<<endl;
        cout<<"0/1 a b:"<<endl;
        cout<<" where 0 a b stands for updation of b integer at ath index of array"<<endl;
        cout<<" where 1 a b stands for min range query between a and b inclusive"<<endl;
        loop(0,q,i)
        {
            ll a11,a2,a3;
            cin>>a11>>a2>>a3;
            if(a11==0)
            update(0,n-1,tree,arr,0,a2-1,a3);
            else
            {
                cout<<ans(a2-1,a3-1,0,n-1,tree,arr,0)<<endl;
            }
            // cout<<"tree is"<<endl;
            // loop(0,2*a1+4,i)
            // cout<<tree[i]<<" ";

            // cout<<endl;
            
        }

    //  cout<<n<<endl;
        
    }
	// your code goes here
	return 0;
}
