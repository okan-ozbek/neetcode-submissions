class MyHashMap {
public:
    MyHashMap() : m_data{ static_cast<int*>(::operator new(DEFAULT_CAPACITY * sizeof(int))) } {
        std::fill_n(m_data, DEFAULT_CAPACITY, -1);
    }

    MyHashMap(const MyHashMap&) = delete;
    MyHashMap(MyHashMap&&) noexcept = delete;

    ~MyHashMap() { 
        delete[] m_data; 
    }

    MyHashMap& operator=(const MyHashMap&) = delete;
    MyHashMap& operator=(MyHashMap&&) noexcept = delete;

    void put(int key, int value) {
        m_data[hash(key)] = value;
    }
    
    int get(int key) const {
        return m_data[hash(key)];   
    }
    
    void remove(int key) {
        m_data[hash(key)] = -1;
    }

private: 
    constexpr static std::size_t DEFAULT_CAPACITY{ 1007 };

    int* m_data;

    int hash(int key) const {
        return key % DEFAULT_CAPACITY;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */