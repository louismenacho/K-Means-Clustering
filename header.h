#ifndef KMEANCLUSTER_HEADER_H
#define KMEANCLUSTER_HEADER_H

#include <iostream>
using namespace std;

class PointNode {
    friend class PointList;
    friend class KMean;
private:
    int x;
    int y;
    int clusterLabel;
    double distance;
    PointNode *next;
public:
    PointNode(int x, int y);
    void printNode();
};

class PointList {
    friend class KMean;
private:
    PointNode *head;
public:
    PointList();
    void printList();
    void insertPoint(int x, int y);
    PointNode* deletePoint();
};

class KMean {
    friend class PointList;
    struct xycoord{
        int x,y;
    };
private:
    int K;
    int numRow;
    int numCol;
    int **imageArray;
    bool pointsChangeLabel;
    xycoord *kCentroids;
    PointNode *listHead;
public:
    KMean(int K, int numRow, int numCol, PointList list);
    void cluster(ofstream& outfile1, ofstream& outfile2);
    void assignLabels();
    void createImage();
    void computeCentroids();
    void computeDistances();
    double distance(PointNode *point, xycoord centroid);
    void displayImage(ofstream& outfile2);
    void printPointInfo(ofstream& outfile1);
};


#endif //KMEANCLUSTER_HEADER_H
