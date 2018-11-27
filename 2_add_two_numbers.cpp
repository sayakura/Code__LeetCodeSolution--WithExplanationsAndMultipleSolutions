// My solution, I used three queue since I calculate it from the back, this solution can
// handle list with different size. 36ms 

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        queue<int>  list1;
        queue<int>  list2;
        queue<int>  s;
        ListNode    *head;
        ListNode    *temp;
        int         carry;
        int         tmp;
    
        carry = 0;
        while (l1)
        {
            list1.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            list2.push(l2->val);
            l2 = l2->next;
        }
        while (list1.size() || list2.size() || carry)
        {
            tmp = 0;
            if (list1.size()){
                tmp += list1.front();
                list1.pop();
            }
            if (list2.size())
            {
                tmp += list2.front();
                list2.pop();
            }
            tmp += carry;
            carry = tmp / 10;
            s.push(tmp % 10);
        }
        if (s.size())
        {
            head = temp = new ListNode(s.front());
            s.pop();
        }
        while (s.size())
        {
            temp->next = new ListNode(s.front());
            s.pop();
            temp = temp->next;
        }
        return head;
    }
};

// another solution here, it is 28ms, but it assumed that two lists have exact same size
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode(0), *first = root;
        int carry = 0;
        
        while ( l1 || l2 )
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int ans = n1 + n2 + carry;
            carry = ans / 10;
            root->next = new ListNode(ans%10);
            root = root->next;
            if ( l1 ) l1 = l1->next;
            if ( l2 ) l2 = l2->next;
        }
        if (carry)
            root->next = new ListNode(1);
        
        return first->next;
        
    }
};


