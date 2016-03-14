#include <string>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int lengthOfLongestSubstring(string s) {
    vector<int> temp(256, -1);
    int max_l = 0;
    int begin = 0;
    for (int i = 0; i < s.size(); i++) {
        begin = max(temp[s[i]] + 1, begin);
        temp[s[i]] = i;
        max_l = max(max_l, i - begin + 1);
    }
    return max_l;
}
int main() {
    string b = "aabc";
    string a = "0";
    int res = lengthOfLongestSubstring(b);
}