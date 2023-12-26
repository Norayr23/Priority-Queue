#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include <vector>
#include <initializer_list>

template <typename T>
class Priority_Queue {
public:
    Priority_Queue() = default;
    Priority_Queue(const std::initializer_list<T>& list) {
        for (const auto& el : list) {
            push(el);
        }
    }
    void push(const T& value) {
        m_arr.push_back(value);
        if (!empty()) {
            int current = size() - 1;
            while (current >= 0 && m_arr[current] > m_arr[parent(current)]) {
                max_heapify(parent(current));
                current = parent(current);
            }
        }
    }
    void pop() {
        if (!empty()) {
            m_arr.front() = m_arr.back();
            m_arr.pop_back();
            max_heapify(0);
        }
    }
    const T& top() const { return m_arr.front(); }
    size_t size() const { return m_arr.size(); }
    bool empty() const { return m_arr.empty(); }
    void print() const {
        for (const auto& el : m_arr) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
private:
    void max_heapify(int i) {
        int l = leftChild(i);
        int r = rightChild(i);
        int largest = i;
        if (l < size() && m_arr[l] > m_arr[largest]) {
            largest = l;
        }
        if (r < size() && m_arr[r] > m_arr[largest]) {
            largest = r;
        }
        if (largest != i) {
            std::swap(m_arr[largest], m_arr[i]);
            max_heapify(largest);
        }
    }
    static constexpr int parent(int i) { return (i - 1) / 2; }
    static constexpr int leftChild(int i) { return 2 * i + 1; }
    static constexpr int rightChild(int i) { return 2 * i + 2; }
    std::vector<T> m_arr;    
};

#endif
