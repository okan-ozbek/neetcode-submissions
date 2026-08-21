class LRUCache {
public:
    LRUCache(int capacity) : m_capacity{ capacity } {}
    
    int get(int key) 
    {
        if (!m_lookup.contains(key)) {
            return -1;
        }

        auto it = m_lookup[key];

        m_nodes.splice(m_nodes.end(), m_nodes, it);

        return it->second;
    }
    
    void put(int key, int value) 
    {
        if (m_capacity == 0) {
            return;
        }

        if (m_lookup.contains(key)) {
            auto it = m_lookup[key];

            it->second = value;
            m_nodes.splice(m_nodes.end(), m_nodes, it);

            return;
        }

        if (m_capacity == m_lookup.size()) {
            auto it = m_nodes.begin();

            m_lookup.erase(it->first);
            m_nodes.erase(it);
        }

        m_nodes.push_back({ key, value });
        m_lookup[key] = std::prev(m_nodes.end());
    }

private:
    int m_capacity{};

    std::list<std::pair<int, int>> m_nodes;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_lookup;
};
