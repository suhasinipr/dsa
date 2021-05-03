/* Problem : 

Given an array “a” of n elements, return true if any 3 of them could be multiplied up to give a value of m.
Examples
a = [6, 5, 4, 3, 2, 1]; m = 10 => True
a = [4, 1, 2, 3]; m = 16 => False
*/


#include <iostream>
#include <vector>
#include <assert.h>


using namespace std;

class Solution {
    public:
        bool ThreeSum(vector<int> nums, int m) {
            int i, j, k = 0;
            if(nums.size() < 3)
                return false;
            for(i = 0; i < nums.size(); i++)
            {
                for(j = i+1; j<nums.size()-1; j++)
                {
                    k = j+1;
                    if((i != j) && (i != k) && (k != j) && (nums[i] + nums[j] + nums[k] == m))
                    {
                        return true;
                    }
                }
            }

            return false;
        }
};

int main(void)
{
    Solution *sol = new Solution();
    assert(sol->ThreeSum( vector<int>{4, 1, 2, 3},16) == false);
    assert(sol->ThreeSum( vector<int>{6, 5, 4, 3, 2, 1},15) == true);
    assert(sol->ThreeSum( vector<int>{6, 5, 4, 3, 2, 1},10) == true);
    assert(sol->ThreeSum( vector<int>{6, 5, 4},10) == false);
    assert(sol->ThreeSum( vector<int>{6, 5},10) == false);
}