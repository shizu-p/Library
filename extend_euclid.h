#include<iostream>
using namespace std;

struct euclid_gcd{
    long long val(long long a,long long b){
        if(b==0){
            return a;
        }
        else return val(b,a%b);
    }
    long long ext_gcd(long long a,long long b,long long &x,long long &y){
        // ax + by = gcd(a,b)
        if(b==0){
            x = 1;
            y = 0;
            return a;
        }
        long long d = ext_gcd(b,a%b,y,x);
        y -= a/b * x;
        return d;
    }
};
