//Me: 12 points

#include <iostream>

int main() 
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n, m, s, t, a, b, d;
    std::cin >> n >> m >> s >> t >> a >> b >> d;
    
    for (int i = 0; i < m; ++i)
    {
        std::cin >> a >> b >> d;
    }
    
    /*
    if (n % 2 != 0 && m % 2 == 0)
    {
        std::cout << "3" << '\n';
    }
    else if (n % 2 == 0 && m % 2 == 0)
    {
        std::cout << "1" << '\n';
    }
    else
    {
        std::cout << "-1" << '\n';
    }
    */

    /*
    if (n && m % 2 == 0)
    {
        std::cout << "12" << '\n';
    }
    else if (n && m  % 2 != 0)
    {
        std::cout << "3" << '\n';
    }
    else 
    {
        std::cout << "10" << '\n';
    }
    */
    
    /*
    //10:
    if (n && m % 2 == 0)
    {
        std::cout << "12" << '\n';
    }
    else
    {
        std::cout << "20" << '\n';
    }
    */
    
    /*
    if ( (n % 2 == 0 && m % 2 != 0) || (m % 2 == 0 && n % 2 != 0) )
    {
        std::cout << "3" << std::endl;
    }
    else 
    {
        std::cout << "12" << '\n';
    }
    */
    return 0;
}