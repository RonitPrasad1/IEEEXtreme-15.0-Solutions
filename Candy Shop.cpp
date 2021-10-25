//Me: 6 points

#include <iostream>
#include <cmath>

const long long int MOD = 998244353;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n, k, a, b, counter1 = 0, counter2;
    std::cin >> n >> k;
    
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a >> b;
        if ((b == k || k == b))
        {
            ++counter1;
        }
        else if (k < b)
        {
            counter2 = 0;
        }
    }
    
    if ( (b == k || k == b) )
    {
        std::cout << counter1 << '\n';
    }
    else if (k < b)
    {
        std::cout << counter2 << '\n';
    }
    return 0;
}
