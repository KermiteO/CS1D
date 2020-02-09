#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->mainPages->setCurrentIndex(LOGIN);
    ui->loginPg_label_ERROR->setText("");

    ui->stadiumsPg_table_info->horizontalHeader()->setVisible(true);
    ui->stadiumsPg_table_info->verticalHeader()->setVisible(false);
    ui->PlanTrip_tableWidget->horizontalHeader()->setVisible(true);

    ui->pushButton_10->hide();
    ui->pushButton_8->hide();
    ui->label_4->hide();

    QFile f(":qdarkstyle/style.qss");
    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginPg_btn_login_clicked()
{
    QString un = ui->loginPg_line_username->text();
    QString pw = ui->loginPg_line_password->text();

    if(un == "" || pw == "")
    {
        ui->loginPg_label_ERROR->setText("Both a username and password must be entered.");
    }
    else
    {
        if(un == "user" && pw == "pass")
        {
            ui->mainPages->setCurrentIndex(HOME);

            ui->loginPg_label_ERROR->setText("");
            ui->loginPg_line_username->clear();
            ui->loginPg_line_password->clear();
        }
        else if(un == "admin" && pw == "1234")
        {
            ui->mainPages->setCurrentIndex(ADMIN);
            ui->loginPg_label_ERROR->setText("");
            ui->loginPg_line_username->clear();
            ui->loginPg_line_password->clear();

            // --------------------------------------------------------------
            //  (BEGIN) Populating the team list for souvenir editing

            // used to store team names
            QVector<QString> teamList = thisDatabase.getTeamNames();

            // putting the team names in the combo box
            for (int index = teamList.size() - 1; index >= 0; index--)
            {
                ui->admin_souvTeam_comboBox->addItem(teamList.at(index));
            }

            // making sure that the combo box, by default, shows the first
            // team
            ui->admin_souvTeam_comboBox->setCurrentIndex(0);



            // filling in the QTableWidget that contains souvenirs
            // for the selected team

            // Contains the souvenir names for index 0 team
            QVector<SouvenirInfoTemporary> souvList = thisDatabase.getSouvenirInfo();

            // Populating souvernir List
            PopulateSouvenirTable(ui->admin_souvTeam_comboBox->currentText(),ui->admin_souvTable);

            ui->admin_souvErrorLabel->hide();

            ui->AdminTabs->setCurrentIndex(1);


            //  (END) Populating the team list for souvenir editing
            // --------------------------------------------------------------
        }
        else
        {
            ui->loginPg_label_ERROR->setText("That is not a valid login.");
        }
    }
}

void MainWindow::on_homePg_btn_logout_clicked()
{
    ui->mainPages->setCurrentIndex(LOGIN);
}

void MainWindow::on_adminPg_btn_logout_clicked()
{
    ui->mainPages->setCurrentIndex(LOGIN);
}

void MainWindow::on_homePg_btn_toStadiumInfo_clicked()
{
    ui->stadiumsPg_radio_MLB->setChecked(true);
    ui->stadiumsPg_list_sorts->setCurrentRow(0);
    ui->stadiumsPg_btn_sortList->click();
    ui->stadiumsPg_table_info->setFocus();

    ui->mainPages->setCurrentIndex(STADIUMS);
}

void MainWindow::on_homePg_btn_toTeamLookup_clicked()
{
    ui->teamPg_disp_address->setText("");
    ui->teamPg_disp_capacity->setText("");
    ui->teamPg_disp_date->setText("");
    ui->teamPg_disp_phone->setText("");
    ui->teamPg_disp_stadium->setText("");
    ui->teamPg_disp_surface->setText("");
    ui->teamPg_disp_team->setText("");
    ui->teamPg_disp_typology->setText("");

    ui->teamPg_line_teamName->clear();
    ui->teamPg_line_teamName->setFocus();

    ui->mainPages->setCurrentIndex(TEAM_INFO);
}

void MainWindow::on_homePg_btn_toPlanTrip_clicked()
{
    ui->PlanTrip_tableWidget->hide();
    ui->SelectedStadium_listWidget->clear();
    ui->comboBox->clear();

    ui->mainPages->setCurrentIndex(8);
}

void MainWindow::on_stadiumsPg_btn_home_clicked()
{
    ui->mainPages->setCurrentIndex(HOME);
    ui->label_4->hide();
}

void MainWindow::on_teamsPg_btn_home_clicked()
{
    ui->mainPages->setCurrentIndex(HOME);

    while(ui->teamPg_table_souvenirs->rowCount()!=0)
    {
        ui->teamPg_table_souvenirs->removeRow(0);
    }
}

void MainWindow::on_planPg_btn_home_clicked()
{
    ui->mainPages->setCurrentIndex(HOME);
}

void MainWindow::on_purchasePg_btn_goBack_clicked()
{
    ui->mainPages->setCurrentIndex(PLAN);
}

void MainWindow::on_comfirmPg_btn_goBack_clicked()
{
    ui->mainPages->setCurrentIndex(PURCHASE);
}

