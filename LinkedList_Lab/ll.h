#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
using namespace std;

class LinkedList {
  public:
    LinkedList();
    ~LinkedList();
    bool insert(unsigned uiData);
    bool remove(unsigned &pData);
    void print(ostream &stream);

  private:
    struct Link {
        unsigned m_uiData;
        Link *m_pNext;
        Link(unsigned uiData, Link *pNext);
    } *m_pHead;

};

ostream &operator<<(ostream &, LinkedList &);

#endif /* LINKED_LIST_H */
