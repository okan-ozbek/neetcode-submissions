class LRUCache {
public:
    LRUCache(int capacity) : m_capacity{ capacity } {}
    
    [[nodiscard]]
    int get(int key) noexcept
    {
        if (m_capacity == 0) {
            return -1;
        }

        if (!m_lookup_table.contains(key)) { 
            return -1;
        }

        auto node = m_lookup_table[key];
        m_list.splice(m_list.end(), m_list, node);

        return node->second;
    }
    
    void put(int key, int value) noexcept
    {
        if (m_capacity == 0) {
            return;
        }

        if (m_lookup_table.contains(key)) {
            auto node = m_lookup_table[key];

            node->second = value;
            m_list.splice(m_list.end(), m_list, node);

            return;
        }

        if (m_lookup_table.size() == m_capacity) {
            auto node = m_list.begin();

            m_lookup_table.erase(node->first);
            m_list.erase(node);
        }

        m_list.push_back({ key, value });
        m_lookup_table.emplace(key, std::prev(m_list.end()));
    }

private:
    int m_capacity{};

    std::list<std::pair<int, int>> m_list;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_lookup_table;
};
