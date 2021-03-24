//recursive solution using depth first traversal. Meaning we visit the root of both trees then the left subtree then the right and each time we compare if they are identical

bool are_identical(BinaryTreeNode* root1, BinaryTreeNode* root2) {
  // TODO: Write - Your - Code
  if (root1==nullptr && root2==nullptr ){
    return true;
  }

  if (root1!=nullptr && root2!=nullptr){
      return root1->data==root2->data && are_identical(root1->left,root2->left) && are_identical(root1->right,root2->right);
      
  }
 
 return false;
}
