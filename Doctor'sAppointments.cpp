//Joseph; SIGSEGV Error debugged by Me: 67 points

#include <bits/stdc++.h>
using namespace std;


void printVector(vector<vector<int>>, int);
void solve(vector<vector<int>>, int);
int expectedSum(int);
int vecSum(vector<int>, int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int l = 0, r = 0;
    int T = 0;
    cin >> T;
    for(int i = 0; i < T; i++) 
    {
        int N = 0;
        cin >> N;
        bool testFlag = true;
        if(N < 2)
        {
                testFlag = false;
                cout << "impossible" << endl;  
        }

        // resizing 2d vector
        vector<vector<int>> v;
        v.resize(N);
        for(int i = 0; i < N; i++)
            v[i].resize(N);
            
        // 2d Array instead of a vector? ANSWER: NO DOESN'T WORK (MEMRORY ISSUES)
        
        // getting left and right and applying them to the vector
        for(int j = 0; j < N; j++)
        {
            cin >> l >> r;
            if(l < 1 || r > N || l > r)
            {
                testFlag = false;
                cout << "impossible" << endl;  
            }
            else 
            {
                while(l <= r)
                {
                    v[j][l-1] = (j + 1);
                    l++;
                } 
            }
        }
        if(testFlag) solve(v, N);
    }  // end testcases
    return 0;
}

int expectedSum(int x)
{
    int ans = x;
    while(x--)
    {
        ans += x;
    }
    return ans;
}

int vecSum(vector<int> v, int N)
{
    int ans = 0;
    for(int i = 0; i < N; i++)
        ans += v[i];
    return ans;
}

void solve(vector<vector<int>> v, int N)
{
    vector<int> ans;
    
    for(int i = 0; i < N; i++)
    {
        int minRow = -1, minColumn = -1, minCount = 100001, minNum = 100001;
        int zCount = 0;
        for(int j = 0; j < N; j++)
        {
            int elemCount = 0;
            
            if(v[j][i] != 0)
            {
                
                elemCount = count(v[j].begin(), v[j].end(), v[j][i]);
                // if it's the only element, it automatically gets the row
                if(elemCount == 1)
                {
                    for(int k = 0; k < N; k++)
                        if(v[k][i] != v[j][i]) v[k][i] = 0;
                    
                    // use minCount as a flag for skipping rest of code
                    minCount = -1;
                    minNum = v[j][i];
                    
                    // butter
                    ans.push_back(v[j][i]);
                    
                    continue;
                } // else it will go to the biggest in the row
                else if(elemCount < minCount) // for priority to the first one
                {
                    minRow = j;
                    minColumn = i;
                    minCount = elemCount;
                    minNum = v[j][i];
                }
                else
                {
                    zCount++;
                }
            } // end count if blcok
            
            if(zCount == N)
            {
                cout << "impossible" << endl;
                return;
            }
            
        } // end for...j
        
        if(minCount == -1) continue;
        // eliminating the numbers from the maxCount row
        for(int j = 0; j < N; j++)
        {
            if(minColumn == -1) break;
            if(j==minColumn) continue;
            v[minRow][j] = 0;
        }
        // eliminate the numbers from the maxCount column
        for(int j = 0; j < N; j++)
        {
            if(minRow == -1) break;
            if(j == minRow) continue;
            v[j][minColumn] = 0;
        }
        ans.push_back(minNum);
    } // end for...i
    if(vecSum(ans, N) != expectedSum(N))
        cout << "impossible";   
    else
        for(auto x: ans)
            cout << x << " ";

    cout << endl;
}

// used for debugging
void printVector(vector<vector<int>> v, int N)
{
    for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < N; k++)
            {
                cout << v[j][k] << " ";
            }
            cout << endl;
        }
}
