#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int> nums, int target) {
            int k1,k2;
            map<int, int>::iterator it;
            vector<int> result;
            map<int, int> nums_map;
            for(int i=1; i< nums.size(); i++) {
                nums_map[nums[i]] = i;
            }
            for(int j=0; j< nums.size(); j++) {
                it = nums_map.find(target - nums[j]);
                if(it != nums_map.end()) {
                    k1 = j;
                    k2 = it->second;
                    break;
                }
            }
            result.push_back(k1);
            result.push_back(k2);
            return result;
        }
};



int main(int argc, char **argv) {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);

    int target = 6;

    Solution su;
    vector<int> result = su.twoSum(nums, target);
    for(int i=0; i< result.size(); i++) {
        cout << result[i] << endl;
    }
}
