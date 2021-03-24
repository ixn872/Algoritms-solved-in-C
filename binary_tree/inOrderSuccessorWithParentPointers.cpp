BinaryTreeNode* find_min_in_tree(BinaryTreeNode* root) {
  if(root == nullptr)
    return nullptr;
  
  while(root->left != nullptr) {
    root = root->left;
  }

  return root;
}

BinaryTreeNode* inorder_successor_bst_parent_pointer(BinaryTreeNode* node) {
  
  if(node == nullptr) {
    return nullptr;
  }

  if(node->right != nullptr) {
    return find_min_in_tree(node->right);
  }
  
  while(node->parent != nullptr) {
    if(node->parent->left == node) {
      return node->parent;
    }
    node = node->parent;
  }

  return nullptr;
}

BinaryTreeNode* find_successor(
  BinaryTreeNode* root, int d) {

  while (root != nullptr) {

    if(root->data < d) {
      root = root->right;
    } else if(root->data > d) {
      root = root->left;
    } else {
      return inorder_successor_bst_parent_pointer(root);
    }
  }

  return nullptr;
}

int main() {
  vector<int> orig_data = {100, 50, 200, 25, 75, 125, 350};
  
  BinaryTreeNode* root = create_BST(orig_data);

  populate_parents(root);

  vector<int> all_data = binary_tree_to_vector(root);

  for (int d : orig_data) {
    //BinaryTreeNode* node = find_in_bst(root, d);
    BinaryTreeNode* successor = find_successor(root, d);
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
  return 0;
}
