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
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<int> toCompare = {};

    void print(vector <int> const& a) {
        std::cout << "The vector elements are : ";

        for (int i = 0; i < a.size(); i++)
            cout << a.at(i) << ' ';
    }


    int find_min(vector <int> const& a) {
        int diff = *std::max_element(a.begin(), a.end());
        for (int i = 0; i < a.size()-1; i++)
            if (a.at(i + 1) - a.at(i) < diff) {
                diff = a.at(i + 1) - a.at(i);

            }
        return diff;
    }

    TreeNode* invertTree(TreeNode* root) {
        //Post order traversal right left root and finnally replave the two main branches

     

        if (root == NULL) {
            return root;
        };

        TreeNode* Left = root->left;
        TreeNode* Right = root->right;

        root->left = Right;
        root->right = Left;

        invertTree(root->right);
        invertTree(root->left);

        // switch the main branches
      
        
        root->left = Right;
        root->right = Left;
       
        
        return root;
      
    };

  
};

void printPreorder(struct TreeNode* node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    cout << node->val << " ";


    /* now recur on right subtree */
    printPreorder(node->right);

    /* then recur on left sutree */
    printPreorder(node->left);


}


int main() {
    struct TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(7);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(9);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(1);
    
    Solution myObj;
    printPreorder(root);
    printPreorder(myObj.invertTree(root));
    return 0;

}
