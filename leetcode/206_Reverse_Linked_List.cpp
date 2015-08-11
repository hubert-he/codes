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
	
ListNode* reverseBetween(ListNode* head, int m, int n) 
{
	ListNode *ppre = head, *pre, *post, *curr, **tail;
	if(!head) return NULL;
	
	for(int i = 1; i < m-1 && ppre; i++)	
		ppre = ppre->next;
	cout << "head = " << ppre->val << endl;
	if(!ppre->next) return NULL;
	pre = ppre->next;
	curr = pre->next;
	tail = &(pre->next);
	cout << "end: " << curr->val << " " << (*tail)->val << endl;
	int count = m;
	post = curr->next;
	while(curr && count < n)
	{
		cout << curr->val << "n " << n << " count " << count << endl;
		post = curr->next;
		curr->next = ppre->next;
		ppre->next = curr;
		curr = post;
		count++;
	}
	cout << "end: " << curr->val << " " << (*tail)->val << endl;
	*tail = curr;
	return head;
}
};

void printList(struct ListNode *head)
{
	struct ListNode *cur = head;
	int total = 10;
	while(cur != NULL && (total-- >= 0))
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
	char a[] = {1, 2, 3, 4, 5, 6};
	for(int i = 0; i < 6; i++)
	{
		head = new ListNode(a[i], head);
	}
	printList(head);
	//A.reverseBetween(head, 2, 4);
	printList(A.reverseBetween(head, 2, 6));
}