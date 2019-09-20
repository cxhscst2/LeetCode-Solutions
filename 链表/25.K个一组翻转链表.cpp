/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	public:
		ListNode* reverseKGroup(ListNode* head, int k) {
			int n = 0;
			ListNode* it = head;
			while (it != NULL){
				++n;
				it = it -> next;
			}

			if (k == 1) return head;
			if (head == NULL) return NULL;
			if (n < k) return head;
			int fg = 0;
			int re = n;
			ListNode* ans = NULL, *anstail = NULL, *now = NULL, *nowhead = NULL, *nowtail = NULL;

			int cnt = 0;
			while (head != NULL){
				++cnt;
				--re;
				ListNode *nxt = head -> next;
				nowhead = head;
				head -> next = now;
				now = head;
				if (cnt == 1) nowtail = head;
				if (cnt == k){
					if (fg == 0){
						fg = 1;
						ans = nowhead;
					}
					cnt = 0;

					if (anstail != NULL) anstail -> next = nowhead;
					anstail  = nowtail;
					now = NULL;
					nowhead = NULL;
					nowtail = NULL;
					if (re < k){
						head = nxt;
						break;
					}
				}

				head = nxt;
			}

			if (anstail != NULL) anstail -> next = head;
			return ans;
		}
};
