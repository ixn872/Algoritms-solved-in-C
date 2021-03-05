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

void printLinkedList(ListNode* head);
//
//Algorithm of Insertion Sort :
//
//Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
//At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
//It repeats until no input elements remain.

class Solution {
public:

    ListNode* insertionSortList(ListNode* head) {


    }

};


template <class T>
void bubbleSort(T a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; i < j; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
            }
        }
    }
}



void printLinkedList(ListNode* head) {
        ListNode* temp = head;
        cout << "----" << endl;
        while (temp) {
            
            cout << temp->val << "" << endl;
            temp = temp->next;
        }
        cout << "----" << endl;

    
};


int main() {
  //[-1,5,3,4,0]
        ListNode* head = new ListNode(-1);
        head->next = new ListNode(5);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(0);
      //  head->next->next->next->next->next = new ListNode(1);

        //printLinkedList(head);
      //  Solution myObj;
     //   printLinkedList(myObj.insertionSortList(head));
        //printLinkedList(myObj.sortList(&head));

        int a[5] = { 10,50,30,20,100 };
       // sizeof is a keyword, but it is a compile - time operator that determines the size, in bytes, of a variable or data type.
        cout << sizeof(a) << " " << sizeof(a[0]) <<  endl;
        int n = sizeof(a) / sizeof(a[0]);
        bubbleSort<int>(a, 5);

        cout << " Sorted array : ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;

        return 0;
    
}
