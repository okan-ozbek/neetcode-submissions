class MyCircularQueue {
public:
    MyCircularQueue(int k) 
        : m_data{ static_cast<int*>(::operator new(k * sizeof(int))) }
        , m_capacity{ k }
    {}
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        m_data[m_last] = value;
        m_last = (m_last + 1) % m_capacity;
        ++m_size;

        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        std::move(m_data[m_first]);
        m_first = (m_first + 1) % m_capacity;
        --m_size;

        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return m_data[m_first];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        return m_data[(m_last + m_capacity - 1) % m_capacity];
    }
    
    bool isEmpty() {
        return (m_size == 0);
    }
    
    bool isFull() {
        return (m_size == m_capacity);
    }

private:
    constexpr static int DEFAULT_VALUE{ 10 };

    int* m_data{ nullptr };
    int m_capacity{ DEFAULT_VALUE };
    int m_size{ 0 };
    int m_first{ 0 };
    int m_last{ 0 };
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */