//
// Created by 朱玥 on 2022/6/15.
//

#pragma once

/**
 * Definition for singly-linked list.
 *
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 双指针法
class Solution01 {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *tmp;
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur) {
      tmp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = tmp;
    }
    return pre;
  }
};

// 递归法
class Solution02 {
public:
  ListNode *reverse(ListNode *pre, ListNode *cur) {
    if (cur == nullptr) return pre;
    ListNode* tmp = cur->next;
    cur->next = pre;
    return reverse(cur, tmp);
  }
  ListNode* reverseList(ListNode* head) {
    return reverse(nullptr, head);
  }
};