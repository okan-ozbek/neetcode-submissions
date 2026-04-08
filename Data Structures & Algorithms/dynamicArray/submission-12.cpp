class DynamicArray {
public:
    DynamicArray(int capacity) 
        : array_{(int*)::operator new(sizeof(int) * capacity)}
        , capacity_{capacity} 
    {}

    int get(int i) {
        return array_[i];
    }

    void set(int i, int n) {
        array_[i] = n;
    }

    void pushback(int n) {
        if (size_ == capacity_) {
            resize();
        }

        array_[size_] = n;
        ++size_;
    }

    int popback() {
        return array_[--size_];
    }

    void resize() {
        int new_capacity = capacity_ * 2;
        int* new_array = (int*)::operator new(sizeof(int) * new_capacity);

        for(int i{}; i < size_; ++i) {
            new_array[i] = array_[i];
        }

        ::operator delete(array_, sizeof(int) * capacity_);

        capacity_ = new_capacity;
        array_ = new_array;
    }

    int getSize() {
        return size_;
    }

    int getCapacity() {
        return capacity_;
    }


private: 
    int* array_{nullptr};
    int size_{};
    int capacity_{};
};
