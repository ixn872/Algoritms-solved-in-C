LinkedListNode* remove_duplicates(LinkedListNode* head) 
{
  if (head == nullptr) {
    return head;
  }

  std::unordered_set<int> dup_set;
  LinkedListNode* curr = head;
  dup_set.insert(curr->data);

  while (curr->next != nullptr) {
    if (dup_set.find(curr->next->data) == dup_set.end()) {
      // Element not found in set, let's add it.
      dup_set.insert(curr->next->data);
      curr = curr->next;
    }
    else {
      // Duplicate node found. Let's remove it from the list.
      LinkedListNode* temp = curr->next;
      curr->next = curr->next->next;
      delete temp;
    }
  }
  return head;
}

int main() {
    vector<int> v1 = {4, 7, 4, 9, 7, 11, 4};
    vector<int> v2 = {4, 7, 9, 11};
    LinkedListNode* list_head = LinkedList::create_linked_list(v1);
    LinkedListNode* expected_list_head = LinkedList::create_linked_list(v2);
    
    cout << "Original: ";
    LinkedList::display(list_head);
    list_head = remove_duplicates(list_head);
    
    cout << "After removing duplicates: ";
    LinkedList::display(list_head);
    assert(LinkedList::is_equal(list_head, expected_list_head));
}
