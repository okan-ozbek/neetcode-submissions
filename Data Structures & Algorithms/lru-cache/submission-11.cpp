class LRUCache {
public:
    using LinkedList = std::list<std::pair<int, int>>;
    using UnorderedMap = std::unordered_map<int, LinkedList::iterator>;

    LRUCache(int capacity) : _capacity{ capacity } {}
    
    int get(int key) 
    {
        if (!_lookupTable.contains(key)) {
            return -1;
        }  

        auto it = _lookupTable[key];

        _nodes.splice(_nodes.end(), _nodes, it);

        return it->second;
    }
    
    void put(int key, int value) 
    {
        if (_lookupTable.contains(key)) {
            auto it = _lookupTable[key];

            it->second = value;
            _nodes.splice(_nodes.end(), _nodes, it);

            return;
        }

        if (_lookupTable.size() >= _capacity) {
            auto it = _nodes.begin();

            _lookupTable.erase(it->first);
            _nodes.erase(it);
        }


        _nodes.push_back({ key, value });
        _lookupTable[key] = std::prev(_nodes.end());
    }

private:
    int _capacity{};

    LinkedList _nodes;
    UnorderedMap _lookupTable;
};
