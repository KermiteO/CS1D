#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include<iostream>
#include<iomanip>
#include<string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <list>
#include <queue>
#include "patient.h"
using namespace std;


template<typename E>
class PriorityQueue
{
public:
    PriorityQueue() {}

    int Size() const {return pList.size();}

    bool IsEmpty() const{return(pList.empty());}

    void Insert(const E& e)
    {
        typename list<E>::iterator i = pList.begin();

        while(i != pList.end() && !isMore(e, *i))
        {
            ++i;
        }

        pList.insert(i, e);
    }

    const E& max() const{return pList.front();}

    void RemoveMax() {pList.erase(pList.begin());}

    list<E> GetList() const {return pList;}

    void DoGoodsDay()
    {
        double currTime = 0; //appointments start at "12:00" or 0 secs
        double appEnd;

        auto it = pList.begin();

        cout << left << setw(17) << "PATIENT"
                     << setw(6)  << "START" << "END\n"
                     << setw(17) << "-------"
                     << setw(6) << "-----" << "---\n";

        while(!pList.empty())
        {
            double appStart = currTime;

            cout << setw(17) << it->GetName()
                 << setw(6) << it->PrintTime(appStart);

            while(currTime < appStart + it->GetAppTime())
            {
                if(currTime == 22)
                {
                    it->ChangeAppTime(currTime, appStart);
                    Patient bobDying("Bob Bleeding", 8);
                    Insert(bobDying);

                    appStart = currTime;
                }
                else if(currTime == 105)
                {
                    it->ChangeAppTime(currTime, appStart);
                    Patient sidDying("Sid Sickly", 8);
                    Insert(sidDying);

                    appStart = currTime;
                }

                currTime++;
            }

            it = pList.begin();

            if(pList.front().GetName() == "Bob Bleeding"
            || pList.front().GetName() == "Sid Sickly")
            {
                appEnd = appStart + 20;

                cout << "\n*** LIFE THREATENED!!! ***\n";

                cout << setw(17) << it->GetName()
                     << setw(6) << it->PrintTime(appStart)
                     << it->PrintTime(appEnd) << endl;

                currTime = appEnd;
            }
            else
            {
                appEnd = currTime;

                cout << it->PrintTime(appEnd) << endl;
            }

            RemoveMax();

            it = pList.begin();
        }
    }

    void DoGoodsStl()
    {
        double currTime = 0; //appointments start at "12:00" or 0 secs
        double appEnd;

        Patient it = list.top();

        cout << left << setw(17) << "PATIENT"
                     << setw(6)  << "START" << "END\n"
                     << setw(17) << "-------"
                     << setw(6)  << "-----" << "---\n";

        while(!list.empty())
        {
            double appStart = currTime;

            cout << setw(17) << it.GetName()
                 << setw(6) << it.PrintTime(appStart);

            while(currTime < appStart + it.GetAppTime())
            {
                if(currTime == 22)
                {

                    it.ChangeAppTime(currTime, appStart);

                    list.pop();

                    list.push(it);

                    Patient bobDying("Bob Bleeding", 8);
                    list.push(bobDying);

                    appStart = currTime;
                }
                else if(currTime == 105)
                {
                    it.ChangeAppTime(currTime, appStart);

                    list.pop();

                    list.push(it);

                    Patient sidDying("Sid Sickly", 8);
                    list.push(sidDying);

                    appStart = currTime;
                }

                currTime++;
            }

            it = list.top();

            if(list.top().GetName() == "Bob Bleeding"
            || list.top().GetName() == "Sid Sickly")
            {
                appEnd = appStart + 20;

                cout << "\n*** LIFE THREATENED!!! ***\n";

                cout << setw(17) << it.GetName()
                     << setw(6) << it.PrintTime(appStart)
                     << it.PrintTime(appEnd) << endl;

                currTime = appEnd;
            }
            else
            {
                appEnd = currTime;

                cout << it.PrintTime(appEnd) << endl;
            }

            list.pop();

            it = list.top();
        }
    }

    void AddPatients(vector<Patient> x)
    {
        for(unsigned int i = 0; i < x.size(); i++)
        {
            list.push(x[i]);
        }
    }

private:
    list<E> pList;
    priority_queue<Patient, vector<Patient> , Compare> list;

    bool isMore(Patient p, Patient q) {return p.GetWaitHrs() > q.GetWaitHrs();}
};

#endif // PRIORITYQUEUE_H
