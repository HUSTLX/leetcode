#include <string>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    int sa = num1.size();
    int sb = num2.size();
    vector<int> temp(sa + sb, 0);
    for (int i = sa - 1; i >= 0; i--) {
        int a = num1[i] - '0';
        for (int j = sb - 1; j >= 0; j--) {
            int b = num2[j] - '0';
            int product = a*b;
            int carry = (temp[j + i + 1] + product) / 10;
            temp[j + i + 1] = (temp[j + i + 1] + product) % 10;
            int x = 0;
            while (carry) {
                int p = temp[j + i - x] + carry;
                temp[j + i - x] = p % 10;
                carry = p / 10;
                x++;
            }
        }
    }
    while (temp[0] == 0) temp.erase(temp.begin());
    string res;
    for (int i = 0; i < temp.size(); i++) {
        res += to_string(temp[i]);
    }
    return res;
}

int main() {
    string b = "0";
    string a = "0";
    string res = multiply(a, b);
}