void MainWindow::on_stadiumsPg_btn_sortList_clicked()
{
    ui->stadiumsPg_table_info->verticalHeader()->setVisible(false);

    /**********************************************************************
     *               Format for QT Date Time class                        *
     *--------------------------------------------------------------------*
     * MMMM = the long localized month name (e.g. 'January' to 'December')*
     *    d = the day as number without a leading zero (1 to 31)          *
     * yyyy = the year as four digit number                               *
     **********************************************************************/
    QString format = "MMMM d, yyyy";

    QTableWidgetItem *itemTeam;
    QTableWidgetItem *itemStadium;
    QTableWidgetItem *itemCapacity;
    QTableWidgetItem *itemTypology;
    QTableWidgetItem *itemSurface;
    QTableWidgetItem *itemAddress;
    QTableWidgetItem *itemPhone;
    QTableWidgetItem *itemDate;

    QListWidgetItem  *selectedSort;

    QVector<StadiumInfo> stadiumVect;
    QString league;

    int index, currentRow;

    while(ui->stadiumsPg_table_info->rowCount()!=0)
    {
        ui->stadiumsPg_table_info->removeRow(0);
    }

    selectedSort = ui->stadiumsPg_list_sorts->selectedItems().at(0);

    if(selectedSort->text() == "Team")
    {
        stadiumVect = thisDatabase.sortedByTeamStadium("Team");
    }
    else if(selectedSort->text() == "Stadium")
    {
        stadiumVect = thisDatabase.sortedByTeamStadium("Stadium");
    }
    else if(selectedSort->text() == "Capacity")
    {
       stadiumVect = thisDatabase.sortedByCapacity();

       int total = 0;

       for(int i = 0; i < stadiumVect.length(); i++)
       {
           total += stadiumVect[i].capacity;
       }

       ui->label_4->show();
       ui->label_4->setText("   Capacity sum: " + QString::number(total));
    }
    else if(selectedSort->text() == "Typology")
    {
        stadiumVect = thisDatabase.sortedStadiumTypology();
    }
    else if(selectedSort->text() == "Surface")
    {
        ui->stadiumsPg_table_info->verticalHeader()->setVisible(true);
        stadiumVect = thisDatabase.surfaceSorted();
    }
    else if(selectedSort->text() == "Opening Date")
    {
        stadiumVect = thisDatabase.sortedChronologicalOrder();
    }
    else
    {
         qDebug() << "ERROR, SORT NON-EXSISTENT.";
    }

    currentRow = 0;
    for(index = 0; index < stadiumVect.size(); index++)
    {
        league = stadiumVect[index].leagueType;

        ui->stadiumsPg_table_info->insertRow(currentRow);

        if(league == "National" && (ui->stadiumsPg_radio_MLB->isChecked() || ui->stadiumsPg_radio_NL->isChecked()))
        {
            itemTeam = new QTableWidgetItem;
            itemTeam->setText(stadiumVect[index].teamName);
            ui->stadiumsPg_table_info->setItem(currentRow, 0, itemTeam);

            itemStadium = new QTableWidgetItem;
            itemStadium->setText(stadiumVect[index].stadiumName);
            ui->stadiumsPg_table_info->setItem(currentRow, 1, itemStadium);

            itemCapacity = new QTableWidgetItem;
            itemCapacity->setText(QString::number(stadiumVect[index].capacity));
            ui->stadiumsPg_table_info->setItem(currentRow, 2, itemCapacity);

            itemTypology = new QTableWidgetItem;
            itemTypology->setText(stadiumVect[index].typology);
            ui->stadiumsPg_table_info->setItem(currentRow, 3, itemTypology);

            itemSurface = new QTableWidgetItem;
            itemSurface->setText(stadiumVect[index].surface);
            ui->stadiumsPg_table_info->setItem(currentRow, 4, itemSurface);

            itemAddress = new QTableWidgetItem;
            itemAddress->setText(stadiumVect[index].address);
            ui->stadiumsPg_table_info->setItem(currentRow, 5, itemAddress);

            itemPhone = new QTableWidgetItem;
            itemPhone->setText(stadiumVect[index].phoneNumber);
            ui->stadiumsPg_table_info->setItem(currentRow, 6, itemPhone);

            itemDate = new QTableWidgetItem;
            itemDate->setText(stadiumVect[index].dateOpen.toString(format));
            ui->stadiumsPg_table_info->setItem(currentRow, 7, itemDate);

            currentRow++;
        }

        if(league == "American" && (ui->stadiumsPg_radio_MLB->isChecked() || ui->stadiumsPg_radio_AL->isChecked()))
        {
            itemTeam = new QTableWidgetItem;
            itemTeam->setText(stadiumVect[index].teamName);
            ui->stadiumsPg_table_info->setItem(currentRow, 0, itemTeam);

            itemStadium = new QTableWidgetItem;
            itemStadium->setText(stadiumVect[index].stadiumName);
            ui->stadiumsPg_table_info->setItem(currentRow, 1, itemStadium);

            itemCapacity = new QTableWidgetItem;
            itemCapacity->setText(QString::number(stadiumVect[index].capacity));
            ui->stadiumsPg_table_info->setItem(currentRow, 2, itemCapacity);

            itemTypology = new QTableWidgetItem;
            itemTypology->setText(stadiumVect[index].typology);
            ui->stadiumsPg_table_info->setItem(currentRow, 3, itemTypology);

            itemSurface = new QTableWidgetItem;
            itemSurface->setText(stadiumVect[index].surface);
            ui->stadiumsPg_table_info->setItem(currentRow, 4, itemSurface);

            itemAddress = new QTableWidgetItem;
            itemAddress->setText(stadiumVect[index].address);
            ui->stadiumsPg_table_info->setItem(currentRow, 5, itemAddress);

            itemPhone = new QTableWidgetItem;
            itemPhone->setText(stadiumVect[index].phoneNumber);
            ui->stadiumsPg_table_info->setItem(currentRow, 6, itemPhone);

            itemDate = new QTableWidgetItem;
            itemDate->setText(stadiumVect[index].dateOpen.toString(format));
            ui->stadiumsPg_table_info->setItem(currentRow, 7, itemDate);

            currentRow++;
        }
    }

    ui->stadiumsPg_table_info->setRowCount(currentRow);
    ui->stadiumsPg_table_info->resizeColumnsToContents();

    ui->stadiumsPg_table_info->selectRow(0);
}

void MainWindow::on_stadiumsPg_btn_viewSouvenirs_clicked()
{

    QList<QTableWidgetItem*> selectedTeam;
    selectedTeam = ui->stadiumsPg_table_info->selectedItems();

    ui->souvenirsPg_label_GRANDTL->hide();
    ui->backbtn->show();

    ui->souvenirsPg_label_TOP->setText(selectedTeam[0]->text());
    ui->mainPages->setCurrentIndex(SOUVENIRS);

    QString teamName = selectedTeam[0]->text();

    QListWidgetItem *item1 = new QListWidgetItem;
    QVector<QString> tempTeamVector;
    QVector<SouvenirInfoTemporary> tempVector;
    SouvenirInfo myInfo;
    TeamSouvenirs *souvenirs;

    tempVector = thisDatabase.getSouvenirInfo();
    tempTeamVector = thisDatabase.getTeamNames();

    for(int index = 0; index < (int)tempTeamVector.size(); index++)
    {
        souvenirs = new TeamSouvenirs;
        souvenirs->teamName = tempTeamVector[index];

        for(int index2 = 0; index2 < (int)tempVector.size(); index2++)
        {
            if(souvenirs->teamName == tempVector[index2].teamName1)
            {
                myInfo.itemName = tempVector[index2].itemName1;
                myInfo.price = tempVector[index2].price1;
                souvenirs->mySouvenirs.push_back(myInfo);
                souvenirMap.insert(souvenirs->teamName, *souvenirs);
            }
        }
    }

   QTableWidgetItem *item2 = new QTableWidgetItem;
   QTableWidgetItem *item3 = new QTableWidgetItem;
   double price;
   QString price1;

    while(ui->souvenirsPg_tableWidget->rowCount()!=0)
    {
        ui->souvenirsPg_tableWidget->removeRow(0);
    }

   for(int index = 0; index < (int)souvenirMap[teamName].mySouvenirs.size(); index++)
   {
       item2->setText(souvenirMap[teamName].mySouvenirs[index].itemName);
       price = souvenirMap[teamName].mySouvenirs[index].price;
       price1 = QString::number(price,'f',2);
       item3->setText(price1);

       //qDebug() << price1 << endl << flush;
       //qDebug() << item2->text() << endl << flush;
       ui->souvenirsPg_tableWidget->insertRow(index);

       ui->souvenirsPg_tableWidget->setItem(index,0,item2);
       ui->souvenirsPg_tableWidget->setItem(index,1,item3);
       item2 = new QTableWidgetItem;
       item3 = new QTableWidgetItem;
   }
   ui->souvenirsPg_tableWidget->resizeColumnsToContents();
}

