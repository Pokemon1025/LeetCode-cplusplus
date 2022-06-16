//
// Created by 朱玥 on 2022/6/12.
//
#include <iostream>
#include <vector>

#include "206. Reverse_Linked_List/reverseLinkedList.h"
#include "List/707. Design_Linked_List.h"

using namespace std;

int main() {
  auto *linked_list = new MyLinkedList();
  // 初始化链表1->2->3->4->5->null
  linked_list->addAtHead(1);
  linked_list->addAtTail(5);
  for (int i = 1; i < 4; i++) {
    linked_list->addAtIndex(i, i + 1);
  }
  linked_list->printLinkedList();
  auto *alg = new Solution01();
  auto *reverse = alg->reverseList(
      reinterpret_cast<ListNode *>(linked_list->GetLinkedList()));
  while (reverse != nullptr && reverse->val != 0) {
    cout << reverse->val << " ";
    reverse = reverse->next;
  }
  cout << endl;
}
