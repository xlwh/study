#include <iostream>
#include <vector>
using namespace std;
/*
 *Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *Example:
 *      Given nums = [2, 7, 11, 15], target = 9,
 *      Because nums[0] + nums[1] = 2 + 7 = 9,
 *      return [0, 1].
 */ 

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> result;
            for(int i=1; i< nums.size(); i++) {
                int temp = nums[i-1];
                if(temp + nums[i] == target) {
                    result.push_back(i-1);
                    result.push_back(i);
                     break;
                }
            }
            return result;
        }

};


int main(int argc, char **argv) {
    Solution su;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    int target = 9;

    vector<int> ret = su.twoSum(nums, target);
    for(int i=0; i< ret.size(); i++) {
        cout << ret[i] << endl;
    }
}
