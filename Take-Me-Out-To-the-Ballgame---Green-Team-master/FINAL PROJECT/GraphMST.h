/**********************************************************
 * AUTHOR         : Wyndal S. & Omar Kermiche
 * Assignment #12 : Dijkstra's & MST Algorithm
 * CLASS          : CS 1D
 * SECTION        : MW 3:00p - 4:50p / 5:00p-6:20p
 * DUE DATE       : 4/24/2017
 **********************************************************/

#ifndef GRAPHMST_H_
#define GRAPHMST_H_

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <limits.h>
#include <QVector>
#include <QTextBrowser>
#include <sstream>
#include "stadiumstruct.h"
#include <qdebug.h>

using namespace std;

const int MAX_CITIES = 32;

class GraphMST
{
public:

	// Constructor
	GraphMST();

	// Destructor
	~GraphMST();

	// MUTATORS
    void insertEdge(const QString inCity1, const QString inCity2, const int inDistance);
    void insertVertex(const QString inCity);

	//Accessors
    void primMST(QTextBrowser *inTable);
    void ReadInfo(QVector<DistanceInfo> edgeList);
    bool CityExists(const QString& inCity);
    void DisplayMST(int parent[], int n, QTextBrowser *inTable);

private:
    int vertexCount;
    QString vertexList[MAX_CITIES];
    int graph[MAX_CITIES][MAX_CITIES];

	int minKey(int key[], bool mstSet[]);

};

#endif /* GRAPHMST_H_ */
