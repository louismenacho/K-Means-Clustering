#include "header.h"

PointList::PointList() {
    head = new PointNode(-9999,-9999);
}

void PointList::insertPoint (int x, int y) {
    PointNode* newPoint = new PointNode(x,y);
    if (head->next == NULL){
        head->next = newPoint;
    } else {
        PointNode* current = head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newPoint;
    }
}

void PointList::printList() {
    PointNode* current = head;
    while(current != NULL) {
        cout << "X: " << current->x;
        cout << " Y: " << current->y;
        cout << " ID: " << current->clusterLabel << endl;
        current = current->next;
    }
}