void MainWindow::on_admin_addSouv_clicked()
{
    ui->admin_souvPriceLine->setValidator(new QDoubleValidator(std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), 2, ui->admin_souvPriceLine));

    // Checks if there is a name entered
    if (!ui->admin_souvNameLine->text().isEmpty())
    {
        if (!ui->admin_souvErrorLabel->isHidden())
        {
            ui->admin_souvErrorLabel->hide();
        }
        if (!ui->admin_souvPriceLine->text().isEmpty())
        {
            if (ui->admin_souvPriceLine->hasAcceptableInput())
            {
                if (!ui->admin_souvErrorLabel->isHidden())
                {
                    ui->admin_souvErrorLabel->hide();
                }

                SouvenirInfoTemporary newItem;

                // Stores team name
                newItem.teamName1 = ui->admin_souvTeam_comboBox->currentText();

                // Stores item name
                newItem.itemName1 = ui->admin_souvNameLine->text();

                // Stores item price
                newItem.price1    = ui->admin_souvPriceLine->text().toDouble();

                thisDatabase.InsertSouvenir(newItem);
                PopulateSouvenirTable(ui->admin_souvTeam_comboBox->currentText(),ui->admin_souvTable);
            }
            else
            {
                QFont newFont;

                newFont.setItalic(true);

                ui->admin_souvErrorLabel->setText("Please enter a valid price");
                ui->admin_souvErrorLabel->setStyleSheet(QStringLiteral("QLabel{color: rgb(255,0,0);}"));
                ui->admin_souvErrorLabel->setFont(newFont);
                ui->admin_souvErrorLabel->show();
            }
        }
        else
        {
            QFont newFont;

            newFont.setItalic(true);

            ui->admin_souvErrorLabel->setText("Please enter a price");
            ui->admin_souvErrorLabel->setStyleSheet(QStringLiteral("QLabel{color: rgb(255,0,0);}"));
            ui->admin_souvErrorLabel->setFont(newFont);
            ui->admin_souvErrorLabel->show();
        }
    }
    else
    {
        if (ui->admin_souvPriceLine->text().isEmpty())
        {
            QFont newFont;

            newFont.setItalic(true);

            ui->admin_souvErrorLabel->setText("Please enter a name and price");
            ui->admin_souvErrorLabel->setStyleSheet(QStringLiteral("QLabel{color: rgb(255,0,0);}"));
            ui->admin_souvErrorLabel->setFont(newFont);
            ui->admin_souvErrorLabel->show();
        }
        else
        {
            QFont newFont;

            newFont.setItalic(true);

            ui->admin_souvErrorLabel->setText("Please enter a name");
            ui->admin_souvErrorLabel->setStyleSheet(QStringLiteral("QLabel{color: rgb(255,0,0);}"));
            ui->admin_souvErrorLabel->setFont(newFont);
            ui->admin_souvErrorLabel->show();
        }
    }
}



void MainWindow::on_admin_RemoveSouv_clicked()
{
    // Checks if there is a name entered
    if (!ui->admin_souvNameLine->text().isEmpty())
    {
        SouvenirInfoTemporary newItem;

        // Stores team name
        newItem.teamName1 = ui->admin_souvTeam_comboBox->currentText();

        // Stores item name
        newItem.itemName1 = ui->admin_souvNameLine->text();

        // Stores item price
        newItem.price1    = ui->admin_souvPriceLine->text().toDouble();

        thisDatabase.RemoveSouvenir(newItem);
        PopulateSouvenirTable(ui->admin_souvTeam_comboBox->currentText(),ui->admin_souvTable);
    }
    else
    {
        QFont newFont;

        newFont.setItalic(true);

        ui->admin_souvErrorLabel->setText("Please enter a name");
        ui->admin_souvErrorLabel->setStyleSheet(QStringLiteral("QLabel{color: rgb(255,0,0);}"));
        ui->admin_souvErrorLabel->setFont(newFont);
        ui->admin_souvErrorLabel->show();
    }
}

void MainWindow::on_admin_modifySouv_clicked()
{
    ui->admin_souvPriceLine->setValidator(new QDoubleValidator(std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), 2, ui->admin_souvPriceLine));

    // Checks if there is a name entered
    if (!ui->admin_souvNameLine->text().isEmpty()) // making sure name line isn't empty
    {
        if (!ui->admin_souvErrorLabel->isHidden()) // hiding the error label
        {
            ui->admin_souvErrorLabel->hide();
        }

        if (!ui->admin_souvPriceLine->text().isEmpty())
        {
            if (ui->admin_souvPriceLine->hasAcceptableInput())
            {
                if (!ui->admin_souvErrorLabel->isHidden())
                {
                    ui->admin_souvErrorLabel->hide();
                }

                SouvenirInfoTemporary oldItem;
                SouvenirInfoTemporary newItem;

                QList<QTableWidgetItem*> currentItem = ui->admin_souvTable->selectedItems();

                if (currentItem.size() > 0)
                {
                    // Stores team name
                    newItem.teamName1 = ui->admin_souvTeam_comboBox->currentText();
                    oldItem.teamName1 = ui->admin_souvTeam_comboBox->currentText();

                    // Stores item name
                    newItem.itemName1 = ui->admin_souvNameLine->text();
                    oldItem.itemName1 = currentItem[0]->text();

                    // Stores item price
                    newItem.price1    = ui->admin_souvPriceLine->text().toDouble();
                    oldItem.price1    = currentItem[1]->text().toDouble();

                    thisDatabase.ModifySouvenir(oldItem,newItem);
                    PopulateSouvenirTable(ui->admin_souvTeam_comboBox->currentText(),ui->admin_souvTable);
                }
                else
                {
                    QFont newFont;

                    newFont.setItalic(true);

                    ui->admin_souvErrorLabel->setText("Please select an item from the left to modify");
                    ui->admin_souvErrorLabel->setStyleSheet(QStringLiteral("QLabel{color: rgb(255,0,0);}"));
                    ui->admin_souvErrorLabel->setFont(newFont);
                    ui->admin_souvErrorLabel->show();
                }
            }
            else
            {
                QFont newFont;

                newFont.setItalic(true);

                ui->admin_souvErrorLabel->setText("Please enter a valid price");
                ui->admin_souvErrorLabel->setStyleSheet(QStringLiteral("QLabel{color: rgb(255,0,0);}"));
                ui->admin_souvErrorLabel->setFont(newFont);
                ui->admin_souvErrorLabel->show();
            }
        }
        else // valid name no price
        {
            QFont newFont;

            newFont.setItalic(true);

            ui->admin_souvErrorLabel->setText("Please enter a price");
            ui->admin_souvErrorLabel->setStyleSheet(QStringLiteral("QLabel{color: rgb(255,0,0);}"));
            ui->admin_souvErrorLabel->setFont(newFont);
            ui->admin_souvErrorLabel->show();
        }
    }
    else // no name
    {
        if (ui->admin_souvPriceLine->text().isEmpty()) // no name and price
        {
            QFont newFont;

            newFont.setItalic(true);

            ui->admin_souvErrorLabel->setText("Please enter a name and price");
            ui->admin_souvErrorLabel->setStyleSheet(QStringLiteral("QLabel{color: rgb(255,0,0);}"));
            ui->admin_souvErrorLabel->setFont(newFont);
            ui->admin_souvErrorLabel->show();
        }
        else // no name valid price
        {
            QFont newFont;

            newFont.setItalic(true);

            ui->admin_souvErrorLabel->setText("Please enter a name");
            ui->admin_souvErrorLabel->setStyleSheet(QStringLiteral("QLabel{color: rgb(255,0,0);}"));
            ui->admin_souvErrorLabel->setFont(newFont);
            ui->admin_souvErrorLabel->show();
        }
    }
}



