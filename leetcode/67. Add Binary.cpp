#include <string>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
string addBinary(string a, string b) {
    int carry = 0;
    int len = a.size() > b.size() ? a.size() : b.size();
    string res;
    for (int i = 0; i < len; i++) {
        int na = i < a.size() ? (a[a.size() - 1 - i] - '0') : 0;
        int nb = i < b.size() ? (b[b.size() - 1 - i] - '0') : 0;
        int sum = na + nb + carry;
        res = to_string(sum % 2) + res;
        carry = sum / 2;
    }
    if (carry) res = '1' + res;
    return res;
}
int main() {
    string b = "11";
    string a = "11";
    string re = addBinary(a, b);
}