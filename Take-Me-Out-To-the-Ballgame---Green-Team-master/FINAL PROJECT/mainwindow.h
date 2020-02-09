#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QtSql>
#include <QMap>
#include <QMessageBox>
#include <QtDebug>
#include "dbmanager.h"
#include "stadiumstruct.h"
#include "graphs.h"
#include "GraphMST.h"
#include <QFileInfo>
#include <QTableWidget>

namespace Ui {
class MainWindow;
}

enum pages{
    LOGIN     = 0,
    HOME      = 1,
    STADIUMS  = 2,
    SOUVENIRS = 3,
    TEAM_INFO = 4,
    PLAN      = 5,
    PURCHASE  = 6,
    CONFIRM   = 7,
    ADMIN     = 7
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void PopulateSouvenirTable(const QString teamName, QTableWidget *inTable);
    ~MainWindow();

private slots:
    void on_loginPg_btn_login_clicked();

    void on_homePg_btn_logout_clicked();

    void on_adminPg_btn_logout_clicked();

    void on_homePg_btn_toStadiumInfo_clicked();

    void on_homePg_btn_toPlanTrip_clicked();

    void on_homePg_btn_toTeamLookup_clicked();

    void on_stadiumsPg_btn_home_clicked();

    void on_teamsPg_btn_home_clicked();

    void on_planPg_btn_home_clicked();

    void on_purchasePg_btn_goBack_clicked();

    void on_comfirmPg_btn_goBack_clicked();

    void on_stadiumsPg_btn_sortList_clicked();

    void on_stadiumsPg_btn_viewSouvenirs_clicked();

    void on_admin_addSouv_clicked();

    void on_admin_souvTeam_comboBox_currentIndexChanged(int index);

    void on_admin_RemoveSouv_clicked();

    void on_admin_souvTable_clicked(const QModelIndex &index);

    void on_admin_modifySouv_clicked();

    void on_admin_clearLineEditsButton_clicked();

    void on_PlanYourTrip_pushButton_clicked();

    void on_PlanTrip_tableWidget_cellDoubleClicked(int row, int column);

    bool isThisStadiumSelected(QString stadToCheck);

    void on_StartTrip_pushButton_2_clicked();

    void FillItemMenu(QString teamName);

    void on_Default_radioButton_3_clicked();

    void on_CustomTrip1_radioButton_clicked();

    void on_CustomTrip2_radioButton_2_clicked();

    void on_CancelSelectedTrips_pushButton_3_clicked();

    bool Find(QString stadium)
    {
        int i = 0;
        bool found = false;

        while(!found && i < stadiumsToVisit.size())
        {
            if(stadiumsToVisit[i].stadiumName == stadium)
            {
                found = true;
            }

            i++;
        }

        return found;
    }

    QString FindTeam(QString stadium)
    {
        int i = 0;
        bool found = false;
        QVector<StadiumInfo> temp = thisDatabase.sortedByTeamStadium("Stadium");
        while(!found && i < temp.size())
        {
            if(temp[i].stadiumName == stadium)
            {
                found = true;

                return temp[i].teamName;
            }

            i++;
        }

        return "N/A";
    }

    QVector<CurrLocal> InsertionSort(QVector<CurrLocal> stadiums)
    {
        int indexCurrent;
        int indexCheck;
        CurrLocal tempLargerCheck;

        /**********************************************************************
         * PROCESSING
         * 	- indexCurrent starts as 1 and is incremented after each loop
         * 	  iteration
         * 	- tempLargerCheck becomes the value at stadiums[indexCurrent]
         * 	- indexCheck becomes (indexCurrent - 1)
         * 	- then a while loop that swaps the values in the two index numbers
         * 	  loops as long as the value of indexCheck >= 0 & the value of the
         * 	  element of indexCheck is bigger than the value of tempLargerCheck
         *  - if the conditions for the while loop are not met, then the element
         *    of [indexCheck + 1] becomes tempLargerCheck
         *  - then the for loop iterates again until it reaches the end of the
         *    array.
         **********************************************************************/
        for(indexCurrent = 1; indexCurrent < stadiums.size(); indexCurrent++)
        {
            tempLargerCheck = stadiums[indexCurrent];
            indexCheck = indexCurrent - 1;

            while(indexCheck >= 0 && stadiums[indexCheck].totDistance > tempLargerCheck.totDistance)
            {
                stadiums[indexCheck + 1] = stadiums[indexCheck];
                indexCheck = indexCheck - 1;
            }

            stadiums[indexCheck + 1] = tempLargerCheck;
        }

        return stadiums;
    }

