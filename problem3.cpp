#include<bits/stdc++.h>
#include<algorithm>
typedef unsigned long long int ll;
using namespace std;

bool findPrimes(ll n, bool primes[]){
    primes[0] = primes[1] = false;
    for (ll i=2; i<=n; i++)
        primes[i] = true;
    for (ll i=2; i*i<=n; i++){
        if (primes[i] == true){
            for (ll j=i*i; j<=n; j += i)
                primes[j] = false;
        }
    }
}

int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        bool primes[n+1];
        findPrimes(n, primes);
        bool found=false;
        for (ll i=0; i<n; i++){
            if (primes[i] && primes[n-i]){
                if(i == (n-i))
                    cout<<"impossible\n";
                else
                    cout << i << " " <<n-i<<endl;
                found = true;
                break;
            }
        }
        if(!found)
            cout<<"impossible\n";
    }
}
