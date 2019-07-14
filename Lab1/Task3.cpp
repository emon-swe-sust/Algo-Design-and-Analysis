#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long k;
    cin >> k;
    double a=0.6,m=100003,hash_k;
    hash_k = floor(m*(k*a-floor(k*a)));
    cout << hash_k << endl ;
    return 0;
}
