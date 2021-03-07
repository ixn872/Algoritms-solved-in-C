#include <iostream> 
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;







/**
 * Definition for a binary tree node.**/
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

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

#include <vector>
#include <queue>




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

#include <vector>
#include <queue>

class Solution {
		public:

			vector<vector<int>> final;
			int lc1, rc1;
			vector<vector<int>> levelOrder(TreeNode* root) {


				if (root == NULL && final.size() == 0) {
					return final;
				}

				queue<TreeNode* > q;
				//initiating a queue with a root starting from level = 0
				q.push(root);
				int level = 0;


				while (q.empty() == false) {
					// final.push_back({});

					 //number of elements in the current level
					int level_length = q.size();
					vector<int> curr_level = {};
					for (int i = 0; i < level_length; i++) {
						TreeNode* node = q.front();
						q.pop();
						curr_level.push_back(node->val);

						// final.push_back(curr_level);


						if (node->left != NULL) {

							q.push(node->left);

						}

						if (node->right != NULL) {

							q.push(node->right);
						}

					}
					final.push_back(curr_level);

					level++;


				}

				return final;
			}



		};


void quicksort(int arr[],int low,int high) {

	if (low < high){

		for (int j = low; j < high; j++) {
			if (arr[j] > arr[j+1]) {
				std::swap(arr[j], arr[j + 1]);
			    quicksort(arr, low, j + 1);
				
			}
		}

	}

}

void printArray(int arr[],int n){
	for (int i = 0; i < n; i++) {
		cout << arr[i] <<","<<endl;
	}

}

void printVector(vector<vector<int>> vec) {
	cout << "-----------------------" << endl;
	std::cout << "["<<vec[0][1] << "," << vec[0][1 + 1] << "]";
		for (int i = 0; i < vec[0].size(); i++) {
			std::cout << vec[0][i] << "," << vec[0][i+ 1] << "]";
		
	}

}

struct TreeNode* printInOrderTree(TreeNode* root) {
	//cout << root->val;
	if (root->left != NULL) {
		printInOrderTree(root->left);
	}
	cout << root->val << ",";

	if (root->right != NULL) {
		printInOrderTree(root->right);
	}

}

struct TreeNode* createBT(vector<int> arr,int j) {
	TreeNode* node = new TreeNode(arr[j]);
	j += 1;
	if (j < arr.size()) {
		if (j % 2 == 0) {
			node->right = createBT(arr, j);
		}
		else {
			node->left = createBT(arr, j );
		}
	}
	
	return node;
	
}

int main() {

	vector<int> arr; // = { 3, 9, 20, NULL, NULL, 15, 7 };
	arr.assign({ 3, 9, 20, NULL,NULL, 15, 7 });


	TreeNode* root;
	root = createBT(arr, 0);
//	cout << printInOrderTree(createBT(arr, 0)) << endl;
	//cout << root->val << endl;

	Solution x;
	printVector(x.levelOrder(root));
	
	return 0;

}
