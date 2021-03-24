//complexity O(n)
//space commplexity O(h)
class InorderIterator {
  stack<BinaryTreeNode*> stk;
  public:
  // When iterator is initialized it is always
  // at the first element of tree in its in-order
  InorderIterator(BinaryTreeNode* root) {
    populateIterator(root);
  }

  void populateIterator(BinaryTreeNode* root) {
      while (root != nullptr) {
        stk.push(root);
        root = root->left;
      }
  }
  
  bool hasNext() {
    return !stk.empty();
  }

  // getNext returns null if there are no more elements in tree
  BinaryTreeNode* getNext() {
    if (stk.empty()) {
      return nullptr;
    }

    BinaryTreeNode* rVal = stk.top();
    stk.pop();
    BinaryTreeNode* temp = rVal->right;
    populateIterator(temp);
    
    return rVal;
  }
};

string inorder_using_iterator(BinaryTreeNode* root) {
  InorderIterator iter(root);
  string result = "";
  while (iter.hasNext()) {
    result += to_string(iter.getNext()->data) + " ";
  }
  return result;
}

int main() {

  BinaryTreeNode *root = new BinaryTreeNode(100);
  insert_bst(root, 50);
  insert_bst(root, 200);
  insert_bst(root, 25);
  insert_bst(root, 125);
  insert_bst(root, 350);
  insert_bst(root, 12);
  insert_bst(root, 35);
  insert_bst(root, 60);
  cout << endl << "Inorder Iterator= ";
  cout<<inorder_using_iterator(root);
}
