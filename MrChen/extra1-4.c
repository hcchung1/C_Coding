#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

long long r = 0;
long long sum = 0;

int gcd(int t,int v){

    if(t%v==0){

        return v;
    }

    else return GCD(v,t%v);

}

long long Pollard_Rho(long long x) {
  long long t = 0;
  long long c = rand() % (x - 1) + 1;
  // 加速算法，这一步可以省略
  for (int i = 1; i < 1145; ++i) t = f(t, c, x);
  long long s = t;
  int step = 0, goal = 1;
  long long val = 1;
  for (goal = 1;; goal <<= 1, s = t, val = 1) {
    for (step = 1; step <= goal; ++step) {
      t = f(t, c, x);
      val = val * abs(t - s) % x;
      // 如果 val 为 0，退出重新分解
      if (!val) return x;
      if (step % 127 == 0) {
        long long d = gcd(val, x);
        if (d > 1) return d;
      }
    }
    long long d = gcd(val, x);
    if (d > 1) return d;
  }
}

int main(){

    long long num;

    scanf("%lld", &num);
    //printf("%lld", num);
    Pollard_Rho(num);
    //printf("%lld", carrey);

    int carreycarrey = sum;
    
    if(num % sum == 0){


        Pollard_Rho(sum);

        if(carreycarrey % sum == 0){

            printf("%lld is a Carrey's Taipei number.", num);
        }
        
        else{
            printf("%lld is a Carrey's number.", num);
        }

    }
    else{

        printf("%lld is not a Carrey's number (%lld).", num, sum);

    }

    
    
    return 0;
    



}