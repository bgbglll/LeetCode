// 382. Linked List Random Node.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>

using namespace std;



struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
private:
	ListNode* curr;
	ListNode* newhead;
	int length;
public:
	/** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		curr = head;
		newhead = head;
		int i = 0;
		while (head){
			head = head->next;
			i++;
		}
		length = i;
	}

	/** Returns a random node's value. */
	int getRandom() {
		int n = rand() % length;
		while (n){
			if (!curr->next){
				curr = newhead;
				n--;
			}
			while (curr && curr->next && n){
				curr = curr->next;
				n--;
			}
		}
		return curr->val;
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(head);
* int param_1 = obj.getRandom();
*/
int main()
{
	return 0;
}

