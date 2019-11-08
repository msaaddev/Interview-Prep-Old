#include <iostream>
using namespace std;

class cNode
{
private:
    int data;

public:
    cNode *nextNode;
    cNode() : nextNode(NULL) {}
    cNode(int d) : data(d) {}
    int getData() const { return data; }
    void *setData(int data) { this->data = data; }
    void print() const { cout << data << " "; }
};

class cList
{
public:
    cNode *headNode;
    int count;
    cList() : headNode(NULL), count(0) {}

    cList(cNode *ptr) : headNode(ptr), count(1)
    {
        headNode->nextNode = NULL;
    }

    bool isNotEmpty()
    {
        if (headNode)
            return true;
        else
            return false;
    }

    bool isEmpty()
    {
        if (headNode)
            return false;
        else
            return true;
    }

    int getCount() const
    {
        return count;
    }

    cList &insert(cNode *&ptr)
    {
        if (!headNode)
        {
            headNode = ptr;
            ptr->nextNode = NULL;
        }
        else
        {
            ptr->nextNode = headNode;
            headNode = ptr;

            ++count;
        }
        ptr = NULL;
        return *this;
    }

    void print() const
    {
        cNode *ptr = headNode;
        while (ptr)
        {
            cout << ptr->getData() << endl;
            ptr = ptr->nextNode;
        }
        ptr = NULL;
    }

    cList &reverse()
    {
        if (count < 2)
            return *this;

        cNode *rptr, **arr = new cNode *[count];
        rptr = headNode;

        for (int i = 0; i < count; ++i)
        {
            arr[i] = rptr;
            rptr = rptr->nextNode;
        }

        for (int i = 1; i < count; ++i)
        {
            arr[i]->nextNode = arr[i - 1];
        }

        arr[0]->nextNode = NULL;
        headNode = arr[count - 1];
        delete[] arr;
        return *this;
    }

    cList operator=(const cList &rObj)
    {
        if (this == &rObj)
            return *this;

        if (true)
        {
            cList temp;
            temp.headNode = headNode;
        }

        if (true)
        {
            cList temp(rObj);
            headNode = temp.headNode;
            count = temp.getCount();
            temp.headNode = NULL;
        }
    }
};

cList addTwoNumbers(cList l1, cList l2, cList &newList)
{
    cNode *rptr = l1.headNode;
    int num1, sum1 = 0, num2, sum2 = 0, i = 1, totalSum, numbers[10] = {-1};

    while (rptr != NULL)
    {
        num1 = rptr->getData() * i;
        i *= 10;
        sum1 = sum1 + num1;
        rptr = rptr->nextNode;
    }

    rptr = l2.headNode;
    i = 1;
    while (rptr != NULL)
    {
        num2 = rptr->getData() * i;
        i *= 10;
        sum2 = sum2 + num2;
        rptr = rptr->nextNode;
    }

    totalSum = sum1 + sum2;

    while (totalSum != 0)
    {
        int remainder = totalSum % 10;
        cNode *newNode = new cNode(remainder);
        newList.insert(newNode);
        totalSum = (totalSum - remainder) / 10;
    }

    newList.reverse();
    return newList;
}
int main()
{
    cList l1, l2, result;
    cNode *node1 = new cNode(3);
    cNode *node2 = new cNode(4);
    cNode *node3 = new cNode(2);
    cNode *node4 = new cNode(4);
    cNode *node5 = new cNode(6);
    cNode *node6 = new cNode(5);

    l1.insert(node1).insert(node2).insert(node3);
    l2.insert(node4).insert(node5).insert(node6).print();

    cout << "-----------" << endl;

    result = addTwoNumbers(l1, l2, result);

    result.print();
}