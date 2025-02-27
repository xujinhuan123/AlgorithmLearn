#include <iostream>

typedef struct node
{
    int data;
    struct node *next;
} Node;

class LinkList
{
private:
    Node *head;

public:
    LinkList() { head = NULL; }
    ~LinkList();

    bool clearSqlist();                    // 清空单向链表
    bool isEmpty();                        // 判断单向链表是否为空
    int length();                          // 返回单向链表的长度
    bool getElem(int i, int *e);           // 获取单向链表中第i个元素
    int locateElem(int e);                 // 返回元素e在单向链表中的位置
    bool priorElem(int cur_e, int *pre_e); // 返回元素cur_e的前驱
    bool nextElem(int cur_e, int *next_e); // 返回元素cur_e的后继
    bool insert(int i, int e);             // 在单向链表的第i个位置插入元素e
    bool Delete(int i, int *e);            // 删除单向链表的第i个元素，并用e返回其值
    bool Traverse(bool (*visit)(int e));   // 遍历单向链表
};

bool LinkList::getElem(int i, int *e) // 获取单向链表中第i个元素
{
    Node *p = head;
    int j = 0;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    *e = p->data;
    return true;
}

bool LinkList::insert(int i, int e) // 在单向链表的第i个位置插入元素e
{
    Node *p = head, *s;
    int j = 0;
    while (j < i - 1)
    {
        p = p->next;
        j++;
    }
    s = new Node;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

int main()
{
    int *temp = new int[100]{1, 2};
    std::cout << *temp << std::endl;
    delete[] temp;
    temp = nullptr;
    return 0;
}