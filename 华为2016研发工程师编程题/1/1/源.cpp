#include<cstdio>
#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* pNext;
	ListNode():val(0),pNext(nullptr){}
};

int main()//循环链表解题
{
	int n;
	while (cin >> n)
	{
		ListNode* pHead = new ListNode();
		ListNode* Pre = pHead;
		//大于1000说的什么几把玩意
		for (int i = 0; i < n; ++i)
		{
			ListNode* pNode = new ListNode();
			pNode->val = i;
			Pre->pNext = pNode;
			Pre = Pre->pNext;
		}
		Pre->pNext = pHead->pNext;
		ListNode* pRun = pHead->pNext;
		int sum = n;
		while (sum!=1)
		{
			pRun = pRun->pNext;
			ListNode* pForward = pRun;
			pForward->pNext = pRun->pNext->pNext;
			pRun = pForward->pNext;
			sum--;
		}
		cout << pRun->val << endl;
	}
	return 0;
}