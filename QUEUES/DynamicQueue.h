template <typename T>
class DynamicQueue
{
private:
    int capacity;
    int size;
    int frontIndex;
    int nextIndex;
    T *data;

public:
    DynamicQueue()
    {
        data = new T[1];
        capacity = 1;
        size = 0;
        nextIndex = 0;
        frontIndex = -1;
    }

    int getSize()
    {
        return size;
    }

    void enqueue(T x)
    {
        nextIndex = nextIndex % capacity;
        if (size == capacity)
        {
            T *newData = new T[capacity * 2];
            int j = 0;
            for (int i = frontIndex; i < capacity; i++)
            {
                newData[j++] = data[i];
            }
            for (int i = 0; i < frontIndex; i++)
            {
                newData[j++] = data[i];
            }
            delete[] data;
            data = newData;
            nextIndex = capacity;
            frontIndex = 0;
            capacity = 2 * capacity;
        }
        data[nextIndex] = x;
        nextIndex++;
        size++;
        if (frontIndex == -1)
            frontIndex = 0;
    }
    T dequeue()
    {
        if (size == 0)
        {
            cout << "\nUnderflow";
            return -1;
        }
        else if (size == 1)
        {
            int val = data[frontIndex];
            frontIndex = -1;
            nextIndex = 0;
            size--;
            return val;
        }
        else
        {
            int val = data[frontIndex];
            frontIndex = (frontIndex + 1) % capacity;
            size--;
            return val;
        }
    }
    bool isEmpty()
    {
        return size == 0;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "\nQueue is empty";
            return 0;
        }
        return data[frontIndex];
    }
};