class Observer {
public:
    virtual void notify(string& itemName) = 0;
};

class Customer : public Observer {
private:
    string name;
    int notifications;

public:
    Customer(string& name) : name(name), notifications(0) {}

    void notify(string& itemName) override {
        notifications += 1;
    }

    int countNotifications() {
        return notifications;
    }
};

class OnlineStoreItem {
private:
    string itemName;
    int stock;

    std::unordered_set<Observer*> subs{};

public:
    OnlineStoreItem(string& itemName, int stock) : itemName(itemName), stock(stock) {}

    void subscribe(Observer* observer) {
        subs.insert(observer);
    }

    void unsubscribe(Observer* observer) {
        subs.erase(observer);
    }

    void updateStock(int newStock) {
        if (stock == 0 && newStock > 0) {
            for (auto& s : subs) {
                s->notify(itemName);
            }   
        }

        stock = newStock;
    }
};
