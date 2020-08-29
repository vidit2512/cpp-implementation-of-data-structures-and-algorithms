/*author : vidit shukla
           (valiant_vidit)*/
#include <bits/stdc++.h>
#define ll               long long int
#define loop(a,b,i)      for(ll i=a;i<b;i++)
#define loop1(a,b,i)     for(ll i=a;i>b;i--)
#define endl              '\n'
using namespace std;
const ll mod = 1000000000+7;


ll [] sqrt_decompose(ll arr[],ll n,ll q,ll r)
{
   
    ll brr[q+1];ll h=0;
    loop(0,q+1,i)
    brr[i]=1e18;
    loop(0,n,i)
    {
        if(i+1%q==0)
        h++;
        brr[h]=min(brr[h],arr[i]);
    }
    return brr;
}


int main() {
     
    
        ll n;
        cin>>n; ll arr[n];
        loop(0,n,i)
        cin>>arr[i];
         
         ll a1=(ll)sqrt(n);
         ll q=n/a1;
         ll r=n%a1;
        
        ll brr[q+1];

        brr=sqrt_decompose(arr,n,q,r);
        ll query;
        cout<<"enter the total number of queries"<<endl;
        cin>>query;
        cout<<"enter 2 numbers a and b to calculate minimum number in the range a and b inclusive "<<endl;

        loop(0,query,i)
        {
            ll a,b;
            cin>>a>>b;

            ll pre=a/a1;
            ll next=b/a1;
            ll ans=1e18;
           loop(pre-1,next,i)
           {
               ans=min(ans,brr[i]);
           }
           ll a12=a%a1;
           ll b12=b%a1;
           
           loop1(pre-1,pre-a12-1,i)
           ans=min(ans,arr[i]);

            loop1(next-1,next-b12-1,i)
           ans=min(ans,arr[i]);

           cout<<ans<<endl;

        }

    //  cout<<n<<endl;
        
	// your code goes here
	return 0;
}
