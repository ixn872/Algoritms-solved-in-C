vector<int> find_max_sliding_window(vector<int>& v, int window_size) {
  vector<int> result;
  
  if (v.size() > 0) {
    if ( window_size > v.size()) {
      return result;
    }

    deque<int> window;

    //find out max for first window
    for(int i = 0; i < window_size; ++i) {
      while(!window.empty() && v[i] >= v[window.back()]) {
        window.pop_back();
      }

      window.push_back(i);
    }
    result.push_back(v[window.front()]);
    for (int i = window_size; i < v.size(); ++i) {

      //remove all numbers that are smaller than current number
      //from the tail of list
      while(!window.empty() && v[i] >= v[window.back()]) {
        window.pop_back();
      }

      //remove first number if it doesn't fall in the window anymore
      if(!window.empty() && window.front() <= i - window_size ) {
        window.pop_front();
      }

      window.push_back(i);
      result.push_back(v[window.front()]);
    }
    return result;
  }
  else
    return result;
}

int main(int argc, const char * argv[])
{
  // defining first array
  vector<int> x = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // 

  // printing first array
  cout << "Array = ";
  for (int i=0; i<x.size(); ++i)
    cout << x[i] << ", ";
  cout << endl;

  auto res1 = find_max_sliding_window(x, 3);
  
  //printing the first result 
  cout << "Max = ";
  for(int i=0; i<res1.size(); ++i)
    cout << res1[i] << ", ";
  cout << endl;
  
  // defining second array
  x = {10, 6, 9, -3, 23, -1, 34, 56, 67, -1, -4, -8, -2, 9, 10, 34, 67};

  //printing the second array
  cout << "Array = ";
  for (int i = 0; i < x.size(); ++i)
    cout << x[i] << ", ";
  cout << endl;

  auto res2 = find_max_sliding_window(x, 3);
  
  //printing the second result
  cout << "Max = ";
  for(int i = 0; i < res2.size(); ++i)
    cout << res2[i] << ", ";
  cout << endl;

  return 0;
}
