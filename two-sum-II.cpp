#include <iostream>
#include <unordered_map>
#include <vector>

using std::vector;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> answer;
            int beginning = 0;
            int end = nums.size() - 1;

            for(int i=0; i < nums.size();i++){
                int sum = nums[beginning] + nums[end];
                if(sum == target){
                    answer.push_back(beginning+1);
                    answer.push_back(end+1);            
                    return answer;
                }
                else if(sum < target){
                    beginning++;
                }
                else if(sum > target){
                    end--;
                }
            }
            std::cout << "Something Happened";
            return {};
        }
};

int main (){
    vector<int> input = {2, 7, 11, 15};
    int target = 9;

    Solution solution;
    vector<int> answer = solution.twoSum(input, target);

    std::cout << answer.at(0) << ' ';
    std::cout << answer.at(1) << '\n';
}