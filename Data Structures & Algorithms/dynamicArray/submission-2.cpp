class DynamicArray {
public:
    int* arr;
    int length;
    int capacity;

    DynamicArray(int capacity) : length(0), capacity(capacity) {
        arr = new int[capacity];
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (length == capacity) {
            resize();
        }

        arr[length] = n;
        ++length;
    }

    int popback() {
        int v = arr[length - 1];
        --length;
        return v;
    }

    void resize() {
        auto* oldArr = arr;
        arr = new int[capacity * 2];
        capacity = capacity * 2;

        for (int i{}; i < length; ++i) {
            arr[i] = oldArr[i];
        }
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;
    }
};
