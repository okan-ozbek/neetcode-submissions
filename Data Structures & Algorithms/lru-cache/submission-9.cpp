class LRUCache {
public:
    using Key = int;
    using Value = int;
    using Capacity = int;

    struct CacheNode
    {
        Key key;
        Value value;
    };

    using LinkedList = std::list<CacheNode>;
    using Lookup = std::unordered_map<Key, LinkedList::iterator>;

    LRUCache(Capacity capacity) : m_capacity{ capacity }
    {
        m_lookup.reserve(capacity);
    }

    Value get(Key key) 
    {
        if (!m_lookup.contains(key)) {
            return -1;
        }

        auto it = m_lookup[key];

        m_list.splice(
            m_list.end(),
            m_list,
            it
        );

        return it->value;
    }
    
    void put(Key key, Value value) 
    {
        if (m_capacity == 0) {
            return;
        }

        if (m_lookup.contains(key)) {
            auto it = m_lookup[key];

            it->value = value;

            m_list.splice(
                m_list.end(),
                m_list,
                it
            );

            return;
        }

        if (m_lookup.size() == m_capacity) {
            auto head = m_list.begin();

            m_lookup.erase(head->key);
            m_list.erase(head);
        }

        m_list.push_back({ key, value });
        m_lookup[key] = std::prev(m_list.end());
    }

private:
    Capacity m_capacity{};

    LinkedList m_list;
    Lookup m_lookup;
};
