#include <bits/stdc++.h>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <fstream>
#include <typeinfo>
#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define I insert
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define repi(i, a, b) for (ll i = a; i < b; i++)
#define repj(j, a, b) for (ll j = a; j < b; j++)
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define mod 1000000007
#define lim 100001
#define pi 3.14159265

using namespace std;
ll factorial(ll n) { return (n == 1 || n == 0) ? 1 : n * factorial(n - 1); }
int max3(int a, int b, int c) { return max(a, max(c, b)); }
int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    else
    {
        return gcd(b % a, a);
    }
}
ll power(ll a, ll n)
{
    if (n == 1)
        return a;
    else if (n == 0)
        return 1;
    else
    {
        ll r = power(a, n / 2);
        if (n % 2 == 0)
            return r * r;
        else
            return r * a * r;
    }
}
ll nCr(ll n, ll r) { return ((factorial(n)) / (factorial(n - r) * factorial(r))); }
void dfs(vector<vector<int>> &v, vi &check, int start)
{
    check[start - 1] = 1;
    repj(j, 0, v[start - 1].size())
    {
        if (!check[v[start - 1][j] - 1])
        {
            dfs(v, check, v[start - 1][j]);
        }
    }
}
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
//works under 2 till 1e12

double newPrecision(double n)
{
    return floor(pow(10, 250) * n) / pow(10, 250);
}

ll f( ll arr[][2], ll pos, ll n,ll maxw, ll current, ll rec[][100001]){
   if(pos==n-1){
       if(current+arr[pos][0]> maxw){
           return 0;
       }
       else
           return arr[pos][1];
   }
   else {
       ;
   }

   if(rec[pos][current]!=-1){
       return rec[pos][current];
   }

   if (current + arr[pos][0] > maxw)
   {
       return f(arr, pos + 1, n, maxw, current,rec);
   }
   else{
       return max(
           f(arr, pos + 1, n, maxw, current,rec),
           arr[pos][1] + f(arr, pos + 1, n, maxw, (current+arr[pos][0]),rec)
           );
   }
}

int calculate(string s1, string s2, int pos1, int pos2, vector<vector<int> > &LCS){
    if(pos1<0 or pos2<0)
        return 0;
    if(LCS[pos1][pos2]!=-1)
        return LCS[pos1][pos2];
    if(s1[pos1]==s2[pos2]){
        return LCS[pos1][pos2] = 1 + calculate(s1, s2, pos1 - 1, pos2 - 1, LCS);
    }
    else{
        return LCS[pos1][pos2] = max(calculate(s1, s2, pos1-1, pos2 , LCS), calculate(s1, s2, pos1, pos2 - 1, LCS) );
    }
}

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll t;
        cin >> t;
        while(t--){
            int n1, n2;
            cin >> n1 >> n2;
            string s1, s2;
            cin >> s1 >> s2;
            vector<vector<int> > LCS(n1);
            for (int i = 0; i < n1; i++)
            {
                LCS[i] = vector<int>(n2);
                for (int j = 0; j < n2; j++)
                {
                    LCS[i][j] = -1;
                }
            }
            int ans = calculate(s1, s2, n1 - 1, n2 - 1, LCS);
            cout << ans << endl;
        }

        return 0;
}
