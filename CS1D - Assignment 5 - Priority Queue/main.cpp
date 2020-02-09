/**************************************************************
 * PROGRAMMER   : Omar Kermiche
 * ASSIGNMENT #5: Priority Queues
 * PROFESSOR    : Jerry Lebowitz
 * CLASS	    : CS1D
 **************************************************************/

#include "Header.h"
#include "Patient.h"
#include "PriorityQueue.h"

int main()
{
    //Constant Declarations go here
    const char   PROJECT_TYPE = 'A';
    const string PROGRAMMER   = "Omar Kermiche";
    const int	 LAB_NUM      = 5;
    const string LAB_NAME     = "Priority Queues";

    string prompt = "* This program implements two priority queues to\n"
                    "* simulate an afternoon in an emermgency room. \n"
                    "* One priority queue is using the stl. The other\n"
                    "* uses an ADT to implement the p.q. based on a\n"
                    "* sorted list. The general idea is that the p.q\n"
                    "* is built at noon, and each patient gets 20 \n"
                    "* minutes. The patient who has waited the longest\n"
                    "* up till noon has the highest priority unless \n"
                    "* there is a life threatening scenario. Also, \n"
                    "* even if a patient's appointment is interrupted\n"
                    "* they still only get 20 minutes of appointment\n"
                    "* time.";

    //Variable declarations go here
    Patient Patient1("Irene Ill", 6);
    Patient Patient2("Frank Feelingbad", 7);
    Patient Patient3("Cathy Coughing", 4);
    Patient Patient4("Alice Ailment", 5);
    Patient Patient5("Paula Pain", 2);
    Patient Patient6("Sam Sneezing", 2.5);
    Patient Patient7("Tom Temperature", 1);
    Patient p1 = Patient1;
    Patient p2 = Patient2;
    Patient p3 = Patient3;
    Patient p4 = Patient4;
    Patient p5 = Patient5;
    Patient p6 = Patient6;
    Patient p7 = Patient7;
    PriorityQueue<Patient> sickList;
    vector<Patient> dummy = {p1,p2,p3,p4,p5,p6,p7};


    cout << PrintHeader(PROJECT_TYPE, PROGRAMMER, LAB_NUM, LAB_NAME, prompt);

    sickList.Insert(Patient1);
    sickList.Insert(Patient2);
    sickList.Insert(Patient3);
    sickList.Insert(Patient4);
    sickList.Insert(Patient5);
    sickList.Insert(Patient6);
    sickList.Insert(Patient7);

    sickList.AddPatients(dummy);

    cout << "Implementing priority queue using a sorted list:\n\n";
    sickList.DoGoodsDay();

    cout << "\n\nImplementing priority queue using stl priority_queue:\n\n";
    sickList.DoGoodsStl();




    return 0;
}
