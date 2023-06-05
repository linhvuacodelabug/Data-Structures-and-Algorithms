#include <iostream>
using namespace std;

// Khai bao cau truc cua mot node
class Node
{
public:
    int data;    // truyen du lieu vao 1 node
    Node *pNext; // con tro dung de lien ket cac node voi nhau
};

// Khai bao cau truc cua simple linked list
class List
{
public:
    Node *pHead; // node qly dau list
    Node *pTail; // node qly cuoi list
};

// Khoi tao cau truc simple linked list
void Create(List &l) //& tham chieu
{
    // cho 2 node tro den NULL - vi list rong
    l.pHead = NULL;
    l.pTail = NULL;
}

// Khoi tao node
Node *createNode(int x)
{
    Node *p = new Node; // cap phat vung nho cho p
    p->data = x;
    p->pNext = NULL;
    return p;
}

// Ham them node vao dau danh sach lien ket
void addHead(List &l, Node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p; // node dau la node cuoi cung la p
    }
    else
    {
        p->pNext = l.pHead; // Cho con tro cua node p lien ket den node dau - pHead
        l.pHead = p;        // cap nhat lai pHead la node p
    }
}

// Ham them node vao cuoi danh sach lien ket
void addTail(List &l, Node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p; // node dau la node cuoi cung la p
    }
    else
    {
        l.pTail->pNext = p; // Cho con tro cua pTai lien ket den node p
        l.pTail = p;        // cap nhat lai p la node ptail
    }
}

void insertAfter(List &l, int x, int pos)
{
    int count =1;
    Node *p = new Node();
    p->data=x;
    Node *k = l.pHead;
    while (count != pos)
    {
        count ++;
        k = k->pNext; 
    }
    p->pNext = k->pNext;
    k->pNext = p;
}

// printList list
void printList(List l)
{
    Node *k = l.pHead;
    while (k != NULL)
    {
        cout << k->data << " ";
        k = k->pNext;
    }

    // for (Node * k= l.pHead ; k != NULL; k=k->pNext)
    // {
    //      cout << k->data << " ";
    // }
}

int main()
{
    List l;
    Create(l); // khoi tao linked list

    int n;
    cout << "\nNhap so luong node can them: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "\nNhap node " << i + 1 << " ";
        cin >> x;
        Node *p = createNode(x); // khoi tao 1 node so nguyen
        addTail(l, p);
    }
    cout << endl;
    printList(l);
    insertAfter(l,0,3);
     cout << endl;
    printList(l);
    return 0;
}