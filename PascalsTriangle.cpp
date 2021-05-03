/* Problem : 

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example1: 
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example2:
Input: numRows = 1
Output: [[1]]
*/


#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generatePascalsTriangle(int numRows) {
        
        vector<vector<int>> res;
        
        for(int i = 0; i < numRows; i++)
        {
            res.push_back(vector<int>{1}); //first element, always 1
            for(int j = 1; j <= i-1; j++)
            {
                res[i].push_back(res[i-1][j-1] + res[i-1][j]);
            }
            if(i>=1)
                res[i].push_back(1); //last element is 1
        }
        return res;
    }
};

int main(void)
{
    Solution *sol = new Solution();
    vector<vector<int>> vec1{{1},{1,1},{1,2,1},{1,3,3,1}, {1,4,6,4,1}};
    vector<vector<int>> vec2{{1},{1,1}};
    vector<vector<int>> vec3{{1}};
    assert(sol->generatePascalsTriangle(5) == vec1);
    assert(sol->generatePascalsTriangle(2) == vec2);
    assert(sol->generatePascalsTriangle(1) == vec3);
}