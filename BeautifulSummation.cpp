//Me: 0 points and TLE, but converted to Python by Jake [bottom of page]:

#include <iostream>

const long long int MOD = 1e9 + 7;

//Binary Exponentiation:
//Complexity: O(log n)
long long int Power(long long int a, unsigned long long int b)
{
     long long int power = 1L;
     
     while (b)
     {
         if (b & 1)
         {
             power *= a;
         }
         b = b >> 1;
         a = a * a;
     }
     return power;
}

//Better way to compute two numbers being multiplied:
//Worst-case complexity: O(log n)
long long int RussianPeasantAlgo (long long int a, long long int b)
{
    long long int res = 0, hold = 0;
    const long long int K = 33;
    
    while (a > 0)
    {
        hold = a & (1 << K) - 1;
        res = (res + b * hold) % MOD;
        a >>= K;
        b = (b << K) % MOD;
    }
    return res;
}

/*
long long int Karatsuba(long long int x, long long int y)
{
    if (x < 10 && y < 10)
        return x * y;
    
    long long int size = std::fmax(Speed(x), Speed(y));

    long long int n = (int) ceil(size / 2.0);
    long p = (long long int) Power(10, n);
    
    long a = (long long int) Floor(x / (double) p);
    long b = x % p;
    
    long c = (long long int) Floor(y / (double) p);
    long d = y % p;

    long long int ac = Karatsuba(a, c);
    long long int bd = Karatsuba(b, d);
    long long int tempHold = Karatsuba(a + b, c + d) - ac - bd;

    return (long long int) 
    (pow(10 * 1L, 2 * n) * ac + pow(10 * 1L, n) * tempHold + bd);
}
*/

/*
Fast Fourier Theorem?
*/

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    long long int p, q, n, M, BeautifulSummation = 0, Summation = 0;
    std::cin >> p >> q >> n >> M;
    
    for (long long int k = 1; k <= n; ++k)
    {
        //std::cout << Exp(p, k) << " " << '\n';
        //std::cout << Exp(k, q) << " " << '\n';
        
        BeautifulSummation = RussianPeasantAlgo(Power(p, k) % MOD, Power(k, q)) % MOD;  
        
        //std::cout << BeautifulSummation << " " << '\n';
        
        //std::cout << '\n';
        
        Summation = Summation % MOD + BeautifulSummation % MOD;
        
        //std::cout << '\n';
        
        //std::cout << Summation << " " << '\n';
    }
    
    std::cout << Summation % M << '\n';
    return 0;
}




——————————————————————————————————————————

#Optimized Solution (Me and Jake): 13 points

from fractions import Fraction

def powerr(b, p, m):
    res = 1

    while p:
        if p & 0x1:
            res *= b
        b *= b % m
        p >>= 1 % m

    return res


p, q, n, m = map(int, input().split())
summation, beautiful_summation = 0, 0

for k in range(1, n + 1):
    beautiful_summation = Fraction(powerr(p % m, k, m) % m) * Fraction(powerr(k % m, q, m) % m)
    summation = (summation % m) + (beautiful_summation % m)

print(int(summation % m))
