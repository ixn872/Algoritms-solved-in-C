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

int x = 0;
int right = 0;
//we know that diff between root and left or root and right is smaller than left and right
//so we just need to compare left and right subtrees


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

    int minDiffInBST(TreeNode* root) {
   
        if (root == NULL) {
            return 0;
        };

        minDiffInBST(root->left);
        toCompare.push_back(root->val);

        minDiffInBST(root->right);
 
        return find_min(toCompare);
       
        
        


        //store values of tree in a decreasing array using post order
      
    };

  
};


int main() {
    struct TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    
    Solution myObj;

    cout << myObj.minDiffInBST(root);
    return 0;

}
