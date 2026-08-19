class CacheNode
{
public:
    CacheNode(int key, int value) 
        : m_key{ key }
        , m_value{ value } 
    {}

    int m_key;
    int m_value;

    CacheNode* m_next{ nullptr };
    CacheNode* m_prev{ nullptr };
};

class LRUCache {
public:
    LRUCache(int capacity) : m_capacity{ capacity }
    {
        m_nodes.reserve(capacity);
    }
    
    int get(int key) {
        auto it = m_nodes.find(key);

        if (it == m_nodes.end()) {
            return -1;
        }

        auto* node = it->second;

        ToTail(node);
        return node->m_value;
    }
    
    void put(int key, int value) {
        if (m_nodes.contains(key)) {
            auto* node = m_nodes[key];
            node->m_value = value;

            ToTail(node);

            return;
        }

        if (m_nodes.size() >= m_capacity) {
            auto* node = m_head;
            
            m_head = m_head->m_next;

            if (m_head != nullptr) {
                m_head->m_prev = nullptr;
            } else {
                m_tail = nullptr;
            }

            m_nodes.erase(node->m_key);
            delete node;
        }

        auto* node = new CacheNode(key, value);

        if (m_tail != nullptr) {
            m_tail->m_next = node;
            node->m_prev = m_tail;
        }
        
        m_tail = node;

        if (m_head == nullptr) {
            m_head = node;
        }

        m_nodes[key] = node;
    }

private:
    CacheNode* m_head{ nullptr };
    CacheNode* m_tail{ nullptr };
    std::unordered_map<int, CacheNode*> m_nodes;
    int m_capacity;

    void ToTail(CacheNode* node)
    {
        if (node == m_tail) {
            return;
        }

        if (node->m_prev != nullptr) {
            node->m_prev->m_next = node->m_next;
        } else {
            m_head = node->m_next;
        }

        if (node->m_next != nullptr) {
            node->m_next->m_prev = node->m_prev;
        } 

        node->m_prev = m_tail;
        node->m_next = nullptr;

        m_tail->m_next = node;
        m_tail = node;
    }

    // hashmap for o1 lookup
    // linked list for prio
    // [i1]->[i2]->[i3] 
    // h = lru
    // t = ru
    // if i1 get() called
    // [i2]->[i3]->[i1]
};