void MainWindow::on_admin_souvTable_clicked(const QModelIndex &index)
{
    QList<QTableWidgetItem*> currentItem = ui->admin_souvTable->selectedItems();
    ui->admin_souvNameLine->setText(currentItem[0]->text());
    ui->admin_souvPriceLine->setText(currentItem[1]->text());
}


void MainWindow::on_admin_souvTeam_comboBox_currentIndexChanged(int index)
{
   PopulateSouvenirTable(ui->admin_souvTeam_comboBox->currentText(),ui->admin_souvTable);
}


void MainWindow::PopulateSouvenirTable(const QString teamName, QTableWidget* inTable)
{
    QListWidgetItem *item1 = new QListWidgetItem;
    QVector<QString> tempTeamVector;
    QVector<SouvenirInfoTemporary> tempVector;
    SouvenirInfo myInfo;
    TeamSouvenirs *souvenirs;

    tempVector = thisDatabase.getSouvenirInfo();
    tempTeamVector = thisDatabase.getTeamNames();

    for(int index = 0; index < (int)tempTeamVector.size(); index++)
    {
        souvenirs = new TeamSouvenirs;
        souvenirs->teamName = tempTeamVector[index];

        for(int index2 = 0; index2 < (int)tempVector.size(); index2++)
        {

            if(souvenirs->teamName == tempVector[index2].teamName1)
            {
                myInfo.itemName = tempVector[index2].itemName1;
                myInfo.price = tempVector[index2].price1;
                souvenirs->mySouvenirs.push_back(myInfo);
                souvenirMap.insert(souvenirs->teamName, *souvenirs);

            }
        }

    }

   QTableWidgetItem *item2 = new QTableWidgetItem;
   QTableWidgetItem *item3 = new QTableWidgetItem;
   double price;
   QString price1;

    while(inTable->rowCount()!=0)
    {
        inTable->removeRow(0);
    }

   for(int index = 0; index < (int)souvenirMap[teamName].mySouvenirs.size(); index++)
   {
       item2->setText(souvenirMap[teamName].mySouvenirs[index].itemName);
       price = souvenirMap[teamName].mySouvenirs[index].price;
       price1 = QString::number(price,'f',2);
       item3->setText(price1);

       //qDebug() << price1 << endl << flush;
       //qDebug() << item2->text() << endl << flush;
       inTable->insertRow(index);

       inTable->setItem(index,0,item2);
       inTable->setItem(index,1,item3);
       item2 = new QTableWidgetItem;
       item3 = new QTableWidgetItem;
   }

   ui->admin_souvTable->setSelectionBehavior(QAbstractItemView::SelectRows);
   ui->admin_souvTable->resizeColumnsToContents();
}


void MainWindow::on_admin_clearLineEditsButton_clicked()
{
    ui->admin_souvNameLine->clear();
    ui->admin_souvPriceLine->clear();


    if(ui->admin_souvErrorLabel->isVisible())
    {
        ui->admin_souvErrorLabel->hide();
    }
}


void MainWindow::on_PlanYourTrip_pushButton_clicked()
{
    ui->mainPages->setCurrentIndex(HOME);

    ui->SelectedStadium_listWidget->clear();

    stadiumsToVisit.clear();
}


void MainWindow::on_PlanTrip_tableWidget_cellDoubleClicked(int row, int column)
{
    StadiumInfo namesS = thisDatabase.sortedByTeamStadium("Stadium").at(row);

    if(isThisStadiumSelected(namesS.stadiumName))
    {
        QMessageBox msgBox;
        msgBox.critical(0,"Existing Stadium!","Duplicate stadiums are not permitted");
        msgBox.setFixedSize(1200,400);
    }
    else
    {
        ui->SelectedStadium_listWidget->addItem(namesS.stadiumName);
        ui->comboBox->addItem(namesS.stadiumName);

        stadiumsToVisit.push_back(namesS);
    }
}


bool MainWindow::isThisStadiumSelected(QString stadToCheck)
{
    for(int i = 0; i < stadiumsToVisit.size(); i++)
    {
        if(stadiumsToVisit[i].stadiumName == stadToCheck)
        {
            return true;
        }
    }
    return false;
}


void MainWindow::on_StartTrip_pushButton_2_clicked()
{
    index = 0;

    switch(tripNum)
    {
    case 2:{
        ui->mainPages->setCurrentIndex(6);

        QVector<Graph> graphs1;

        stadiumsToVisit = thisDatabase.sortedByTeamStadium("Stadium");

        for(int i = 0; i < stadiumsToVisit.size(); i++)
        {
        qDebug()<< i;
            if(stadiumsToVisit[i].stadiumName != "Comerica Park"){
                qDebug() << "made it";
                Graph newG(stadiumsToVisit[i].stadiumName);
                qDebug() << "made it 2";

                graphs1.push_back(newG);
            }

        }

        Graph g("Comerica Park");
        graphs1.push_front(g);

        //get all the map data from the sql table Distances
        QVector<DistanceInfo> graphInfo = thisDatabase.getGraphDistances();
qDebug() << "fail here";
        for(int k = 0; k < graphs1.size(); k++)
        {
            for(int i = 0 ; i < graphInfo.size(); i++)
            {
                //Each stadium is associated with a specific index # from 0 to 29.
                //Find that corresponding index for the starting and ending city
                //and add the edge to the graph
                graphs1[k].addEdge(graphs1[k].FindIndex(graphInfo[i].startStad), graphs1[k].FindIndex(graphInfo[i].endStad), graphInfo[i].distance);


            }
        }
        qDebug() << "fail here 2";

        for(int i = 0; i < graphs1.size(); i++)
        {
            QVector<CurrLocal> tempV = graphs1[i].Dijkstras();

            selectDist.push_back(tempV);
        }

        visited.push_back("Comerica Park");
        int row = 0;
        for(int count = 1; count < graphs1.size(); count++)
        {
            CurrLocal temp = FindShortestIndexDefault(row);
            visited.push_back(temp.local);
            shortestPaths.push_back(temp);
            grandTotalDistance += temp.totDistance;
            row = FindIndexSelectDist(temp.local);
        }
        CurrLocal front = {"Comerica Park", "", 0, 0, 0, true};
        shortestPaths.push_front(front);
        ui->CurrentStadium_label->setText(shortestPaths[index].local);

        FillItemMenu(FindTeam(shortestPaths[index].local));

        index++;
    }
        break;
    case 3:{
        index = 0;

        QString startCity = ui->comboBox->currentText();

        visited.push_back(startCity);

        ui->mainPages->setCurrentIndex(6);

        QVector<Graph> graphs;
        Graph temp(startCity);
        graphs.push_back(temp);
        stadToVisit2.push_back(startCity);

        for(int t = 0; t < ui->SelectedStadium_listWidget->count(); t++)
        {
                if(ui->SelectedStadium_listWidget->item(t)->text() != startCity){
                    Graph temp(ui->SelectedStadium_listWidget->item(t)->text());
                    graphs.push_back(temp);
                    stadToVisit2.push_back(ui->SelectedStadium_listWidget->item(t)->text());
                }
        }

        stadiumsToVisit = thisDatabase.sortedByTeamStadium("Stadium");

        //get all the map data from the sql table Distances
        QVector<DistanceInfo> graphInfo = thisDatabase.getGraphDistances();

        for(int k = 0; k < graphs.size(); k++)
        {
            for(int i = 0 ; i < graphInfo.size(); i++)
            {
                //Each stadium is associated with a specific index # from 0 to 29.
                //Find that corresponding index for the starting and ending city
                //and add the edge to the graph
                graphs[k].addEdge(graphs[k].FindIndex(graphInfo[i].startStad), graphs[k].FindIndex(graphInfo[i].endStad), graphInfo[i].distance);
            }
        }

        for(int i = 0; i < graphs.size(); i++)
        {
            QVector<CurrLocal> tempV = graphs[i].Dijkstras();

            selectDist.push_back(tempV);
        }

        int row = 0;

        CurrLocal front = {startCity, "", 0, 0, 0, true};
        shortestPaths.push_back(front);
        for(int count = 0; count < graphs.size(); count++)
        {
            CurrLocal temp = FindShortestIndex(row);
            if(temp.local != "")
            {
                visited.push_back(temp.local);

                qDebug() << temp.local;
                grandTotalDistance += temp.totDistance;

                qDebug() << grandTotalDistance;

                shortestPaths.push_back(temp);
            }

            row = FindIndexSelectDist(temp.local);
        }

        ui->CurrentStadium_label->setText(shortestPaths[index].local);

        FillItemMenu(FindTeam(shortestPaths[index].local));

        index++;
/***************************************************************************************************************************************/
    }
        break;
    default:  QMessageBox::information(this,

                                       "Error!",

                                       "Pick a Custom Trip & cities!\n");
    }
}


