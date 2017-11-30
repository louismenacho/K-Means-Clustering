#include "header.h"

PointNode::PointNode(int x, int y) {
    this->x = x;
    this->y = y;
    distance = -1;
    this->next = NULL;
}