//
// Created by 朱玥 on 2022/6/15.
//

#pragma once
/*
 * 设计一个链表，实现以下功能：
 * (1)查询：get(idx)
 * (2)添加头节点：addAtHead(val)
 * (3)添加尾节点：addAtTail(val)
 * (4)指定位置添加节点：addAtIdx(idx, val)
 * (5)删除节点：deleteAtIdx(idx)
 * */

/*
 * 链表操作两种方式：
 * 1、直接使用原来的链表来进行操作
 * 2、设置一个虚拟头节点再进行操作
 * */
#include <iostream>

using namespace std;

class MyLinkedList {
public:
  // 定义链表节点结构体
  struct LinkedNode {
    int val;
    LinkedNode *next;
    LinkedNode(int val) : val(val), next(nullptr) {}
  };

  // 初始化链表
  MyLinkedList() {
    _dummyHead = new LinkedNode(
        0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
    _size = 0;
  }

  // 获取到第index个节点数值，如果index是非法数值直接返回-1，
  // 注意index是从0开始的，第0个节点就是头结点
  int get(int index) {
    if (index > (_size - 1) || index < 0) {
      return -1;
    }
    LinkedNode *cur = _dummyHead->next;
    while (index--) { // 如果--index 就会陷入死循环
      cur = cur->next;
    }
    return cur->val;
  }

  // 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
  void addAtHead(int val) {
    LinkedNode *newNode = new LinkedNode(val);
    newNode->next = _dummyHead->next;
    _dummyHead->next = newNode;
    _size++;
  }

  // 在链表最后面添加一个节点
  void addAtTail(int val) {
    LinkedNode *newNode = new LinkedNode(val);
    LinkedNode *cur = _dummyHead;
    while (cur->next != nullptr) {
      cur = cur->next;
    }
    cur->next = newNode;
    _size++;
  }

  // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
  // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
  // 如果index大于链表的长度，则返回空
  void addAtIndex(int index, int val) {
    if (index > _size) {
      return;
    }
    LinkedNode *newNode = new LinkedNode(val);
    LinkedNode *cur = _dummyHead;
    while (index--) {
      cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
    _size++;
  }

  // 删除第index个节点，如果index
  // 大于等于链表的长度，直接return，注意index是从0开始的
  void deleteAtIndex(int index) {
    if (index >= _size || index < 0) {
      return;
    }
    LinkedNode *cur = _dummyHead;
    while (index--) {
      cur = cur->next;
    }
    LinkedNode *tmp = cur->next;
    cur->next = cur->next->next;
    delete tmp;
    _size--;
  }

  // 打印链表
  void printLinkedList() {
    LinkedNode *cur = _dummyHead;
    while (cur->next != nullptr) {
      cout << cur->next->val << " ";
      cur = cur->next;
    }
    cout << endl;
  }

  LinkedNode *GetLinkedList() { return _dummyHead; }


private:
  int _size;
  LinkedNode *_dummyHead;
};
