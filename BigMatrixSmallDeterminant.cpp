//Me: 23 points

#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n, a;
    std::cin >> n;
    
    while (n--)
    {
        std::cin >> a;
    }
    
    int hold = 0, Summation = 0;
    
    int val = -1;
    hold = val;
    
    if (hold <= 0)
    {
        std::cout << hold << '\n';
    }
    else if (n % 2 == 0)
    {
        std::cout << "1 0" << '\n';
        std::cout << "0 1" << '\n';
    }
    else 
    {
        for (int i = 0; i < n; ++i)
        {
            Summation += i;
            if (Summation % 2 != 0)
            {
                std::cout << "1 1" << '\n';
                std::cout << "0 1" << '\n';
            }
            else if (n % 2 != 0)
            {
                std::cout << "-1" << '\n';
                exit(0);
            }
        }
    }
    return 0;
}
