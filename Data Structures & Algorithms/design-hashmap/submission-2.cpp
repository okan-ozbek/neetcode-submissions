class MyHashMap {
public:
    MyHashMap() 
        : m_data{ static_cast<int*>(::operator new(DEFAULT_CAPACITY * sizeof(int))) }
        , m_capacity{ DEFAULT_CAPACITY }
    {
        for(std::size_t i{}; i < m_capacity; ++i) {
            m_data[i] = -1;
        }
    }
    
    void put(int key, int value) {
        m_data[key] = value;
    }
    
    int get(int key) {
        return m_data[key];   
    }
    
    void remove(int key) {
        m_data[key] = -1;
    }

private: 
    constexpr static std::size_t DEFAULT_CAPACITY{ 1000001 };

    int* m_data{ nullptr };
    std::size_t m_capacity{ DEFAULT_CAPACITY };
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */