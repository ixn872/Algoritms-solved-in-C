/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


//Algorithm Inorder(tree)
//1. Traverse the left subtree, i.e., call Inorder(left - subtree)
//2. Visit the root.
//3. Traverse the right subtree, i.e., call Inorder(right - subtree)

#include<iostream> 
#include <vector>
#include <algorithm>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};



class Solution {
public:
    vector<int> toStore = {}; //save the node values each time

    vector<int> inorderTraversal(TreeNode* root) {

        TreeNode* temp = root;
        if (root == NULL)
            return toStore;

        /* first recur on left child */
        inorderTraversal(root->left);

        /* then print the data of node */
       
        toStore.push_back(root->val);

        /* now recur on right child */
        inorderTraversal(root->right);
        
        return toStore;
    }

};



void print(vector <int> const& a) {
    std::cout << "The vector elements are : ";

    for (int i = 0; i < a.size(); i++)
        cout << a.at(i) << ' ';
}

int main() {
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution myObj;
 
    print(myObj.inorderTraversal(root));
    return 0;

}
