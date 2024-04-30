## Class Representation ##
// Singly linked list 
class ListNode {
public:
    int data;
    ListNode* next;
};
------------------------------------------------------
// Doubly linked list 
class ListNode {
public:
    int data;
    ListNode* next; // Pointer to next node in DLL
    ListNode* prev; // Pointer to previous node in DLL
};

=================================================================================================
Reverse a Linked List   //BEWARE we return pre here.

ListNode* ReverseLL(ListNode* head)
{
    ListNode* pre = NULL ;
    ListNode* next = NULL ;
    while(head!= NULL)
        {
            next = head->next ;
            head->next = pre ;
            pre = head ;
            head = next ;
        }
    return pre  ;
}

=================================================================================================
Remove Nth node from end 

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* start = new ListNode();
    start->next = head ; 
    ListNode* slow = start ;
    ListNode* fast = start ; 
    for(int i =0;i<n;i++)
        {
            fast = fast->next ; 
        }
    while(fast!= NULL)
        {
            fast= fast->next ;
            slow = slow->next ; 
        }
    slow->next = slow->next->next ; 

    return start->next ; 
}

=================================================================================================
Find Middle of Linked List

ListNode* findMiddle(ListNode* head)
{
    ListNode* slow =  head ;
    ListNode* fast = head ;
    while(fast!= NULL && fast->next!= NULL)
        {
            slow = slow->next ;
            fast = fast->next->next ; 
        }
    return slow ; 
}

=================================================================================================
Merge Two Sorted Linked Lists

ListNode* MergeSortedLL(ListNode* l1, ListNode* l2)
{
    if(l1 == NULL) return l2 ;
    if(l2 == NULL) return l1 ; 

    if(l2->val > l1->val)
    {
          swap(l1,l2) ;
    }
    ListNode* res = l1 ;              // Creating a node that is to be returned.
    while(l1 !=NULL && l2 !=NULL)
        {
            ListNode* tmp = NULL ;
            while(l1!=NULL && l1->val<= l2->val)
            {
                tmp = l1 ;
                l1=l1->next ; 
            }
            tmp->next =  l2 ;
            swap(l1, l2);
        }
    return res ; 
    }
}

=================================================================================================
Delete Node whos address is known in a LL 

void deleteNode(ListNode* node) {

        node->val  = node->next->val  ; 
        node->next = node->next->next ; 
    }
};

=================================================================================================
Add two numbers given as Linked List

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode() ;
    ListNode* temp =  dummy ;
    int carry  = 0 ;
    while( l1!= NULL || l2 != NULL || carry)
        {
            int sum = 0 ; 
            
            if(l1!= NULL)
            {
                sum += l1->val ;
                l1 = l1->next ; 
            }
            if(l2!= NULL)
            {
                sum+= l1->val ; 
                l2 = l2->next ; 
            }
            
            sum= sum + carry ; 
            carry =  sum/10 ; 
            
            ListNode* node =  new ListNode(sum%10);
            temp->next = node ;
            node = temp->next ; 
        }
    return dummy->next ; 
}

=================================================================================================
Find Intersection Point in a Linked List

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if( headA == NULL || headB  == NULL) return NULL ; 
	ListNode* a = headA ;
	ListNode* b = headB ; 
	
	while(a!=b)
	{
	    a = a == NULL ? headB : a->next ; 
	    b = b == NULL ? headA : b->next ;
	}
	return a ;
}

=================================================================================================
Find Intersection Point in a Linked List
