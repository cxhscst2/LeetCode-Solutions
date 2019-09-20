// Definition for a Node.
/*
class Node {
	public:
		int val;
		Node* next;
		Node* random;

		Node() {}

		Node(int _val, Node* _next, Node* _random) {
			val = _val;
			next = _next;
			random = _random;
		}
};
*/

class Solution {
	public:
		Node* copyRandomList(Node* head){
			if (head == NULL){
				return NULL;
			}

			Node* now = head;
			for (; now != NULL;){
				Node* ins = (struct Node*)malloc(sizeof(struct Node));
				ins -> next = now -> next;
				ins -> random = NULL;
				ins -> val = now -> val;
				now -> next = ins;
				now = ins -> next;
			}

			now = head;
			for (; now != NULL; now = now -> next -> next){
				Node* nxt = now -> next;
				if (now -> random != NULL){
					nxt -> random = now -> random -> next;
				}
				else nxt -> random = NULL;
			}

			now = head;
			Node* ret = head -> next;
			for (; now != NULL; ){
				Node *nxt = now -> next;
				if (nxt -> next == NULL){
					now -> next = NULL;
					break;
				}

				now -> next = nxt -> next;
				nxt -> next = now -> next -> next;

			}

			return ret;
		}
};
