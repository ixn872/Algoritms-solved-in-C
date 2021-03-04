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
    int f;
    int t;


    void print(vector <string> const& a) {

        for (int i = 0; i < a.size(); i++)
            cout << a.at(i) << "\n" << endl;
    }

    string addSpaces(string a, vector <string> const& b, int maxWidth) {

        cout << "WHAT ENTERED\n:"<<f;
        print(b);
        cout << "WHAT ENTERED\n";

        float cc = 0;
        int count=0;
       
        for (int i = 0; i < b.size(); i++) {           
                count = count+b.at(i).length();
            
        }
        cout << count << endl;
        int toAdd = maxWidth - count; // maybe absolute val
        string row;
        int x;
        double y;
        if (b.size() <= 1) {
            x = toAdd;
            y = 0;
        }
        else {
            x = ceil(toAdd / (b.size() - 1));
            if (x==0 & toAdd==0){
                x=0;
            }
            cout << toAdd << endl;
            if (x == 0 & toAdd!=0) {
                x = 0; 
                y = 1; //or zero
            }
            else {
                y = ceil(toAdd / x);
            }
        }
        cout << "Spaces to add: " << toAdd << " Number of words: " << b.size() << " How many spaces each separation will have: " << x << endl;

        string temp = " "; //standars
        string temp2 = ""; ////I think

        if (toAdd == 0 ) { //full

            for (int i = 1; i < b.size() - 1; i++) {
                row = row + " " + b.at(i);
            }
            row = row + " " + b.back();
            row = b.at(0) + row;
            return row;
        }
        

        for (int i = 1; i <= std::abs(x); i++) {

            temp2 = temp2 + " ";
        }

        cout << temp2.length() << endl; //ok
        if (f == 1) {
            cout << "FINAL ROW" << endl;
            row = b.at(0);
            for (int i = 1; i < b.size(); i++) {

                row =  row + " "+b.at(i);
            }
            row = row + temp2; //b.at(0) + temp2;
            cout << row << "\n";
            row.resize(maxWidth);
            return row;
        }
        if (y == 0) {
            cout << "One word" << endl;
            //row = temp2;
            //row = row + b.at(0);
            for (int i = 0; i < b.size(); i++) {

                row = temp2 + b.at(i) +row;
            }
            //b.at(0) + temp2;
            cout << row << "\n";
            //row.resize(maxWidth);
            return row;


        }

       
        for (int i = 1; i < b.size()-1; i++) {
            cout << "111111111111";
            row = row + temp2 + b.at(i);
            cout << row << "\n";
            if (i == b.size()-2) {
                row = b.at(0)+row;
                row = row + temp2+" "+ b.back();
                cout << row.length() << endl;
                return row;
            }
            
        }
        for (int i = y + 1; i < b.size(); i++) {
            cout << "2222222222222222";

            row = row + temp + b.at(i);
        }

        row = b.at(0) + row; //starting
        //row = row + b.back();

        cout << "Spaces added in temp spaces  " << temp2.length() << endl;




        return row;

    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // first row as benchmark. How many words can fit with space in between? But will try to solve straight forwardly to avoid complexity

        string row = "";
        vector<string> theLines = {};
        vector<string> currLines = {};
        vector<string> remLines = {};


        for (int i = 0; i < words.size(); i++) {
        //    cout <<  words.at(i)<<endl;

            cout << words.at(i) << endl;
            
            if (row.length() + words.at(i).length() + 1 <= maxWidth) {
                t = i;
                cout << "T: " << t << endl;
                print(currLines);
                currLines.push_back(words.at(i));
              
               // remLines = {};



                // remLines = {};
                // for (int j = i; j < words.size(); j++) {
                  //   remLines.push_back(words.at(j));
                 //}


                if (row == "") {
                    row = words.at(i);
                    continue;
                }
                else {
                    row = row + " " + words.at(i);
                }

            }


            if (row.length() + words.at(i + 1).length() + 1 > maxWidth) {


                theLines.push_back(addSpaces(row, currLines, maxWidth));
                
                row = "";
                currLines = {};
                //remLines = {};
                

            }

         

        }




       for (int j = t; j < words.size(); j++) {
                remLines.push_back(words.at(j));
                f = 1;
            }
        
        row = "";
        for (int i = 0; i < remLines.size(); i++) {
            row = row + remLines.at(i);
        }

        theLines.push_back(addSpaces(row, remLines, maxWidth));


        print(theLines);

        return theLines;

    }




};


    int main() {
        struct TreeNode* root = new TreeNode(4);
        root->left = new TreeNode(7);
        root->right = new TreeNode(2);
        root->left->left = new TreeNode(9);
        root->left->right = new TreeNode(6);
        root->right->left = new TreeNode(3);
        root->right->right = new TreeNode(1);

        vector<string> words = {"This", "is", "an", "example", "of", "text", "justification." };
        Solution myObj;
        myObj.fullJustify(words, 16);
        return 0;
    
}
