#include "mem_r.hpp"
template <typename T> class Bilist {
  private:
    struct Node {
        T data;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> prev;

        Node(const T &value) : data(value) {}
    };

    using Allocator = std::pmr::polymorphic_allocator<Node>;

    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    Allocator allocator;

  public:
    class Iterator {
      public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T *;
        using reference = T &;

        explicit Iterator(std::shared_ptr<Node> node) : current(node) {}

        reference operator*() const { return current->data; }
        pointer operator->() { return &(current->data); }

        Iterator &operator++() {
            current = current->next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        Iterator &operator--() {
            current = current->prev;
            return *this;
            }

        Iterator operator--(int) {
            Iterator tmp = *this;
            --(*this);
            return tmp;
        }


        std::shared_ptr<Node> get_current() const { return current; }

        friend bool operator!=(const Iterator &a, const Iterator &b) {
            return a.current != b.current;
        }

        friend bool operator==(const Iterator &a, const Iterator &b) {
            return a.current == b.current;
        }

      private:
        std::shared_ptr<Node> current;
    };

    Bilist(const Allocator &alloc = Allocator{}) : allocator(alloc) {}

    void push_back(const T &value) {
        auto node = std::allocate_shared<Node>(allocator, value);
        if (!tail) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void push_front(const T &value) {
        auto node = std::allocate_shared<Node>(allocator, value);
        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

    void pop_back() {
        if (empty()) {
            throw std::runtime_error("ошибка на уровне поп бэка , рытаемся 'очищать ' пустой спсиок");
        }
        if (tail == head) {
            head.reset();
            tail.reset();
        } else {
            tail = tail->prev.lock();
            tail->next.reset();
        }
    }

    void pop_front() {
        if (empty()) {
            throw std::runtime_error("ошибка на уровне поп фронта , рытаемся 'очищать ' пустой спсиок");
        }
        if (tail == head) {
            head.reset();
            tail.reset();
        } else {
            head = head->next;
            head->prev.reset();
        }
    }

    T &at(size_t index) {
        auto it = begin();
        size_t count = 0;
        for (; it != end(); ++it, ++count) {
            if (count == index) {
                return *it;
            }
        }
        throw std::out_of_range("кпс проблемка на уровне at , что не не так с индексацией");
    }

    void insert(size_t index, const T &value) {
        if (index == 0) {
            push_front(value);
            return;
        }

        auto it = begin();
        size_t count = 0;
        for (; it != end(); ++it, ++count) {
            if (count == index - 1) {
                auto current = it.get_current();
                auto node = std::allocate_shared<Node>(allocator, value);
                node->next = current->next;
                node->prev = current;

                if (current->next) {
                    current->next->prev = node;
                } else {
                    tail = node;
                }
                current->next = node;
                return;
            }
        }

        if (count == index) {
            push_back(value);
            return;
        }

        throw std::out_of_range("проблема сл вставкой и индексом");
    }

    void erase(size_t index) {
        if (index == 0) {
            pop_front();
            return;
        }

        auto it = begin();
        size_t count = 0;
        for (; it != end(); ++it, ++count) {
            if (count == index) {
                auto current = it.get_current(); 
                auto prev_node = current->prev.lock();
                auto next_node = current->next;

                prev_node->next = next_node;
                if (next_node) {
                    next_node->prev = prev_node;
                } else {
                    tail = prev_node;
                }
                return;
            }
        }

        throw std::out_of_range("проблема на уровне erase, что то не так синдексацией");
    }

    Iterator begin() const { return Iterator(head); } // надо не делаь это не в инетатооре, а то не видно
    Iterator end() const { return Iterator(nullptr); }

    bool empty() const { return !head; }

    size_t size() const {
        size_t count = 0;
        for (auto it = head; it; it = it->next)
            count++;
        return count;
    }
};