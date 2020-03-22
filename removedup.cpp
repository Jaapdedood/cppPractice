/*  -- Remove Duplicates from Sorted Array -- 
 *
 * Given a sorted array nums, remove the duplicates in-place such that
 * each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this by
 * modifying the input array in-place with O(1) extra memory.
 */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }

        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i + 1]){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
    }
};

int main(){
    vector<int> input = {0, 0, 1, 1, 1, 2, 2, 3, 4};

    Solution solution;

    int a = solution.removeDuplicates(input);

        // range based for loop
    for(int i : input){
        std::cout << i << '\n';
    }

    return 0;
}