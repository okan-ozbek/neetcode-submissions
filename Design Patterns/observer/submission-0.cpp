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
    vector<Observer*> subscriptions;

public:
    OnlineStoreItem(string& itemName, int stock) : itemName(itemName), stock(stock) {}

    void subscribe(Observer* observer) {
        subscriptions.push_back(observer);
    }

    void unsubscribe(Observer* observer) {
        for (int i{}; i < subscriptions.size(); i++) {
            if (subscriptions[i] == observer) {
                subscriptions.erase(subscriptions.begin() + i);
            }
        }
    }

    void updateStock(int newStock) {
        if (newStock == 0) {
            stock = newStock;
            return;
        }

        if (newStock > stock) {
            stock = newStock;
            for (auto o : subscriptions) {
                o->notify(itemName);
            }
        }
    }
};
