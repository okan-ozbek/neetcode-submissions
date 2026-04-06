class DynamicArray {
public:
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
        int* newArr = new int[capacity * 2];
        for(int i{}; i < capacity; ++i) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        capacity *= 2;
        arr = newArr;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;
    }


private: 
    int* arr;
    int length;
    int capacity;
};
