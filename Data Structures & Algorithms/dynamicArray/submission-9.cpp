class DynamicArray {
public:
    DynamicArray(int capacity) : size_(0), capacity_(capacity) {
        array_ = new int[capacity];
    }

    int get(int i) {
        return array_[i];
    }

    void set(int i, int n) {
        array_[i] = n;
    }

    void pushback(int n) {
        if (getSize() == getCapacity()) {
            resize();
        }

        array_[getSize()] = n;
        ++size_;
    }

    int popback() {
        int v = array_[getSize() - 1];
        --size_;
        return v;
    }

    void resize() {
        int* new_array = new int[getCapacity() * 2];

        for(int i{}; i < getSize(); ++i) {
            new_array[i] = array_[i];
        }

        delete[] array_;

        capacity_ *= 2;
        array_ = new_array;
    }

    int getSize() {
        return size_;
    }

    int getCapacity() {
        return capacity_;
    }


private: 
    int* array_;
    int size_;
    int capacity_;
};
