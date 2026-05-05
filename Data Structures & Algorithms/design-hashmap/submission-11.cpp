class MyHashMap {
public:
    MyHashMap() : m_data{ static_cast<int*>(::operator new(DEFAULT_CAPACITY * sizeof(int))) } {
        std::fill_n(m_data, DEFAULT_CAPACITY, -1);
    }

    ~MyHashMap() { 
        delete[] m_data; 
    }
    
    void put(int key, int value) {
        m_data[key] = value;
    }
    
    int get(int key) {
        std::cout << "Value for key: " << key << " is " << m_data[key] << std::endl;
        return m_data[key];   
    }
    
    void remove(int key) {
        m_data[key] = -1;
    }

private: 
    constexpr static std::size_t DEFAULT_CAPACITY{ 1000001 };

    int* m_data;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */