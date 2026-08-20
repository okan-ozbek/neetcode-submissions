class LRUCache {
public:
    using Key = int;
    using Value = int;
    using Capacity = int;

    struct CacheNode
    {
        Key key;
        Value value;
        CacheNode* next{ nullptr };
        CacheNode* prev{ nullptr };

        CacheNode(Key key, Value value) : key{ key }, value{ value } {}
    };

    using Nodes = std::unordered_map<Key, CacheNode*>;

    LRUCache(Capacity capacity) : m_capacity{ capacity }
    {
        m_nodes.reserve(capacity);
    }

    ~LRUCache() 
    {
        auto* node = m_head;
        while (node != nullptr) {
            auto* next = node->next;
            delete node;
            node = next;
        }
    }
    
    Value get(Key key) 
    {
        if (!m_nodes.contains(key)) {
            return -1;
        }

        auto* node = m_nodes[key];

        SetTail(node);

        return node->value;
    }
    
    void put(Key key, Value value) 
    {
        if (m_nodes.contains(key)) { 
            auto* node = m_nodes[key];

            node->value = value;

            SetTail(node);

            return;
        }

        if (m_nodes.size() >= m_capacity) {
            auto* node = m_head;

            Remove(node);

            m_nodes.erase(node->key);

            delete node;
        }

        auto* node = new CacheNode(key, value);

        if (m_head == nullptr && m_tail == nullptr) {
            m_head = node;
            m_tail = node;
        } 
        else {
            m_tail->next = node;
            node->prev = m_tail;
            m_tail = node;
        }

        m_nodes[key] = node;
    }

private:
    CacheNode* m_head{ nullptr };
    CacheNode* m_tail{ nullptr };

    Capacity m_capacity;
    Nodes m_nodes;

    void Remove(CacheNode* node)
    {
        if (node->prev != nullptr) {
            node->prev->next = node->next;
        } else {
            m_head = node->next;
        }

        if (node->next != nullptr) {
            node->next->prev = node->prev;
        } else {
            m_tail = node->prev;
        }

        node->prev = nullptr;
        node->next = nullptr;
    }

    void AddTail(CacheNode* node)
    {
        node->prev = m_tail;
        node->next = nullptr;

        if (m_tail != nullptr) {
            m_tail->next = node;
        } else {
            m_head = node;
        }

        m_tail = node;
    }

    void SetTail(CacheNode* node)
    {
        if (node == m_tail) {
            return;
        }

        Remove(node);
        AddTail(node);
    }
};
