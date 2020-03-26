/* Given an array nums and a value val, remove all instances of
 * that value in-place and return the new length.
 * 
 * Do not allocate extra space for another array,
 * you must do this by modifying the input array in-place with O(1) extra memory.
 * 
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */

/* Runtime: 4 ms, faster than 67.24% of C++ online submissions for Remove Element. */

#include <iostream>
#include <vector>

using std::vector;

void printVector(vector<int> input){
    for(int c : input){
        std::cout << c << '\n';
    }
}

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()){
            return 0;
        }
        // does using range based for loop make it not O(1)??
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == val){
                nums.erase(nums.begin()+i);
                i--;
            }
        }

        return nums.size();
    }
};

int main() {
    Solution solution;

    vector<int> testCase  = {3, 2, 2, 3};

    std::cout << solution.removeElement(testCase, 3) << '\n';

    return 0;
}   