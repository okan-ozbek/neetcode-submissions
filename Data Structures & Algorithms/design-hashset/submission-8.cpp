class MyHashSet {
public:
    MyHashSet() : m_data{ static_cast<int*>(::operator new(DEFAULT_CAPACITY * sizeof(int))) } {
        std::fill_n(m_data, DEFAULT_CAPACITY, -1);
    }
    
    void add(const int key) {
        if (m_data[hash(key)] == -1) {
            m_data[hash(key)] == 0;
        }

        ++m_data[hash(key)];
    }
    
    void remove(const int key) {
        m_data[hash(key)] = -1;
    }
    
    bool contains(const int key) const {
        return (m_data[hash(key)] != -1);
    }

private: 
    constexpr static int DEFAULT_CAPACITY{ 1007 };

    int* m_data;

    const int hash(const int key) const {
        return key % DEFAULT_CAPACITY;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */