/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include <iostream>
 using namespace std;
 struct ListNode 
 {
    int val;
    ListNode *next;
	ListNode(int x, ListNode *n) : val(x), next(n) {}
 };
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
    }
};

void printList(struct ListNode *head)
{
	struct ListNode *cur = head;
	while(cur != NULL)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main()
{
	ListNode *head = NULL, *tmp = NULL;
	Solution A;
	char a[] = {1};
	for(int i = 0; i < 1; i++)
	{
		head = new ListNode(a[i], head);
	}
	printList(head);
	printList(A.reverseList(head));
}