/*
 * Function: FillItemMenu
 * Task: To take the items of a given city from the database and populate the
 *        TableWidget for the user to view in the UI.
 */
void MainWindow::FillItemMenu(QString teamName)
{
    stadfoodItems.clear();
    stadfoodItems = thisDatabase.getStadiumItems(teamName);

    ui->ItemsComboBox->clear();
    ui->ItemsTableWidget->clear();

    ui->ItemsTableWidget->setRowCount(0);
    ui->ItemsTableWidget->setColumnCount(0);

    int col = 0;

    ui->ItemsTableWidget->horizontalHeader()->setVisible(true);  //Open up the header to represent the columns

    ui->ItemsTableWidget->insertColumn(col);
    ui->ItemsTableWidget->setHorizontalHeaderItem(col, new QTableWidgetItem("Item Price:"));

    ui->ItemsTableWidget->insertColumn(col);
    ui->ItemsTableWidget->setHorizontalHeaderItem(col, new QTableWidgetItem("Item Name:"));

    ui->ItemsTableWidget->resizeColumnsToContents();
    ui->ItemsTableWidget->horizontalHeader()->setStretchLastSection(true);

    for(int i = 0; i < stadfoodItems.size(); i++)
    {
        int numRows = ui->ItemsTableWidget->rowCount();
        ui->ItemsTableWidget->insertRow(numRows);

        ui->ItemsTableWidget->setItem(numRows, 0, new QTableWidgetItem(stadfoodItems.at(i)));
        ui->ItemsTableWidget->setItem(numRows, 1, new QTableWidgetItem(thisDatabase.getItemPrice(teamName, stadfoodItems.at(i))));

        ui->ItemsComboBox->addItem(stadfoodItems.at(i));
    }

    ui->ItemsTableWidget->resizeColumnsToContents();
    ui->ItemsTableWidget->horizontalHeader()->setStretchLastSection(true);
}


void MainWindow::on_Default_radioButton_3_clicked()
{
    tripNum = 1;

    stadiumsToVisit.clear();
}


void MainWindow::on_CustomTrip1_radioButton_clicked()
{
    tripNum = 2;

    stadiumsToVisit.clear();
}


void MainWindow::on_CustomTrip2_radioButton_2_clicked()
{
    tripNum = 3;

    ui->PlanTrip_tableWidget->show();

    QString format = "MMMM d, yyyy";

    QTableWidgetItem *itemStadium;

    QVector<StadiumInfo> stadiumVect;

    int index, currentRow;

    while(ui->PlanTrip_tableWidget->rowCount()!=0)
    {
        ui->PlanTrip_tableWidget->removeRow(0);
    }

    stadiumVect = thisDatabase.sortedByTeamStadium("Stadium");

    currentRow = 0;

    for(index = 0; index < stadiumVect.size(); index++)
    {
        ui->PlanTrip_tableWidget->insertRow(currentRow);

        itemStadium = new QTableWidgetItem;
        itemStadium->setText(stadiumVect[index].stadiumName);
        ui->PlanTrip_tableWidget->setItem(currentRow, 0, itemStadium);

        currentRow++;
    }

    ui->PlanTrip_tableWidget->setRowCount(currentRow);
    ui->PlanTrip_tableWidget->resizeColumnsToContents();
}


void MainWindow::on_CancelSelectedTrips_pushButton_3_clicked()
{
    stadiumsToVisit.clear();

    ui->SelectedStadium_listWidget->clear();
    ui->comboBox->clear();
}


void MainWindow::on_NextCity_pushButton_clicked()
{
    grandTotalSpent += totalSpent;
    totalSpent = 0;

    ui->currPurchase_label->setText("$");
    ui->totPurch_label_12->setText("$");
    ui->AmountItems_spinBox->setValue(0);
    ui->SelectedItemsTableWidget->clearContents();
    ui->SelectedItemsTableWidget->setRowCount(0);

    currRow = 0;

    if(ui->CustomTrip1_radioButton->isChecked() && index < shortestPaths.size())
    {
        ui->CurrentStadium_label->setText(shortestPaths[index].local);

        FillItemMenu(FindTeam(shortestPaths[index].local));

        index++;
    }
    else if(ui->CustomTrip2_radioButton_2->isChecked() && index < ui->comboBox->count())
    {
        ui->CurrentStadium_label->setText(shortestPaths[index].local);

        FillItemMenu(FindTeam(shortestPaths[index].local));

        index++;
    }
    else
    {
        ui->souvenirsPg_label_GRANDTL->show();
        ui->backbtn->hide();

        ui->souvenirsPg_label_GRANDTL->setText("Total Distance Travelled: " + QString::number(grandTotalDistance) + "\nGrand Total Spent: $" + QString::number(grandTotalSpent));
        ui->souvenirsPg_label_TOP->setText( + "Total Trip Expenditure");

        ui->mainPages->setCurrentIndex(3);
    }
}


