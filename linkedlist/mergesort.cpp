//*
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// * };
// 

//Given the root of a Binary Search Tree(BST), return the minimum difference between the values of any two different nodes in the tree.

#include<iostream> 
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 //
 //Given the head of a linked list, return the list after sorting it in ascending order.
 //
 //Follow up : Can you sort the linked list in O(n logn) time and O(1) memory(i.e.constant space) ?

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

struct pointers {
    ListNode* ptr1;
    ListNode* ptr2;
};



//ListNode* SortedMerge(ListNode* a, ListNode* b);


//void Split(ListNode* source,
//    ListNode** frontRef, ListNode** backRef);

class Solution {
public:
  
    //MergeSort(headRef)
    //    1) If the head is NULL or there is only one element in the Linked List
    //    then return.
    //    2) Else divide the linked list into two halves.
    //    FrontBackSplit(head, &a, &b); /* a and b are two halves */
    //3) Sort the two halves aand b.
    //MergeSort(a);
    //MergeSort(b);
    //4) Merge the sorted aand b(using SortedMerge() discussed here)
    //    and update the head pointer using headRef.
    //    * headRef = SortedMerge(a, b);
    /* function prototypes */

    void  Split(ListNode* head, ListNode** a, ListNode** b) {

        ListNode* fast;
        ListNode* slow;
        slow = head;
        fast = head->next;

        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }

        /* 'slow' is before the midpoint in the list, so split it in two
   at that point. */

        *a = head;
        *b = slow->next;
        slow->next=NULL; //WHY?
        //struct pointers p;
        //p.ptr1 = a;
        //p.ptr2 = b;
        
        //return p;

     }


    
    ListNode* SortedMerge(ListNode* a, ListNode* b) {
        ListNode* result = NULL;
        if (a == NULL) return (b);
        if (b == NULL) return (a);

        if (a->val <= b->val) {
            result = a;
            result->next= SortedMerge(a->next, b);
        }
        if (b->val <= a->val) {
            result = b;
            result->next= SortedMerge(a, b->next);
        }
        return (result);
    }

    struct ListNode*  sortList(ListNode** headref) {
        //Merge sort is often preferred for sorting a linked list.The slow random - access performance of a linked list makes some other algorithms(such as quicksort) perform poorly, and others(such as heapsort) completely impossible.
        ListNode* head = *headref;
        ListNode* half1 = NULL;
        ListNode* half2 = NULL;

        if (head == NULL || head->next==NULL) {
            return head;
        }

        Split(head, &half1, &half2);
        
        sortList(&half1);

        sortList(&half2);
        //cout << "hello???" << endl;

        *headref= SortedMerge(half1, half2);
        //cout << "hello???" << endl;
        //cout << head->next->val << endl;
        return *headref;
    }
      
};

void printLinkedList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val ;
        temp = temp->next;
       
    }
    cout << "\n";
}

/* Function to print nodes in a given linked list */
void printList(ListNode* node)
{
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
}

    int main() {
  
        ListNode* head = new ListNode(5);
        head->next = new ListNode(4);
        head->next->next = new ListNode(6);
        head->next->next->next = new ListNode(0);
        head->next->next->next->next = new ListNode(10);
        head->next->next->next->next->next = new ListNode(50);

        printLinkedList(head);
        Solution myObj;
        myObj.sortList(&head);
        printList(head);
        //printLinkedList(myObj.sortList(&head));
        return 0;
    
}
