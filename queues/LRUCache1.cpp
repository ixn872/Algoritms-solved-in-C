//we use queue becuse we want FIFO


#include <map>
#include <deque>
class LRUCache {
    
private:
    int cap;
    map<int,int> cache; //key,value
    //deque<int> dq;
    list<int> dq;
public:
    LRUCache(int capacity) {
        cap=capacity;
        cache.clear();
        dq.clear();
        
    }
    
    int get(int key) {

        if (cache.find(key)==cache.end()){
            return -1;
        }

        else{
                       // deque<int>::iterator it = dq.begin();
// while (*it != key) {
 //               it++;
   //         }
            
                 // update queue: update it to most recent used value
            dq.remove(key);
            dq.push_front(key);
            
            // last.push_front(key);
            return cache[key];
        }
    }
    
    void put(int key, int value) {

        if(cache.find(key)==cache.end()){
            if(cache.size()==cap ){
            int rm = dq.back();
            dq.pop_back();
            cache.erase(rm);
        }
        }else{
            // present in cache, remove it from queue and map
       //     deque<int>::iterator it = dq.begin();
         //   while (*it != key) {
           //     it++;
          //  }
            
            dq.remove(key);
            cache.erase(key);
        }
           dq.push_front(key); 
           cache[key]=value;
           
        }
       
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
