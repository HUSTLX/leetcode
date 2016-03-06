#include <string>
#include <stack>
#include <vector>
using namespace std;

bool isValidSerialization(string preorder) {
    int len = preorder.size();
    vector<char> temp;
    bool flag = true;
    for (int i = 0; i < len; i++) {
        if (flag == true) {
            temp.push_back(preorder[i]);
            flag = false;
        }   
        if (preorder[i] == ',') {
            flag = true;
            continue;
        }
        int sz = temp.size();
        while (sz > 1 && temp[sz - 1] == '#'&&temp[sz - 2] == '#') {
            temp.pop_back();
            temp.pop_back();
            if (temp.empty()) return false;
            temp.pop_back();        
            temp.push_back('#');
            sz = temp.size();
        }
    }
    return temp.size()==1&&temp[0]=='#';
}
int main() {
    string s = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    //string s = "1,#,#,#,#";
    //string s = "9,#,92,#,#";
    bool re = isValidSerialization(s);
}





















