
#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<cstdlib>
#include<cmath>
using namespace std;

struct Entry
{
    double key;
    string value;
};
struct QuadNode
	{
		QuadNode *above;
		QuadNode *below;
		Entry        e;
		QuadNode *next;
		QuadNode *prev;
	};
class Dictionary
{
private:
    QuadNode *head;
    QuadNode *tail;
    QuadNode *srchHead;
    QuadNode *srchTail;
    int levelCount;
public:
    Dictionary();

    ~Dictionary();

    void Insert(Entry n);

    QuadNode *Find(double key) const;

    bool Erase(double key);

    bool empty();

    void LinkNodesAbove();

    void LinkNodesAcross();

    bool NewLevel()
    {
        int newLevel = rand() % 2;
        bool makeLevel;
        switch(newLevel)
        {
        case 0: makeLevel = false;
            break;
        case 1: makeLevel = true;
            levelCount++;
            break;
        }

        return makeLevel;
    }

    void PrintHeaders()
    {
    	for(int i = 0; i <= levelCount; i++)
    	{
    		cout << left << "Level " << setw(12) << i;
    	}

    	cout << endl;

    	for(int j = 0; j <= levelCount; j++)
    	{
    		cout << left << setw(18) << "-------";
    	}

    	cout << endl;
    }

    void PrintList()
    {
    	QuadNode *it = head;
    	QuadNode *refIt = it;

		while(refIt != tail)
		{
			for(int i = 0; i <= levelCount; i++)
			{
				cout << left;

				if(it != NULL)
				{
					if(it->e.key == 0)
					{
						cout << setw(18) << "-INFINITY";
					}
					else if(it->e.key == 999)
					{
						cout << setw(18) << "+INFINITY";
					}
					else
					{
						int nodeSpace = 15;

						if(it->e.key > 99)
							nodeSpace = 14;

						cout << it->e.key << "," << setw(nodeSpace)
							 << it->e.value;
					}

					it = it->above;
				}
				else
				{
					cout << setw(18) << "";
				}
			}
			cout << endl;
			refIt = refIt->next;
			it = refIt;
		}

		//output remaining dummy infinity nodes at each level
		for(int c = 0; c <= levelCount; c++)
		{
			cout << setw(18) << "+INFINITY";
		}
    }

    int Levels() const {return levelCount;}
};



#endif /* DICTIONARY_H_ */
