#ifndef PATIENT_H
#define PATIENT_H

#include<iostream>
#include<iomanip>
#include<string>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<sstream>
using namespace std;

class Patient
{
private:
    string name;
    double waitHrs;
    double appTime;

public:
    Patient(string n, double h){name = n; waitHrs = h; appTime = 20;}

    ~Patient() {}

    double GetWaitHrs() const {return waitHrs;}

    string GetName() const {return name;}

    double GetAppTime() const {return appTime;}

    void ChangeAppTime(double& currTime,
                       double& startTime)
    {
        double subtractFrom;

        subtractFrom = currTime - startTime;

        appTime -= subtractFrom;
    }

    string PrintTime(double currT)
    {
        string hrs;
        string min;

        if(currT == 0)
        {
            hrs = "12:";
            min = "00";
        }
        else if(currT > 0 && currT < 60)
        {
            hrs = "12:";

            ostringstream convert;

            convert << currT;

            min = convert.str();
        }
        else if(currT == 60)
        {
            hrs = "1:";
            min = "00";
        }
        else if(currT > 60)
        {
            hrs = "1:";

            double temp = currT - 60;

            if(temp > 60 && temp < 120)
                temp -= 60;
            else if(temp > 120)
                temp -= 120;
            else if(temp == 120)
                hrs = "2:";

            ostringstream convert;

            convert << temp;

            if(temp < 10)
                min = "0" + convert.str();
            else
                min = convert.str();

            if(temp == 120)
                min = "00";
        }

        return hrs + min;
    }
};

class Compare
{
public:
    bool operator() (Patient p, Patient q) {return p.GetWaitHrs() < q.GetWaitHrs();}
};

#endif // PATIENT_H