void MainWindow::on_FromReceiptHome_pushButton_clicked()
{
    ui->mainPages->setCurrentIndex(HOME);

    while(ui->souvenirsPg_tableWidget->rowCount()!=0)
    {
        ui->souvenirsPg_tableWidget->removeRow(0);
    }

    visited.clear();
    shortestPaths.clear();
    selectDist.clear();
    stadToVisit2.clear();
    stadiumsToVisit.clear();
    grandTotalSpent = 0;
    index = 0;
    grandTotalDistance = 0;
}


//Add team las vegas gamblers
void MainWindow::on_addTeam_clicked()
{
    //This function is basically used for reading in the new city from a text file
    QVector<QString>stadiumVec;
    QVector<QString>tempVec;


    //The text file that will be read in
    QFile teamFile("newFile1.txt");

    StadiumInfo myStadiumInfo;

    bool found = false;

    int index = 0;

    int index2 = 0;

    QVector<DistanceInfo>tempDistInfo;

    QString format = "MMMM d, yyyy";

    DistanceInfo myDistInfo;

//If the file is open
if(teamFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //The text stream for loading lines of strings from the text file.
        QTextStream inFile(&teamFile);

         //The current file line being parsed from the file.
          QString line;

            //While not at the end of the infile
             while(!inFile.atEnd())
             {
                 line = inFile.readLine();

                 //Push back each line

                 tempVec.push_back(line);
             }

             //Place the info into the stadium info struct object

             myStadiumInfo.stadiumName = tempVec[0];

             myStadiumInfo.teamName = tempVec[1];

             myStadiumInfo.address = tempVec[2];

             myStadiumInfo.phoneNumber = tempVec[3];

             myStadiumInfo.dateOpen = QDateTime::fromString(tempVec[4], format);

             myStadiumInfo.capacity = tempVec[5].toInt();

             myStadiumInfo.surface = tempVec[6];

             myStadiumInfo.typology = tempVec[7];

             myStadiumInfo.leagueType = tempVec[8];

             //Get a list of all stadiums
             stadiumVec = thisDatabase.getStadiums();

             found = false;

             while(index < stadiumVec.size() && !found)
             {
                 //If the stadium already exists, do not let the user click it again
                  if(myStadiumInfo.stadiumName == stadiumVec[index])

                  {
                      found = true;
                  }
                  else
                  {
                      index++;
                  }
             }

             //If it has not been found
             if(!found)
             {
                 //Place all distances into a distance vector
                 index2 = 9;

                 while(index2 < tempVec.size())
                 {
                    myDistInfo.startStad = myStadiumInfo.stadiumName;

                    myDistInfo.endStad = tempVec[index2];

                    myDistInfo.distance = tempVec[index2+1].toInt();

                    tempDistInfo.push_back(myDistInfo);

                    index2 = index2 + 2;
                 }
                 //Add the team in dbManager
                 if(thisDatabase.addTeam(myStadiumInfo, tempDistInfo))
                 {
                     ui->textEdit->setText("Just added " + myStadiumInfo.teamName + " to the list!");
                 }
                 else
                 {
                     ui->textEdit->setText("Could not set the team!");
                 }
            }
            else
            {
                 QMessageBox::information(this,

                 "Error!",

                 "You have already loaded the information\n"

                 "The stadium could not be loaded again.");
            }
    }
    else
    {
        QMessageBox::information(this,

            "Error!",

            "The file \"newteam1.txt\" is missing!\n"

            "The stadium could not be loaded.");
    }
}


//Delete the new team Las Vegas Gamblers
void MainWindow::on_deleteTEam_clicked()
{
    thisDatabase.tempDelete();
    ui->textEdit->setText("Just deleted the new team!");
}


//Edit the team's phone number
void MainWindow::on_pushButton_7_clicked()
{
    QString phoneNumber;

    phoneNumber = ui->lineEdit->text();

    if(phoneNumber.size() < 13)
    {
        QMessageBox::information(this,

            "Error!",

            "Make phone number longer\n"

            "Example: (714) 654-2000\n");
    }
    else if(phoneNumber.size() > 17)
    {
        QMessageBox::information(this,

            "Error!",

            "Make phone number shorter\n",

            "Example: (714) 654-2000\n");
    }
    else
    {
        if(ui->listWidget->selectedItems().count() == 0)
        {
            QMessageBox::information(this,

                "Error!",

                "Pick a team\n");
        }
        else
        {
            //Update information - 7 means update phone number
            if(thisDatabase.updateInfo(0,phoneNumber,ui->listWidget->selectedItems().at(0)->text(), 7))
            {
                ui->textEdit_2->setText("Changed phone number to " + phoneNumber
                                    + "\n" + "Team is " + ui->listWidget->selectedItems().at(0)->text() + "\n");
            }
             else
            {
                 ui->textEdit_2->setText("Sorry could not execute!");
            }
        }
    }
}


//Click to see teams
void MainWindow::on_pushButton_8_clicked()
{
    while(ui->listWidget->count() > 0)
    {
        ui->listWidget->takeItem(0);
    }
    QVector<QString>myVector;

   myVector = thisDatabase.getTeamNames();
   QListWidgetItem *item;

   for(int index = 0; index < myVector.size(); index++)
   {
       item = new QListWidgetItem;
       item->setText(myVector[index]);
        ui->listWidget->addItem(item);
   }
}


//Edit address
void MainWindow::on_pushButton_6_clicked()
{
    QString address;
    address = ui->lineEdit->text();

    if(address.size() < 10)
    {
        QMessageBox::information(this,

            "Error!",

            "Make address longer\n"

            "Example: 23232 Audrey Way, New York, NY, 12232\n");
    }
    else if(address.size() > 100)
    {
        QMessageBox::information(this,

            "Error!",

            "Make phone number shorter\n",

            "Example: 23232 Audrey Way, New York, NY, 12232\n");
    }
    else
    {
        if(ui->listWidget->selectedItems().count() == 0)
        {
            QMessageBox::information(this,

                "Error!",

                "Pick a team\n");
        }
        else
        {
            //Update information - 6 means update address
            if(thisDatabase.updateInfo(0,address,ui->listWidget->selectedItems().at(0)->text(), 6))
            {
                ui->textEdit_2->setText("Changed address to " + address
                                        + "\n" + "Team is " + ui->listWidget->selectedItems().at(0)->text() + "\n");
            }
            else
            {
                ui->textEdit_2->setText("Sorry could not execute!");
            }
        }
    }
}


//Edit league type
void MainWindow::on_pushButton_5_clicked()
{
    QString leagueType;

    leagueType = ui->lineEdit->text();

    if(leagueType == "National" || leagueType == "American")
    {
        //Update information - 5 means update league type
        if(ui->listWidget->selectedItems().count() == 0)
        {
            QMessageBox::information(this,

                "Error!",

                "Pick a team\n");
        }
        else
        {
            if(thisDatabase.updateInfo(0,leagueType,ui->listWidget->selectedItems().at(0)->text(), 5))
            {
                ui->textEdit_2->setText("Changed league type to " + leagueType
                                        + "\n" + "Team is " + ui->listWidget->selectedItems().at(0)->text() + "\n");
            }
            else
            {
                ui->textEdit_2->setText("Sorry could not execute!");
            }
        }
    }
    else
    {
        QMessageBox::information(this,

            "Error!",

            "Make league type either American/National\n"

            "Example: American\n"

            "Example: National\n");
    }
}


