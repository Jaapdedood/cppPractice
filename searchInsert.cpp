#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(low <= high) {
            int mid = low + (high-low)/2; // use this instead of l+r/2 since l+r might overflow

            if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main(int argc, char *argv[]){
    Solution solution;

    vector<int> input = {1, 3, 5, 6};
    int target = atoi(argv[1]);
    std::cout << "target: " << target << '\n';

    std::cout << solution.searchInsert(input, target) << '\n';

    return 0;
} 