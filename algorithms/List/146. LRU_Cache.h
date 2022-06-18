//
// Created by 朱玥 on 2022/6/18.
//

#pragma once
/*
 * LRU核心：LRU 缓存算法的核心数据结构就是哈希链表，双向链表和哈希表的结合体。
 *
 * */
#include <iostream>
#include <unordered_map>
using namespace std;

// 双链表节点类
class Node {
public:
  int key, val;
  Node *next, *prev;
  Node(int _key, int _value)
      : key(_key), val(_value), next(nullptr), prev(nullptr) {}
  Node() : key(0), val(0), next(nullptr), prev(nullptr) {}
};

class LRUCache {
  // 数据一致性：同时维护一个双链表 cache 和一个哈希表 map
  // 在这两种数据结构之上提供一层抽象 api
private:
  Node *head, *tail; // 存储节点数据 头尾虚节点,不存贮值
  unordered_map<int, Node *> cacheMap; // 数据索引 key -> Node(key, val)
  int capacity;                        // 最大容量
public:
  LRUCache(int _cap) : capacity(_cap) {
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
  }
  void printList() {
    Node *p = head;
    while (p != nullptr) {
      cout << "(" << p->key << "," << p->val << ") ";
      p = p->next;
    }
    cout << endl;
  }

  int get(int key) {
    if (!cacheMap.count(key))
      return -1;
    auto node = cacheMap[key];
    removeNode(node);
    return node->val;
  }

  void put(int key, int val) {
    if (!cacheMap.count(key)) {
      // 新插入的数据为最近使用的数据
      addRecently(key, val);
      if (cacheMap.size() > capacity)
        removeLeastRecently();
    } else {
      auto node = cacheMap[key];
      removeNode(node);
      node->val = val;
    }
  }

private:
  // 构建双链表,因需删除操作
  // 添加节点
  void insertNode(Node *n) {
    n->next = head->next;
    n->prev = head;
    head->next->prev = n;
    head->next = n;
  }

  // 删除节点
  void deleteNode(Node *n) {
    n->prev->next = n->next;
    n->next->prev = n->prev;
  }

  // 移动节点,将某个 n 提升为最近使用的
  void removeNode(Node *n) {
    deleteNode(n); // 先从链表中删除这个节点
    insertNode(n); // 重新插到队尾
  }

  // 添加最近使用的元素
  void addRecently(int key, int val) {
    auto n = new Node(key, val);
    // 链表尾部就是最近使用的元素
    insertNode(n);
    // map中添加key映射
    cacheMap[key] = n;
  }

  // 删除最久未使用的元素
  void removeLeastRecently() {
    auto deletedNode = tail->prev;
    // 链表头部的第一个元素就是最久未使用的
    deleteNode(deletedNode);
    // 同时别忘了从 map 中删除它的 key
    cacheMap.erase(deletedNode->key);
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */