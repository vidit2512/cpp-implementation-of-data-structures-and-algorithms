#include <bits/stdc++.h>
#define ll               long long int
#define loop(a,b,i)      for(ll i=a;i<b;i++)
#define loop1(a,b,i)     for(ll i=a;i>b;i--)
using namespace std;

ll find_pivot(ll arr[],ll i,ll j,ll &ans)
{
    if(i>j) return -1;

    if(i==j)
    {
        if(arr[0]>arr[j])
    {
        ans=j;
        return 0;
    }
    else return -1;
    }
     if(arr[0]==arr[j])
    return -1;

    if(arr[0]<arr[j])
    {
        return -1;
    }
    else
    {
        ans=j;
       if(find_pivot(arr,i,(i+j)/2,ans)==-1)
        find_pivot(arr,(i+j)/2+1,j,ans);
        return 0;
    }
    
}// to find pivot from which array is rotated.
ll bin(ll arr[],ll i,ll j,ll key,ll &pos)
{
    ll mid=(i+j)/2;
    if(i>j) return -1;
    if(arr[mid]==key) {pos=mid;return 0;}
    if(arr[mid]<key)
    bin(arr,mid+1,j,key,pos);

    else  bin(arr,i,mid-1,key,pos);
    return -1;
    

}//recursive function for binary search

int main()
{
    freopen("@input.txt","r",stdin);
    ll n;
    cin>>n;
    ll arr[n];
    loop(0,n,i)
    cin>>arr[i];
    ll key;
    cin>>key;
ll pivot=-1;

find_pivot(arr,0,n-1,pivot);
ll pos=-1;

if(arr[n-1]>=key)
{ 
bin(arr,pivot,n-1,key,pos);
}
else  bin(arr,0,pivot-1,key,pos);

if(pos==-1)
cout<<"Element is not present "<<endl;
else
{
    cout<<"Element is present at "<<pos+1 <<" position"<<endl;
}

    return 0;
}
//time complexity O(n) , auxiliary space O(1).