public class DynamicArray {
    private int[] array;
    private int size;
    private int capacity;
    
    public DynamicArray(int capacity) {
        this.array = new int[capacity];

        this.size = 0;
        this.capacity = capacity;
    }

    public int Get(int i) {
        return array[i];
    }

    public void Set(int i, int n) {
        array[i] = n;
    }

    public void PushBack(int n) {
        if (size == capacity) {
            Resize();
        }

        array[size] = n;
        ++size;
    }

    public int PopBack() {
        if (size > 0) {
            --size;
        }

        return array[size];
    }

    private void Resize() {
        int[] newArray = new int[capacity * 2];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }

        array = newArray;
        capacity *= 2;
    }

    public int GetSize() {
        return size;
    }

    public int GetCapacity() {
        return capacity;
    }
}
