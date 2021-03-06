#include <string>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    string s1;
    string s2;
    while (l1 != NULL) {
        s1.push_back(l1->val + '0');
        l1 = l1->next;
    }
    reverse(s1.begin(), s1.end());
    long long a = stoll(s1);
    while (l2 != NULL) {
        s2.push_back(l2->val + '0');
        l2 = l2->next;
    }
    reverse(s2.begin(), s2.end());
    long long b = stoll(s2);
    string temp = to_string(a + b);
    ListNode* res2 = new ListNode(temp[temp.size() - 1] - '0');
    ListNode* res1 = res2;
    for (int i = temp.size() - 2; i >= 0; i--) {
        res2->next = new ListNode(temp[i] - '0');
        res2 = res2->next;
    }
    return res1;
}
int main() {
    ListNode* l1 = new ListNode(5);
    //l1->next= new ListNode(1);
    ListNode* l2 = new ListNode(5);
    ListNode* res = addTwoNumbers(l1, l2);
}