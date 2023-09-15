// Number of islands leetcode fastest solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size(); // number of rows
        if(n==0) return 0; // if no rows then return 0
        int m = grid[0].size(); // number of columns
        int count = 0; // count of islands
        for(int i=0;i<n;i++) // for each row
        {
            for(int j=0;j<m;j++) // for each column
            {
                if(grid[i][j]=='1') // if the cell is 1
                {
                    count++; // increment the count
                    dfs(grid,i,j); // call dfs
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>>& grid,int i,int j) // dfs function
    {
        int n = grid.size(); // number of rows
        int m = grid[0].size(); // number of columns
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0') // if the cell is out of bounds or is 0 then 
            return;
        grid[i][j] = '0'; // mark the cell as 0
        dfs(grid,i+1,j); // call dfs for all the 4 directions
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    }
    Solution obj;
    cout<<obj.numIslands(grid)<<endl;
}