/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
  Node* cloneGraph(Node* node) {
    if (!node)
      return node;
    unordered_map<Node *, Node *> lookup;
    vector<Node *> todo(1, node);
    Node * root = new Node(node->val);
    lookup[node]=root; //.insert(std::pair<Node *, Node *>(node, root));
    while (todo.size()) {
      Node * cur = todo.back();
      todo.pop_back();
      Node * clone = lookup.at(cur);
      for (Node * neighbor : cur->neighbors) {
        auto itor = lookup.find(neighbor);
        if (itor == lookup.end()) {
          Node * cloneNeighbor = new Node(neighbor->val);
          todo.push_back(neighbor);
          lookup[neighbor]=cloneNeighbor; //.insert(std::pair<Node *, Node *>(neighbor, cloneNeighbor));
          clone->neighbors.push_back(cloneNeighbor);
        }
        else
          clone->neighbors.push_back(itor->second);
      }
    }
    return root;
  }
};
