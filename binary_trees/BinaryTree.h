template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *right;
    BinaryTreeNode<T> *left;
    BinaryTreeNode(T data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
    }
    ~BinaryTreeNode()
    {
        delete right;
        delete left;
    }
};