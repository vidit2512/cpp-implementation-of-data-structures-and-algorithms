#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void rotate1(ll arr[],ll d,ll n)
{
    ll brr[n];
    for(ll i=0;i<n;i++)
    {
        brr[(i-d+n)%n]=arr[i];
    }
    for(ll i=0;i<n;i++)
    arr[i]=brr[i];
}//time complexity O(n) ,auxiliary space O(n)
void rotate2(ll arr[],ll d,ll n)
{
    d=d%n;
    ll temp=arr[0];ll ind=0;ll e=0;ll tmp2;
    ll hcf=__gcd(d,n);ll pk=0;
    while(pk<hcf)
    {
        ind=pk,e=0;temp=arr[ind];
    while(true)
    {
     
    ll  ind1=ind;
        ind=(ind-d+n)%n;
   
       tmp2=temp;
       temp=arr[ind];
       arr[ind]=tmp2;
    
         if(ind==pk)
         break;
         e=1;
    }
    pk++;
    }
}//time complexity O(n) ,auxiliary space O(1) (implementation of juggling algo) :)

void rotate3(ll arr[],ll d,ll n)
{
    ll brr[d];
    for(ll i=0;i<d;i++)brr[i]=arr[i];
    for(ll i=d;i<n;i++)
    {
        arr[(i-d+n)%n]=arr[i];
    }
    for(ll i=n-d;i<n;i++)
    arr[i]=brr[i-n+d];
}//time complexity O(n) , auxiliary space O(d)
void rotate4(ll arr[],ll d,ll n)
{
    ll brr[1];ll dd=1;
    while(dd<=d)
    {
     for(ll i=0;i<1;i++)brr[i]=arr[i];
    for(ll i=1;i<n;i++)
    {
       
        arr[(i-1+n)%n]=arr[i];
    }
    for(ll i=n-1;i<n;i++)
    arr[i]=brr[i-n+1];
    dd++;
    }
}//time complexity O(n*d) ,auxiliary space O(1)
void reverse(ll arr[],ll a,ll b)
{
    ll i=a,j=b;
    while(i<j)
    {
        ll temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;j--;
    }
}
void rotate5(ll arr[],ll d,ll n)
{
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}//time complexity O(n), auxiliary space O(1)
void swapp(ll arr[],ll s1,ll s2,ll d)
{
    for(ll i=0;i<d;i++)
    {
        ll tmp=arr[i+s1];
        arr[i+s1]=arr[s2+i];
        arr[s2+i]=tmp;
    }
}
void rotate6_recursive(ll arr[],ll d,ll n)
{
    if(d<n-d)
    {
        swapp(arr,0,n-d,d);
        rotate6_recursive(arr,d,n-d);
    }
   else if(d==n-d)
    {
        swapp(arr,0,n-d,d);
    }
    else
    {
        swapp(arr,0,n-d,n-d);
        rotate6_recursive(arr+n-d,2*d-n,d);
    }
}//time complexity O(n), auxiliary space O(1)
void rotate6_iterative(ll arr[],ll d,ll n)
{
    ll s1=0,s2=n-d;ll j=0;
    while(n!=0)
    {
        s1=0,s2=n-d;
        if(d==n-d)
        {
            
             for(ll i=j;i<d;i++)
           {
            ll tmp=arr[i+s1];
            arr[i+s1]=arr[s2+i];
            arr[s2+i]=tmp;
           }
            break;
        }
        else if(d<n-d)
        {

            for(ll i=j;i<d;i++)
            {
                 ll tmp=arr[i+s1];
                 arr[i+s1]=arr[s2+i];
                 arr[s2+i]=tmp;
            }
            n=n-d;
        }
        else
        {
            
            for(ll i=j;i<n-d;i++)
            {
                 ll tmp=arr[i+s1];
                 arr[i+s1]=arr[s2+i];
                 arr[s2+i]=tmp;
            }
            ll d1=d;
            j=n-d;d=2*d-n;n=d1;

        }
        
    }
}//time complexity O(n), auxiliary space O(1)

int main()
{
   // freopen("@input.txt","r",stdin);
    ll n,d;
cin>>n;
ll arr[n];
for(ll i=0;i<n;i++)
cin>>arr[i];
cin>>d;
rotate6_iterative(arr,d,n);
for(ll i=0;i<n;i++)
cout<<arr[i]<<" ";
cout<<endl;

    
}
