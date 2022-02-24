#include "ll.h"
#include <cstdlib>
#include <iostream>

using namespace std;

LinkedList::Link::Link(unsigned uiData, Link *pNext) : m_uiData(uiData), m_pNext(pNext) { }

LinkedList::LinkedList() : m_pHead(nullptr) { }

LinkedList::~LinkedList() {
    while (m_pHead != nullptr) {
        remove(m_pHead->m_uiData);
    }
}

ostream &operator<<(ostream &stream, LinkedList &LinkedL) {
    LinkedL.print(stream);
    return stream;
}

void LinkedList::print(ostream &stream=cout) {
    Link *runner = m_pHead;
    while (runner != nullptr) {
        stream << runner->m_uiData << ' ';
        runner = runner->m_pNext;
    }
}

bool LinkedList::insert(unsigned uiData) {
    Link* new_link = new Link(uiData, m_pHead);            // Get a new node.
    m_pHead = new_link;            // Put it at the head.

    return true;                // Indicate success.
}

bool LinkedList::remove(unsigned &pData) {
    if (!m_pHead)                // Empty list?
    return false;                // Indicate failure.

    Link *temp = m_pHead;            // Point to the first node.
    m_pHead = m_pHead->m_pNext;    // Remove the first node.
    pData = temp->m_uiData;            // Obtain first node’s data.
    delete temp;
    return true;                // Indicate success.
}
