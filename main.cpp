//Louis Menacho

#include <iostream>
#include <fstream>
#include "header.h"

using namespace std;

int main(int argc, char * argv[]) {
    ifstream infile(argv[1]);
    int K;
    int numRow;
    int numCol;
    int x;
    int y;
    PointList list = PointList();

    int number;
    int control = -3;

    while(infile >> number){
        if(control == -3){
            K = number;
            control++;
        }
        else if(control == -2){
            numRow = number;
            control++;
        }
        else if(control == -1){
            numCol = number;
            control++;
        }
        else if(control == 0){
            y = number;
            control++;
        }
        else if(control == 1){
            x = number;
            list.insertPoint(x,y);
            control--;
        }
    }
    ofstream outfile1;
    ofstream outfile2;
    outfile1.open(argv[2]);
    outfile2.open(argv[3]);

    KMean kMean(K, numRow, numCol, list);
    kMean.cluster(outfile1, outfile2);

    outfile1.close();
    outfile2.close();

    return 0;
}