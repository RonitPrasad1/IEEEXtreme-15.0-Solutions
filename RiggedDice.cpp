//Joseph: 75/75 (Full)

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 0;
    cin >> T;
    
    for(int i = 0; i < T; i++)
    {
        int N = 0;
        cin >> N;
        
        int diePos = 1, die1Tot = 0, die2Tot = 0;
        int aScore = 0, bScore = 0;
        
        for(int j = 0; j < N; j++)
        {
            int A = 0, B = 0;
            cin >> A >> B;
            aScore += A;
            bScore += B;
            
            if(aScore != bScore && diePos == 1)
            {
                die1Tot += A;
                die2Tot += B;
                diePos = 2;
            }
            else if(aScore != bScore && diePos == 2)
            {
                die1Tot += B;
                die2Tot += A;
                diePos = 1;
            }
            
        }
        
        if(die1Tot > die2Tot)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
    
    return 0;
}
