LinkedListNode* reverse(LinkedListNode* head) {
  // no need to reverse if head is nullptr 
  // or there is only 1 node.
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  LinkedListNode* list_to_do = head->next;

  LinkedListNode* reversed_list = head;
  reversed_list->next = nullptr;

  while (list_to_do != nullptr) {
    LinkedListNode* temp = list_to_do;
    list_to_do = list_to_do->next;

    temp->next = reversed_list;
    reversed_list = temp;
  }

  return reversed_list;
}

int main() {
  vector<int> v1 = {7, 14, 21, 28};
  LinkedListNode* list_head = LinkedList::create_linked_list(v1);

  cout << "Original: ";
  LinkedList::display(list_head);
  list_head = reverse(list_head);
  cout << "After Reverse: ";
  LinkedList::display(list_head);

  vector<int> v2 = {28, 21, 14, 7};
  LinkedListNode* expected_list_head = LinkedList::create_linked_list(v2);
}
