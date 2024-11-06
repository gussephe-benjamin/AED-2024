struct Node {
  int key;
  int val;
  Node *prev;
  Node *next;

  Node(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
  int capacity;
  int size;
  Node *head;
  Node *tail;

  void remove(Node *node) {
    if (node->prev) {
      node->prev->next = node->next;
    } else {
      head = node->next;
    }

    if (node->next) {
      node->next->prev = node->prev;
    } else {
      tail = node->prev;
    }
  }

  void push_front(Node *node) {
    node->next = head;
    node->prev = nullptr;
    if (head) {
      head->prev = node;
    }
    head = node;
    if (!tail) {
      tail = node;
    }
  }

  void pop_back() {
    if (tail) {
      Node *temp = tail;
      if (tail->prev) {
        tail = tail->prev;
        tail->next = nullptr;
      } else {
        head = tail = nullptr;
      }
      delete temp;
    }
  }

  Node *findNodeByKey(int key) {
    Node *curr = head;
    while (curr) {
      if (curr->key == key) {
        return curr;
      }
      curr = curr->next;
    }
    return nullptr;
  }

  void moveToFront(Node *node) {
    remove(node);
    push_front(node);
  }

public:
  LRUCache(int _capacity) : capacity(_capacity), size(0), head(nullptr), tail(nullptr) {}

  int get(int key) {
    Node *node = findNodeByKey(key);
    if (!node) {
      return -1;
    }
    moveToFront(node);
    return node->val;
  }

  void put(int key, int value) {
    Node *node = findNodeByKey(key);
    if (node) {
      node->val = value;
      moveToFront(node);
    } else {
      Node *newNode = new Node(key, value);
      if (size == capacity) {
        pop_back();
        --size;
      }
      push_front(newNode);
      ++size;
    }
  }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key, value);
 */