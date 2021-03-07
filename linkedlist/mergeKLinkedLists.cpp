/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <queue>
#include <iostream> 
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

class Solution {
public:
  
    ListNode* sortedMerge(ListNode* a, ListNode* b){
        ListNode* result = NULL;
        if (a==NULL){
            return b;
        }
        else if (b==NULL){
            return a;
        }
        if (a->val<b->val){
            result=a;
            result->next=sortedMerge(a->next,b);
        }
        else{
            result=b;
            result->next= sortedMerge(a,b->next);
        }
        return result;
        
    }
    ListNode* mergeKListsHelper(vector<ListNode*>& arr,int last){
         while(last!=0){
                int i=0;
                int j = last;
                while(i<j){
                  
                    arr[i]=sortedMerge(arr.at(i),arr.at(j));

                    i++;
                    j--;

                }
              
            // If all pairs are merged, update last
            if (i >= j){
                last = j;
            }
            }
            
            return arr[0];
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
            int k = lists.size();

            if (lists.size()==0){
                return NULL;
            }
           
            return mergeKListsHelper(lists,k-1);
                
    };
     
        
         
            
        
        
    
};
