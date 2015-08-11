/**
** Reverse a singly linked list.
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
// ͷ�巨
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *post, *curr;
		if(!head) return NULL;
		curr = head->next;
		head->next = NULL;
		while(curr)
		{
			post = curr->next;
			curr->next = head;
			head = curr;
			curr = post;
		}
		return head;
    }
	
	ListNode* reverseBetween(ListNode* head, int m, int n) {
        int count = 0;
		ListNode *post, *curr;
		if(!head) return NULL;
		curr = head->next;
		while(curr)
		{
			if(count++ < m) 
				continue;
			head = curr;
			curr = head->next;
		}
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