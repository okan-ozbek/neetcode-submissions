class MyHashSet {
public:
    MyHashSet() : m_data(1000001, -1) {}
    
    void add(int key) {
        if (m_data[key] == -1) {
            m_data[key] == 0;
        }

        ++m_data[key];
    }
    
    void remove(int key) {
        m_data[key] = -1;
    }
    
    bool contains(int key) {
        return (m_data[key] != -1);
    }

private: 
    std::vector<int> m_data;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */