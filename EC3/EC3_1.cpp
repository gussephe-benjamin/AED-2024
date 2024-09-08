class Node {
public:
    string keys[100];
    int numKeys;
    int count;
    Node* prev;
    Node* next;

    Node() : numKeys(0), count(0), prev(nullptr), next(nullptr) {}
    Node(int count) : numKeys(0), count(count), prev(nullptr), next(nullptr) {}

    int findKey(const string& key) {
        for (int i = 0; i < numKeys; ++i) {
            if (keys[i] == key) {
                return i;
            }
        }
        return -1;
    }

    void addKey(const string& key) {
        if (numKeys < 100) {
            keys[numKeys++] = key;
        }
    }

    bool removeKey(const string& key) {
        int index = findKey(key);
        if (index != -1) {
            keys[index] = keys[--numKeys];
            return true;
        }
        return false;
    }
};

class AllOne {
private:
    Node* head;
    Node* tail;

public:
    AllOne() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    void inc(const string& key) {
        Node* curr = head->next;
        while (curr != tail && curr->findKey(key) == -1) {
            curr = curr->next;
        }

        if (curr == tail) {
            Node* newNode = new Node(1);
            newNode->addKey(key);
            newNode->next = head->next;
            head->next->prev = newNode;
            newNode->prev = head;
            head->next = newNode;
        } else {
            curr->count++;
        }
    }

    void dec(const string& key) {
        Node* curr = head->next;
        while (curr != tail) {
            if (curr->findKey(key) != -1) {
                break;
            }
            curr = curr->next;
        }
        
        if (curr != tail) {
            curr->count--;
            if (curr->count == 0) {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
            }
        }
    }

    string getMaxKey() {
        if (tail->prev != head) {
            return tail->prev->keys[0];
        }
        return "";
    }

    string getMinKey() {
        if (head->next != tail) {
            return head->next->keys[0];
        }
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */