#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

template <typename T>
class Queue {
    struct Node {
        T value;
        Node *next;

        explicit Node(const T &item) : value(item), next(nullptr) {}
    };

    Node *first;
    Node *last;

public:
    Queue() : first(nullptr), last(nullptr) {}

    Queue(const Queue &) = delete;
    Queue &operator=(const Queue &) = delete;

    ~Queue() {
        while (first != nullptr) {
            Node *removed = first;
            first = first->next;
            delete removed;
        }
    }

    bool empty() const {
        return first == nullptr;
    }

    void enqueue(const T &value) {
        Node *added = new Node(value);
        if (last == nullptr)
            first = added;
        else
            last->next = added;
        last = added;
    }

    T dequeue() {
        if (empty())
            throw underflow_error("Cannot dequeue from an empty queue");

        Node *removed = first;
        T value = removed->value;
        first = first->next;
        if (first == nullptr)
            last = nullptr;
        delete removed;
        return value;
    }

    const T &front() const {
        if (empty())
            throw underflow_error("Cannot read the front of an empty queue");
        return first->value;
    }
};

int main() {
    Queue<string> queue;
    queue.enqueue("first");
    queue.enqueue("second");
    queue.enqueue("third");

    cout << "Front: " << queue.front() << endl;
    while (!queue.empty())
        cout << "Dequeued: " << queue.dequeue() << endl;

    return 0;
}