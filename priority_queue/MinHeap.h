template <typename T>
class MinHeap
{
private:
    T *arr;
    int size;
    int capacity;
    int parent(int index)
    {
        return (index - 1) / 2;
    }
    int left(int index)
    {
        return 2 * index + 1;
    }
    int right(int index)
    {
        return 2 * index + 2;
    }
    void swap(T *ele1, T *ele2)
    {
        T temp = *ele1;
        *ele1 = *ele2;
        *ele2 = temp;
    }
    void heapify(int index)
    {
        int smallest = index;
        int li = left(index);
        int ri = right(index);
        if (li < size && arr[li] < arr[smallest])
        {
            smallest = li;
        }
        if (ri < size && arr[ri] < arr[smallest])
        {
            smallest = ri;
        }
        if (smallest != index)
        {

            swap(&arr[index], &arr[smallest]);
            heapify(smallest);
        }
    }

public:
    MinHeap()
    {
        size = 0;
        capacity = 1;
        arr = new T[1];
    }
    bool empty()
    {
        return size == 0;
    }
    int getSize()
    {
        return size;
    }
    T top()
    {
        return arr[0];
    }
    void push(T node)
    {
        if (size == capacity)
        {
            T *newArr = new T[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                newArr[i] = arr[i];
            }
            capacity = capacity * 2;
            delete[] arr;
            arr = newArr;
        }
        size++;
        arr[size - 1] = node;
        int index = size - 1;
        while (arr[index] < arr[parent(index)] && index != 0)
        {
            swap(&arr[index], &arr[parent(index)]);
            index = parent(index);
        }
    }
    void pop()
    {
        if (empty())
            return;
        if (size == 1)
        {
            size--;
            delete[] arr;
            return;
        }
        swap(&arr[0], &arr[size - 1]);
        size--;
        heapify(0);
    }
};