//Edit typology
void MainWindow::on_pushButton_4_clicked()
{
    QString typology;

    typology = ui->lineEdit->text();
    if(typology.size() == 0)
    {
        QMessageBox::information(this,

            "Error!",

            "Make typology different\n"

            "Example: Modern\n");
    }
    else
    {
        if(ui->listWidget->selectedItems().count() == 0)
        {
            QMessageBox::information(this,

                "Error!",

                "Pick a team\n");
        }
        else
        {
            //Update information - 4 means update typology
            if(thisDatabase.updateInfo(0,typology,ui->listWidget->selectedItems().at(0)->text(), 4))
            {
                ui->textEdit_2->setText("Changed typology to " + typology
                                        + "\n" + "Team is " + ui->listWidget->selectedItems().at(0)->text() + "\n");
            }
            else
            {
                ui->textEdit_2->setText("Sorry could not execute!");
            }
        }
    }
}


//Edit stadium opening date
void MainWindow::on_pushButton_3_clicked()
{

    QString format = "MMMM d, yyyy";
    QString date;
    date = ui->lineEdit->text();

    if(date.size() < 10)
    {
        QMessageBox::information(this,

            "Error!",

            "Make date longer\n"

            "Example: April 19, 1966\n");
    }
    else if(date.size() > 19)
    {
        QMessageBox::information(this,

            "Error!",

            "Make date shorter\n",

            "Example: April 19, 1966\n");
    }
    else
    {
        if(ui->listWidget->selectedItems().count() == 0)
        {
            QMessageBox::information(this,

                "Error!",

                "Pick a team\n");
        }
        else
        {
            //Update information - 3 means update date
            if(thisDatabase.updateInfo(0,date,ui->listWidget->selectedItems().at(0)->text(), 3))
            {
                ui->textEdit_2->setText("Changed date to " + date
                                        + "\n" + "Team is " + ui->listWidget->selectedItems().at(0)->text() + "\n");
            }
            else
            {
                ui->textEdit_2->setText("Sorry could not execute!");
            }
        }
    }
}


//Edit stadium capacity
void MainWindow::on_pushButton_2_clicked()
{
    int capacity;
    capacity = ui->lineEdit->text().toInt();

    if(capacity < 0)
    {
        QMessageBox::information(this,

            "Error!",

            "Make amount greater than 0\n"

             "Example: 56825");
    }
    else
    {
        if(ui->listWidget->selectedItems().count() == 0)
        {
            QMessageBox::information(this,

                "Error!",

                "Pick a team\n");
        }
        else
        {
            //Update information - 2 means update capacity
            if(thisDatabase.updateInfo(capacity," ",ui->listWidget->selectedItems().at(0)->text(), 2))
            {
                ui->textEdit_2->setText("Changed capacity to " + QString::number(capacity)
                                        + "\n" + "Team is " + ui->listWidget->selectedItems().at(0)->text() + "\n");
            }
            else
            {
                ui->textEdit_2->setText("Sorry could not execute!");
            }
        }
    }
}


//Edit stadium name
void MainWindow::on_pushButton_clicked()
{
    QString stadiumName;
     stadiumName = ui->lineEdit->text();
    if(stadiumName.size() < 1)
    {
        QMessageBox::information(this,

            "Error!",

            "Write the name of the stadium\n"

            "Example: Grand Park");
    }
    else
    {
        if(ui->listWidget->selectedItems().count() == 0)
        {
            QMessageBox::information(this,

                "Error!",

                "Pick a team\n");
        }
        else
        {
            //Update information - 1 means update stadium information
            if(thisDatabase.updateInfo(0,stadiumName,ui->listWidget->selectedItems().at(0)->text(), 1))
            {
                ui->textEdit_2->setText("Changed stadium name to " + stadiumName
                                        + "\n" + "Team is " + ui->listWidget->selectedItems().at(0)->text() + "\n");
            }
            else
            {
                ui->textEdit_2->setText("Sorry could not execute!");
            }
        }
    }
}


//Shows all information about a team
void MainWindow::on_pushButton_9_clicked()
{
    QString format = "MMMM d, yyyy";
    QVector <StadiumInfo> myInfo;
    QString theString;
    if(ui->listWidget_2->selectedItems().count() == 0)
    {
        QMessageBox::information(this,

            "Error!",

            "Pick a team\n");
    }
    else
    {
        theString = ui->listWidget_2->selectedItems().at(0)->text();
        myInfo = thisDatabase.getInfo(theString);
        if(myInfo.size() > 0)
        {
            ui->textBrowser_2->setText("Team Name:    " + theString + "\n" +
                                   "Stadium Name: " + myInfo[0].stadiumName + "\n" +
                                   "Address:      " + myInfo[0].address + "\n" +
                                   "Phone Number: " + myInfo[0].phoneNumber + "\n" +
                                   "Capacity:     " + QString::number(myInfo[0].capacity) + "\n" +
                                   "Typology:     " + myInfo[0].typology + "\n" +
                                   "League Type:  " + myInfo[0].leagueType + "\n" +
                                   "Surface:      " + myInfo[0].surface + "\n" +
                                   "Date Opened:  " + myInfo[0].dateOpen.toString(format) + "\n");
        }
        else
        {
            qDebug() << "ERROR";
        }
    }
}


//Click to see teams
void MainWindow::on_pushButton_10_clicked()
{
    while(ui->listWidget_2->count() > 0)
    {
        ui->listWidget_2->takeItem(0);
    }
    QVector<QString>myVector;

   myVector = thisDatabase.getTeamNames();
   QListWidgetItem *item;

   for(int index = 0; index < myVector.size(); index++)
   {
       item = new QListWidgetItem;
       item->setText(myVector[index]);
       ui->listWidget_2->addItem(item);
   }
}


//Edit surfaces
void MainWindow::on_pushButton_11_clicked()
{
    QString surface;
     surface = ui->lineEdit->text();
    if(surface.size() < 1)
    {
        QMessageBox::information(this,

            "Error!",

            "Write a surface\n"

             "Example: Grass");
    }
    else
    {
        if(ui->listWidget->selectedItems().count() == 0)
        {
            QMessageBox::information(this,

                "Error!",

                "Pick a team\n");
        }
        else
        {
            //Update information - 8 means update surface
            if(thisDatabase.updateInfo(0,surface,ui->listWidget->selectedItems().at(0)->text(), 8))
            {
                ui->textEdit_2->setText("Changed surface to " + surface
                                        + "\n" + "Team is " + ui->listWidget->selectedItems().at(0)->text() + "\n");
            }
            else
            {
                ui->textEdit_2->setText("Sorry could not execute!");
            }
        }
    }
}


