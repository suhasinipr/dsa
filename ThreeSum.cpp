/* Problem : 

Given an array “a” of n elements, return true if any 3 of them could be multiplied up to give a value of m.
Examples
a = [6, 5, 4, 3, 2, 1]; m = 10 => True
a = [4, 1, 2, 3]; m = 16 => False
*/


#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;

class Solution {
    public:
        bool ThreeSum(vector<int> nums, int m) {
            int i, j, k = 0;
            if(nums.size() < 3)
                return false;

            std::sort(nums.begin(), nums.end());
            for(i = 0; i < nums.size(); i++)
            {
               // k = 0;
               int left = i+1; 
               int right = nums.size() -1;
                for(j = i+1; j<nums.size(); j++)
                {
                    //k = j+1;
                    int temp = nums[i] + nums[left] + nums[right];
                    if( temp == m)
                    {
                        return true;
                    }
                    else if (temp < m )
                    {
                        left++;
                    }
                    else
                    { // decrease the index. 
                        right--;
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
    assert(sol->ThreeSum( vector<int>{1, 10, 3, 11, 5},9) == true);
    assert(sol->ThreeSum( vector<int>{6, 5, 4, 3, 2, 1},15) == true);
    assert(sol->ThreeSum( vector<int>{6, 5, 4, 3, 2, 1},10) == true);
    assert(sol->ThreeSum( vector<int>{6, 5, 4},10) == false);
    assert(sol->ThreeSum( vector<int>{6, 5},10) == false);
}