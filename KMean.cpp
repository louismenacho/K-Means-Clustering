#include <math.h>
#include <time.h>
#include <fstream>
#include "header.h"

KMean::KMean(int K, int numRow, int numCol, PointList list) {
    this->K = K;
    this->numRow = numRow;
    this->numCol = numCol;
    listHead = list.head;
    kCentroids = new xycoord[K+1];
    //initialize imageArray
    imageArray = new int*[numRow];
    for(int i = 0; i < numRow; i ++){
        imageArray[i] = new int[numCol];
    }
    pointsChangeLabel = true;
}

void KMean::cluster(ofstream& outfile1, ofstream& outfile2) {
    //Step 1
    assignLabels();
    //Step 6 (loop)
    while(pointsChangeLabel) {
        //Step 2
        createImage();
        displayImage(outfile2);
        //Step 3
        computeCentroids();
        //Step 4
        computeDistances();
    }
    printPointInfo(outfile1);
}

void KMean::assignLabels() {
    PointNode* current = listHead->next;
    int label = 1;
    while(current != NULL) {
        if(label > K) {
            label = 1;
        }
        current->clusterLabel = label;
        label++;
        current = current->next;
    }
}

void KMean::createImage() {
    PointNode* current = listHead->next;
    while(current != NULL) {
        int x = current->x;
        int y = current->y;
        int label = current->clusterLabel;

        imageArray[y][x] = label;
        current = current->next;
    }
}

void KMean::displayImage(ofstream& outfile2) {
    outfile2 << "START IMAGE" << endl;
    for(int i = 0; i < numRow; i++){
        for(int j = 0; j < numCol; j++){
            if(imageArray[i][j] == 0) {
                outfile2 << " ";
            }
            else {
                outfile2 << imageArray[i][j];
            }
        }
        outfile2 << endl;
    }
    outfile2 << "END IMAGE" << endl;
}

void KMean::computeCentroids() {
    for(int i = 1; i <= K; i++){

        int xTotal = 0;
        int yTotal = 0;
        int xNumPoints = 0;
        int yNumPoints = 0;

        PointNode* current = listHead->next;
        while(current != NULL) {
            if(current->clusterLabel == i){
                int xcoord = current->x;
                int ycoord = current->y;
                xTotal += xcoord;
                yTotal += ycoord;
                xNumPoints++;
                yNumPoints++;
            }
            current = current->next;
        }
        if(xNumPoints != 0 && yNumPoints != 0) {
            kCentroids[i].x = xTotal / xNumPoints;
            kCentroids[i].y = yTotal / yNumPoints;
        }
    }
}

void KMean::computeDistances() {
    PointNode* current = listHead->next;
    pointsChangeLabel = false;
    //Step 5
    while(current != NULL){
        int currentLabel = current->clusterLabel;
        int minKGroup = current->clusterLabel;
        double minDistance;

        if(current->distance == -1) {
            minDistance = distance(current, kCentroids[1]);
        }
        else{
            minDistance = current->distance;
        }
        for(int i = 1; i <= K; i++){
            double dist = distance(current, kCentroids[i]);
            if(dist <= minDistance){
                minKGroup = i;
                minDistance = dist;
            }
        }
        if(minKGroup != currentLabel) {
            current->clusterLabel = minKGroup;
            current->distance = minDistance;
            pointsChangeLabel = true;
        }
        current = current->next;
    }
}

double KMean::distance(PointNode *point, xycoord centroid) {
    int xPoint = point->x;
    int yPoint = point->y;
    int xCentroid = centroid.x;
    int yCentroid = centroid.y;
    int xDist = abs(xPoint - xCentroid);
    int yDist = abs(yPoint - yCentroid);
    return sqrt(pow(xDist, 2.0) + pow(yDist, 2.0));
}

void KMean::printPointInfo(ofstream& outfile1){
    PointNode* current = listHead->next;
    outfile1 << "K :" << K << endl;
    outfile1 << "Number of Rows: " << numRow << endl;
    outfile1 << "Number of Columns: " << numCol << endl;
    while(current != NULL) {
        outfile1 << current->y << "\t ";
        outfile1 << current->x << "\t ";
        outfile1 << current->clusterLabel << endl;
        current = current->next;
    }
}
