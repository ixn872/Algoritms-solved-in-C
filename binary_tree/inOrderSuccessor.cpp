//we locate the position of d using the properties of BST
//if its on the left return successor
//if it is on the right find the minimum right above it

BinaryTreeNode* find_min(BinaryTreeNode* root) {

  if(root == nullptr)
    return nullptr;
  
  while(root->left != nullptr) {
    root = root->left;
  }

  return root;
}

BinaryTreeNode* inorder_successor_bst(BinaryTreeNode* root, int d) {

  if(root == nullptr) {
    return nullptr;
  }

  BinaryTreeNode* successor = nullptr;

  while (root != nullptr) {

    if(root->data < d) {
      root = root->right;
    } else if(root->data > d) {
      successor = root;
      root = root->left;
    } else {
      if(root->right != nullptr) {
        successor = find_min(root->right);
      }
      break;
    }
  }
  return successor;
}

void test(vector<int>& orig_data) {
  
  BinaryTreeNode* root = create_BST(orig_data);
  
  vector<int> all_data = binary_tree_to_vector(root);

  for (int d : orig_data) {
    BinaryTreeNode* successor = inorder_successor_bst(root, d);
    int i = find_in_vector(all_data, d);
    int expected_val = -1;
    if (i < all_data.size() - 1) {
      expected_val = all_data[i + 1];
    }

    if (successor != nullptr) {
      if (expected_val != successor->data) {
        cout << "** " << d << " ==== " << expected_val << ", " << successor->data << "*****";
        assert(expected_val == successor->data);
      }
    }  else {
      assert(successor == nullptr);
    }
    
    if (successor != nullptr)
      cout << "(" << d << ", " << successor->data << ") ";
    else 
      cout << "(" << d << ", nullptr) ";
  }
}
/// Test Program.
int main() {
  vector<int> orig_data = {100, 50, 200, 25, 75, 125, 350};
  test(orig_data);
  
  return 0;
}
