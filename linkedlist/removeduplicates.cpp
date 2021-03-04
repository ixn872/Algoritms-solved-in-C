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



class Solution {
public:

    ListNode* deleteDuplicates(ListNode* head) {
        //Base Case

        //first merge sort the list...
        if (head == NULL) {
            return head;
        }

        ListNode* temp = head;
        ListNode* prev;
        while (temp->next!=NULL) {
            if (temp->val == temp->next->val) {
               // cout << prev->val << " " << temp->val << endl;
                prev = temp->next->next;
                
                free(temp->next);
                temp->next = prev;
                continue;
            }
            
            
            temp = temp->next;

        }
        return head;

    }



};

void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->val<< ' ' << endl;
        temp = temp->next;
    }

};


int main() {
  
        ListNode* head = new ListNode(5);
        head->next = new ListNode(4);
        head->next->next = new ListNode(4);
        head->next->next->next = new ListNode(3);
        head->next->next->next->next = new ListNode(2);
        head->next->next->next->next->next = new ListNode(1);

        //printLinkedList(head);
        Solution myObj;
        myObj.deleteDuplicates(head);
        printLinkedList(myObj.deleteDuplicates(head));
        //printLinkedList(myObj.sortList(&head));
        return 0;
    
}
