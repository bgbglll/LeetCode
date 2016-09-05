// 24. Swap Nodes in Pairs.cpp : Defines the entry point for the console application.
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
public:
	ListNode *swapPairs(ListNode *head) {
		if (head == nullptr || head->next == nullptr)return head;
		ListNode dummy(-1);
		dummy.next = head;
		for (ListNode *prev = &dummy, *cur = prev->next, *next = cur->next; next != nullptr;
			prev = cur, cur = cur->next, next = (cur ? cur->next : nullptr)){
			prev->next = next;
			cur->next = next->next;
			next->next = cur;
		}
		return dummy.next;
	}
};

int main()
{

	return 0;
}

