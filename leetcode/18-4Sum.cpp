#include <string>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int len = nums.size();

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int third = j + 1, fouth = len - 1;
            while (third < fouth) {
                int sum = nums[i] + nums[j] + nums[third] + nums[fouth];
                if (target == sum) {
                    vector<int> temp = { nums[i],nums[j],nums[third],nums[fouth] };
                    res.push_back(temp);
                    while (third < fouth && nums[third] == temp[2]) third++;
                    while (third < fouth && nums[fouth] == temp[3]) fouth--;
                }
                else sum < target ? third++ : fouth--;
            }
            while ((j + 1 < len) && nums[j] == nums[j + 1]) j++;
        }
        while ((i + 1 < len) && nums[i] == nums[i + 1]) i++;
    }
    return res;
}
int main() {
    vector<int> nums = { 1,0,-1,0,-2,2 };
    int target = 0;
    vector<vector<int>> res = fourSum(nums, target);
}