    QVector<CurrLocal> InsertionSort2(QVector<int> distances)
    {
        int indexCurrent;
        int indexCheck;
        int tempLargerCheck;
        QVector<CurrLocal> dists;
        /**********************************************************************
         * PROCESSING
         * 	- indexCurrent starts as 1 and is incremented after each loop
         * 	  iteration
         * 	- tempLargerCheck becomes the value at stadiums[indexCurrent]
         * 	- indexCheck becomes (indexCurrent - 1)
         * 	- then a while loop that swaps the values in the two index numbers
         * 	  loops as long as the value of indexCheck >= 0 & the value of the
         * 	  element of indexCheck is bigger than the value of tempLargerCheck
         *  - if the conditions for the while loop are not met, then the element
         *    of [indexCheck + 1] becomes tempLargerCheck
         *  - then the for loop iterates again until it reaches the end of the
         *    array.
         **********************************************************************/
        for(indexCurrent = 1; indexCurrent < distances.size(); indexCurrent++)
        {
            tempLargerCheck = distances[indexCurrent];
            indexCheck = indexCurrent - 1;

            while(indexCheck >= 0 && distances[indexCheck] > tempLargerCheck)
            {
                distances[indexCheck + 1] = distances[indexCheck];
                indexCheck = indexCheck - 1;
            }

            distances[indexCheck + 1] = tempLargerCheck;
        }

        for(int i = 0; i < distances.size(); i++)
        {
            CurrLocal c = {stadiumsToVisit[i].teamName,"",0, 0, double(distances[i]), true};

            dists.push_back(c);
        }

        return dists;
    }

    bool StadiumVisited(QString stad)
    {
        int i= 0;
        bool found = false;

        while(!found && i < visited.size())
        {
            if(visited[i] == stad)
            {
                found = true;
            }

            i++;
        }

        return found;
    }

    bool isSelectedStadium(QString ind)
    {
        int i = 0;
        bool found = false;

        while(!found && i < stadToVisit2.size())
        {
            if(stadToVisit2[i] == ind)
                found = true;

            i++;
        }

        return found;
    }

    CurrLocal FindShortestIndex(int currRow)
    {
        int shortest = 10000000;
        CurrLocal temp;
        for(int i = 1; i < selectDist[currRow].size(); i++)
        {
            if(selectDist[currRow][i].totDistance < shortest && isSelectedStadium(selectDist[currRow][i].local) && !StadiumVisited(selectDist[currRow][i].local))
            {
                shortest = selectDist[currRow][i].totDistance;

                temp = selectDist[currRow][i];

            }
        }

        return temp;
    }
    int FindIndexSelectDist(QString stad)
    {
        int i = 0;
        int col = 0;
        int index;
        bool found = false;
        while(!found && i < selectDist.size())
        {
            if(selectDist[i][col].local == stad){
                found = true;

                index = i;
            }

            i++;
        }
        return index;
    }

    CurrLocal FindShortestIndexDefault(int currRow)
    {
        int shortest = 10000000;
        CurrLocal temp;
        for(int i = 1; i < selectDist[currRow].size(); i++)
        {
            if(selectDist[currRow][i].totDistance < shortest && !StadiumVisited(selectDist[currRow][i].local))
            {
                shortest = selectDist[currRow][i].totDistance;

                temp = selectDist[currRow][i];
            }
        }
        qDebug() << shortest;
        return temp;
    }

    void on_NextCity_pushButton_clicked();

    void on_FromReceiptHome_pushButton_clicked();

    void on_addTeam_clicked();

    void on_deleteTEam_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_AdminTabs_tabBarClicked(int index);

    void on_teamPg_btn_search_clicked();

    void on_Purchase_pushButton_clicked();

    void on_souvenirsPg_btn_goBack_clicked();

    void on_MST_pushButton_clicked();

    void on_MST_home_pushbutton_clicked();

    void on_MST_back_pushbutton_clicked();

    void on_backbtn_clicked();

private:
    Ui::MainWindow *ui;

    int tripNum = 0;
    int index = 0;
    double grandTotalSpent = 0;
    double totalSpent = 0;
    bool createCol = true;
    int currRow = 0;
    int grandTotalDistance = 0;
    dbManager thisDatabase;
    SouvenirMap souvenirMap;
    QVector<StadiumInfo> stadiumsToVisit;
    QVector<QString> stadfoodItems;
    QVector<CurrLocal> shortestPaths;
    QVector<QString> shortestCust2;
    QVector<QString> stadToVisit2;
    QVector<QString> visited;
    QVector<int> selectInd;
    QVector<QVector<CurrLocal>> selectDist;
};

#endif // MAINWINDOW_H