void MainWindow::on_AdminTabs_tabBarClicked(int i)
{
    while(ui->listWidget->count() > 0)
    {
        ui->listWidget->takeItem(0);
        ui->listWidget_2->takeItem(0);
    }

    QVector<QString>myVector;

    myVector = thisDatabase.getTeamNames();
    QListWidgetItem *item, *item2;

    for(int index = 0; index < myVector.size(); index++)
    {
        item  = new QListWidgetItem;
        item2 = new QListWidgetItem;

        item->setText(myVector[index]);
        item2->setText(myVector[index]);

        ui->listWidget->addItem(item);
        ui->listWidget_2->addItem(item2);
    }

    // --------------------------------------------------------------
    //  (BEGIN) Populating the team list for souvenir editing

    ui->admin_souvTeam_comboBox->clear();

    // used to store team names
    QVector<QString> teamList = thisDatabase.getTeamNames();

    // putting the team names in the combo box
    for (int index = teamList.size() - 1; index >= 0; index--)
    {
        ui->admin_souvTeam_comboBox->addItem(teamList.at(index));
    }

    // making sure that the combo box, by default, shows the first
    // team
    ui->admin_souvTeam_comboBox->setCurrentIndex(0);



    // filling in the QTableWidget that contains souvenirs
    // for the selected team

    // Contains the souvenir names for index 0 team
    QVector<SouvenirInfoTemporary> souvList = thisDatabase.getSouvenirInfo();

    // Populating souvernir List
    PopulateSouvenirTable(ui->admin_souvTeam_comboBox->currentText(),ui->admin_souvTable);

    ui->admin_souvErrorLabel->hide();

    ui->AdminTabs->setCurrentIndex(1);


    //  (END) Populating the team list for souvenir editing
    // --------------------------------------------------------------
}


void MainWindow::on_teamPg_btn_search_clicked()
{
    QString key = ui->teamPg_line_teamName->text();

    ui->teamPg_disp_address->setText("");
    ui->teamPg_disp_capacity->setText("");
    ui->teamPg_disp_date->setText("");
    ui->teamPg_disp_phone->setText("");
    ui->teamPg_disp_stadium->setText("");
    ui->teamPg_disp_surface->setText("");
    ui->teamPg_disp_team->setText("");
    ui->teamPg_disp_typology->setText("");

    if(key.size() > 0)
    {
        QVector<StadiumInfo>info;
        QVector<QString>souvenirs;
        QString price;

        QTableWidgetItem *itemOb;
        QTableWidgetItem *itemPr;

        info = thisDatabase.sortedByTeamStadium("Team");
        int i = 0;

        while(i < info.size() && info[i].teamName != key)
            i++;

        if(i >= info.size())
        {
            while(ui->teamPg_table_souvenirs->rowCount()!=0)
            {
                ui->teamPg_table_souvenirs->removeRow(0);
            }

            QMessageBox::information(this,
                "Error!",
                "Team was not found.");
        }
        else
        {
            ui->teamPg_disp_address->setText(info[i].address);
            ui->teamPg_disp_capacity->setText(QString::number(info[i].capacity));
            ui->teamPg_disp_date->setText(info[i].dateOpen.toString("MMMM d, yyyy"));
            ui->teamPg_disp_phone->setText(info[i].phoneNumber);
            ui->teamPg_disp_stadium->setText(info[i].stadiumName);
            ui->teamPg_disp_surface->setText(info[i].surface);
            ui->teamPg_disp_team->setText(info[i].teamName);
            ui->teamPg_disp_typology->setText(info[i].typology);

            while(ui->teamPg_table_souvenirs->rowCount()!=0)
            {
                ui->teamPg_table_souvenirs->removeRow(0);
            }

            souvenirs = thisDatabase.getStadiumItems(key);


            for(int i = 0; i < souvenirs.size(); i++)
            {
                itemOb = new QTableWidgetItem;
                itemPr = new QTableWidgetItem;

                itemOb->setText(souvenirs[i]);
                itemPr->setText(thisDatabase.getItemPrice(key, souvenirs[i]));

                ui->teamPg_table_souvenirs->insertRow(i);
                ui->teamPg_table_souvenirs->setItem(i, 0, itemOb);
                ui->teamPg_table_souvenirs->setItem(i, 1, itemPr);
            }
            ui->teamPg_table_souvenirs->resizeColumnsToContents();
        }
    }
    else
    {
        while(ui->teamPg_table_souvenirs->rowCount()!=0)
        {
            ui->teamPg_table_souvenirs->removeRow(0);
        }

        QMessageBox::information(this,
            "Error!",
            "Please enter a team name.");
    }
}


void MainWindow::on_Purchase_pushButton_clicked()
{
    if(ui->AmountItems_spinBox->value() > 0)
    {
        QString price = thisDatabase.getItemPrice(FindTeam(shortestPaths[index].local),ui->ItemsComboBox->currentText());

        double currPurchase = price.toDouble() * ui->AmountItems_spinBox->value();

        ui->currPurchase_label->setText("$" + QString::number(currPurchase));

        totalSpent += currPurchase;

        ui->totPurch_label_12->setText("$" + QString::number(totalSpent));

        QTableWidgetItem *item      = new QTableWidgetItem;
        QTableWidgetItem *itemSouv  = new QTableWidgetItem;
        QTableWidgetItem *priceSouv = new QTableWidgetItem;


        item->setText(ui->ItemsComboBox->currentText());
        itemSouv->setText(ui->ItemsComboBox->currentText());
        priceSouv->setText(QString::number(currPurchase));

        ui->SelectedItemsTableWidget->insertRow(currRow);

        if(createCol && currRow == 0)
        {
            createCol = false;
            ui->SelectedItemsTableWidget->insertColumn(0);
            ui->SelectedItemsTableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Item"));
        }

        ui->souvenirsPg_tableWidget->insertRow(currRow);
        ui->souvenirsPg_tableWidget->setItem(currRow, 0, itemSouv);
        ui->souvenirsPg_tableWidget->setItem(currRow, 1, priceSouv);
        ui->SelectedItemsTableWidget->setItem(currRow, 0, item);

        currRow++;
    }
}

void MainWindow::on_souvenirsPg_btn_goBack_clicked()
{
    ui->mainPages->setCurrentIndex(STADIUMS);

    while(ui->souvenirsPg_tableWidget->rowCount()!=0)
    {
        ui->souvenirsPg_tableWidget->removeRow(0);
    }
}

void MainWindow::on_MST_pushButton_clicked()
{
    ui->mainPages->setCurrentIndex(9);

    GraphMST mstGraph;

    //get all the map data from the sql table Distances
    QVector<DistanceInfo> graphInfo = thisDatabase.getGraphDistances();

    mstGraph.ReadInfo(graphInfo);

    mstGraph.primMST(ui->MST_textbrowser);

}

void MainWindow::on_MST_home_pushbutton_clicked()
{
    ui->mainPages->setCurrentIndex(HOME);
}


void MainWindow::on_MST_back_pushbutton_clicked()
{
    ui->mainPages->setCurrentIndex(8);
}

void MainWindow::on_backbtn_clicked()
{
    ui->mainPages->setCurrentIndex(STADIUMS);
}
