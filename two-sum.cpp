#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> hash;
            vector<int> solution;

            for(int i=0; i<nums.size();i++) {
                int complement = target - nums[i];

                if(hash.find(complement) != hash.end()){
                    solution.push_back(i);
                    solution.push_back(hash[complement]);

                    return solution;
                }

                hash.insert({nums[i], i});
            }
            std::cout << "No Solution\n";
            return {0, 0};
        }
};

int main (){
    vector<int> input = {6, 2, 1, 3, 9, 33};
    int target = 8;

    Solution solution;
    vector<int> answer = solution.twoSum(input, target);

    std::cout << answer.at(0) << ' ';
    std::cout << answer.at(1) << '\n';
}