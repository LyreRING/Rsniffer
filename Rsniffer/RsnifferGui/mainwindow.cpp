#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "RsnifferApi.h"

/**********************************************************************
 *   This file implements the interface of Rsniffer
 *********************************************************************/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->accept_radioButton->setChecked(true);//Reject button is selected by default
    //Initialize each interface  
    InitRuleTable();
    InitLogTable();
}

MainWindow::~MainWindow(){
    delete ui;
}

/**
 *  Initialization function:
 *  Initialize the graphical interface, 
 *  such as displaying the header information of each form
**/

void MainWindow::InitRuleTable(){//Initial rule table display
    QStringList header;
    header << "Src IP" <<"Dst IP" << "Src port" << "Dst port" << "Protocol" << "Log";
    ui->tableWidget_rule->setColumnCount(6);
    ui->tableWidget_rule->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_rule->setFocusPolicy(Qt::NoFocus);
    QHeaderView *headerView = ui->tableWidget_rule->verticalHeader();
    headerView->setHidden(true);
    ui->tableWidget_rule->setHorizontalHeaderLabels(header);
    ui->tableWidget_rule->horizontalHeader()->resizeSection(0,145);
    ui->tableWidget_rule->horizontalHeader()->resizeSection(1,145);
    ui->tableWidget_rule->horizontalHeader()->resizeSection(2,80);
    ui->tableWidget_rule->horizontalHeader()->resizeSection(3,80);
    ui->tableWidget_rule->horizontalHeader()->resizeSection(4,80);
    ui->tableWidget_rule->horizontalHeader()->resizeSection(5,82);
}

void MainWindow::InitLogTable(){//Initial log table display
    QStringList header;
    header << "Access time" << "Src IP" <<"Dst IP" << "Src port" << "Dst port" << "Protocol" << "Datalen";
    ui->tableWidget_logs->setColumnCount(7);
    ui->tableWidget_logs->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_logs->setFocusPolicy(Qt::NoFocus);
    QHeaderView *headerView = ui->tableWidget_logs->verticalHeader();
    headerView->setHidden(true);
    ui->tableWidget_logs->setHorizontalHeaderLabels(header);
    ui->tableWidget_logs->horizontalHeader()->resizeSection(0,185);
    ui->tableWidget_logs->horizontalHeader()->resizeSection(1,129);
    ui->tableWidget_logs->horizontalHeader()->resizeSection(2,129);
    ui->tableWidget_logs->horizontalHeader()->resizeSection(3,70);
    ui->tableWidget_logs->horizontalHeader()->resizeSection(4,70);
    ui->tableWidget_logs->horizontalHeader()->resizeSection(5,70);
    ui->tableWidget_logs->horizontalHeader()->resizeSection(6,70);
    ui->tableWidget_logs->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

/**
 *  Interface of RulesFilter:
 *  Have the function of loading and saving configuration files, 
 *  or adding, deleting, clearing rules and applying configuration rules
**/

void MainWindow::on_select_pushButton_clicked(){//Select a rule configuration file to save or load
    QFileDialog* fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(tr("Select the file to load or save rule configuration"));//set window title
    fileDialog->setDirectory(".");
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    fileDialog->setViewMode(QFileDialog::Detail);
    if (fileDialog->exec() == QDialog::Accepted)
    {
        QString fileName = fileDialog->selectedFiles()[0];
        ui->lineEdit_rcfg->setText(fileName);//show the selected file
    }
}

void MainWindow::on_load_pushButton_clicked(){//Load rule configuration file
    QByteArray bstr = ui->lineEdit_rcfg->text().toLatin1();
    char *cfg_file = bstr.data();
    if (cfg_file == NULL)
    {
        cout << "Path is empty!" << endl;
        return;
    }
    ifstream ifs(cfg_file, ios::in | ios::binary);//Open file in binary form
    if (! ifs.is_open())
    {
        cout << "File open failed!" << endl;
        return;
    }
    Rule r;
    on_clear_pushButton_clicked();
    while(ifs.read((char *) &r, sizeof(r)))//Read in rules by rule structure
    {
        on_add_pushButton_clicked();
        int row = ui->tableWidget_rule->rowCount() - 1;

        ui->tableWidget_rule->setItem(row, 0, new QTableWidgetItem(QString(r.src_ip)));
        ui->tableWidget_rule->setItem(row, 1, new QTableWidgetItem(QString(r.dst_ip)));
        char buff[20];
        port_merge(r.src_port, r.src_port_end, buff);
        ui->tableWidget_rule->setItem(row, 2, new QTableWidgetItem(QString(buff)));
        port_merge(r.dst_port, r.dst_port_end, buff);
        ui->tableWidget_rule->setItem(row, 3, new QTableWidgetItem(QString(buff)));

        QComboBox *combox = (QComboBox *)(ui->tableWidget_rule->cellWidget(row, 4));
        if (r.protocol == TCP)
            combox->setCurrentIndex(0);
        else if (r.protocol == UDP)
            combox->setCurrentIndex(1);
        else if (r.protocol == ICMP)
            combox->setCurrentIndex(2);
        else    
            combox->setCurrentIndex(3);

        combox = (QComboBox *)(ui->tableWidget_rule->cellWidget(row, 5));
        if (r.log)
            combox->setCurrentIndex(0);
        else
            combox->setCurrentIndex(1);
    }
    ifs.close();
}

void MainWindow::on_save_pushButton_clicked(){//Save rule configuration file
    QByteArray bstr = ui->lineEdit_rcfg->text().toLatin1();
    char *cfg_file = bstr.data();
    if (cfg_file == NULL)
    {
        cout << "Path is empty!" << endl;
        return;
    }//Create a new binary file, write the file in append mode
    ofstream ofs(cfg_file, ios::trunc | ios::binary);
    if (! ofs.is_open())
    {
        cout << "File open failed!" << endl;
        return;
    }

    Rule r;
    char *src_ip = NULL, *dst_ip = NULL;
    char *src_port_range = NULL, *dst_port_range = NULL;
    int row = ui->tableWidget_rule->rowCount();
    for(int i = 0; i < row; i++){//Save the currently displayed rule
        char *src_ip = ui->tableWidget_rule->item(i, 0)->text().toLatin1().data();
        strcpy(r.src_ip, src_ip);
        char *dst_ip = ui->tableWidget_rule->item(i, 1)->text().toLatin1().data();
        strcpy(r.dst_ip, dst_ip);
        src_port_range = ui->tableWidget_rule->item(i, 2)->text().toLatin1().data();
        port_split(src_port_range, &r.src_port, &r.src_port_end);
        dst_port_range = ui->tableWidget_rule->item(i, 3)->text().toLatin1().data();
        port_split(dst_port_range, &r.dst_port, &r.dst_port_end);
        QComboBox *combox = (QComboBox *)(ui->tableWidget_rule->cellWidget(i, 4));
        char *tmp = combox->currentText().toLatin1().data();
        if (tmp[0] == 'T') r.protocol = TCP;
        else if (tmp[0] == 'U') r.protocol = UDP;
        else if (tmp[0] == 'I') r.protocol = ICMP;
        else r.protocol = ANY;
        combox = (QComboBox *)(ui->tableWidget_rule->cellWidget(i, 5));
        tmp = combox->currentText().toLatin1().data();
        if (tmp[0] == 'Y') r.log = 1;
        else if (tmp[0] == 'N') r.log = 0;
        //write to the configuration file
        ofs.write((const char *) &r, sizeof(r));
    }
    ofs.close();
}

void MainWindow::on_add_pushButton_clicked(){//Add new rule line
    int row = ui->tableWidget_rule->rowCount();
    ui->tableWidget_rule->insertRow(row);

    QComboBox *protocol_combox = new QComboBox(); // Lower selection frame
    protocol_combox->addItem("TCP");
    protocol_combox->addItem("UDP");
    protocol_combox->addItem("ICMP");
    //protocol_combox->addItem("HTTP");//supportive application layer
    //protocol_combox->addItem("DNS");
    protocol_combox->addItem("ANY");
    ui->tableWidget_rule->setCellWidget(row, 4, (QWidget*)protocol_combox);
    QComboBox *log_combox = new QComboBox();
    log_combox->addItem("Yes");
    log_combox->addItem("No");
    ui->tableWidget_rule->setCellWidget(row, 5, (QWidget*)log_combox);
}

void MainWindow::on_apply_pushButton_clicked(){//Make the current configuration rules take effect
    long src_ip, dst_ip;
    int src_port, dst_port, src_port_end, dst_port_end;
    char protocol;
    bool log;
    char *tmp = NULL;
    rnum = 0;
    int row = ui->tableWidget_rule->rowCount();
    for(int i = 0; i < row; i++){
        port_split(ui->tableWidget_rule->item(i, 2)->text().toLatin1().data(), &src_port, &src_port_end);
        port_split(ui->tableWidget_rule->item(i, 3)->text().toLatin1().data(), &dst_port, &dst_port_end);
        QComboBox *combox = (QComboBox *)(ui->tableWidget_rule->cellWidget(i, 4));
        tmp = combox->currentText().toLatin1().data();
        if (tmp[0] == 'T') protocol = TCP;
        else if (tmp[0] == 'U') protocol = UDP;
        else if (tmp[0] == 'I') protocol = ICMP;
        else protocol = ANY;
        combox = (QComboBox *)(ui->tableWidget_rule->cellWidget(i, 5));
        tmp = combox->currentText().toLatin1().data();
        if (tmp[0] == 'Y') log = 1;
        else if (tmp[0] == 'N') log = 0;
    //  Add corresponding rules
        AddRule(ui->tableWidget_rule->item(i, 0)->text().toLatin1().data(),
                      ui->tableWidget_rule->item(i, 1)->text().toLatin1().data(),
                      src_port, dst_port, src_port_end, dst_port_end, protocol, log);
    }
    //  Send the rules to the kernel
    SendRules();
}

void MainWindow::on_delete_pushButton_clicked(){//Delete current rule line
    int rowIndex = ui->tableWidget_rule->currentRow();
    if (rowIndex != -1)
        ui->tableWidget_rule->removeRow(rowIndex);
}

void MainWindow::on_clear_pushButton_clicked(){//Clear all rules
    int row = ui->tableWidget_rule->rowCount();
    for (int i = row - 1; i >= 0; i --)
        ui->tableWidget_rule->removeRow(i);
}

void MainWindow::on_accept_radioButton_clicked(){//Set the rule to accept by default
    SetDefault(true);
}

void MainWindow::on_reject_radioButton_clicked(){//Set the rule to reject by default
    SetDefault(false);
}

/**
 *  Interface of LogView:
 *  Have the function of refresh or clear log table
**/
void MainWindow::on_flashlog_pushButton_clicked(){//refresh the log
//note: If capture a large number of packets(like wireshark), Need to dynamically change the allocated memory(eg. vector)
//      Simultaneous kernel dynamic refresh
    int row = ui->tableWidget_logs->rowCount();
    //get log information
    GetLogs(1);
    for (int i = row - 1; i >= 0; i --)
        ui->tableWidget_logs->removeRow(i);
    char buff[20];
    for(int i = 0; i < lnum; i ++){
        row = ui->tableWidget_logs->rowCount();
        ui->tableWidget_logs->insertRow(row);
        time_t ts = (time_t)logs[i].t;
        char *t_str = asctime(localtime(&ts));
        int len = strlen(t_str);
        t_str[len - 1] = '\0';
        ui->tableWidget_logs->setItem(i, 0, new QTableWidgetItem(QString(QLatin1String(t_str))));
        ui->tableWidget_logs->setItem(i, 1, new QTableWidgetItem(QString(QLatin1String(addr_from_net(buff, logs[i].src_ip)))));
        ui->tableWidget_logs->setItem(i, 2, new QTableWidgetItem(QString(QLatin1String(addr_from_net(buff, logs[i].dst_ip)))));
        ui->tableWidget_logs->setItem(i, 3, new QTableWidgetItem(QString::number(logs[i].src_port)));
        ui->tableWidget_logs->setItem(i, 4, new QTableWidgetItem(QString::number(logs[i].dst_port)));
        char *tmp = nullptr;
        switch(logs[i].protocol)
        {
            case TCP:
                tmp = "TCP";
                break;
            case UDP:
                tmp = "UDP";
                break;
            case ICMP:
                tmp = "ICMP";
                break;
        }
        ui->tableWidget_logs->setItem(i, 5, new QTableWidgetItem(QString(QLatin1String(tmp))));
        ui->tableWidget_logs->setItem(i, 6, new QTableWidgetItem(QString::number(logs[i].length)));
    }    
    ui->tableWidget_logs->show();
}

void MainWindow::on_clearlog_pushButton_clicked(){//clear log display
    int row = ui->tableWidget_logs->rowCount();
    for (int i = row - 1; i >= 0; i --)
        ui->tableWidget_logs->removeRow(i);
    memset(logs, 0, sizeof(logs));
    lnum = 0;
    ui->textBrowser_logs->clear();
    GetLogs(0);
}
void MainWindow::on_selectlog_pushButton_clicked(){//Select a file to save or load packet capture log
    QFileDialog* fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(tr("Select a file to save or load packet capture log"));//set window title
    fileDialog->setDirectory(".");
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    fileDialog->setViewMode(QFileDialog::Detail);
    if (fileDialog->exec() == QDialog::Accepted)
    {
        QString fileName = fileDialog->selectedFiles()[0];
        ui->lineEdit_lcfg->setText(fileName);//show the selected file
    }
}

void MainWindow::on_loadlog_pushButton_clicked(){//Load packet capture log
    QByteArray bstr = ui->lineEdit_lcfg->text().toLatin1();
    char *cfg_file = bstr.data();
    if (cfg_file == NULL)
    {
        cout << "Path is empty!" << endl;
        return;
    }
    ifstream ifs(cfg_file, ios::in | ios::binary);//Open file in binary form
    if (! ifs.is_open())
    {
        cout << "File open failed!" << endl;
        return;
    }
    Log l;
    on_clearlog_pushButton_clicked();
    char buff[20];
    while(ifs.read((char *) &l, sizeof(l)))//Read in rules by rule structure
    {
        int i = ui->tableWidget_logs->rowCount();
        ui->tableWidget_logs->insertRow(i);
        logs[i] = l;
        time_t ts = (time_t)l.t;
        char *t_str = asctime(localtime(&ts));
        int len = strlen(t_str);
        t_str[len - 1] = '\0';
        ui->tableWidget_logs->setItem(i, 0, new QTableWidgetItem(QString(QLatin1String(t_str))));
        ui->tableWidget_logs->setItem(i, 1, new QTableWidgetItem(QString(QLatin1String(addr_from_net(buff, l.src_ip)))));
        ui->tableWidget_logs->setItem(i, 2, new QTableWidgetItem(QString(QLatin1String(addr_from_net(buff, l.dst_ip)))));
        ui->tableWidget_logs->setItem(i, 3, new QTableWidgetItem(QString::number(l.src_port)));
        ui->tableWidget_logs->setItem(i, 4, new QTableWidgetItem(QString::number(l.dst_port)));
        char *tmp = nullptr;
        switch(l.protocol)
        {
            case TCP:
                tmp = "TCP";
                break;
            case UDP:
                tmp = "UDP";
                break;
            case ICMP:
                tmp = "ICMP";
                break;
        }
        ui->tableWidget_logs->setItem(i, 5, new QTableWidgetItem(QString(QLatin1String(tmp))));
        ui->tableWidget_logs->setItem(i, 6, new QTableWidgetItem(QString::number(l.length)));

    }
    ifs.close();
}

void MainWindow::on_savelog_pushButton_clicked(){//Save packet capture log
    QByteArray bstr = ui->lineEdit_lcfg->text().toLatin1();
    char *cfg_file = bstr.data();
    if (cfg_file == NULL)
    {
        cout << "Path is empty!" << endl;
        return;
    }//Create a new binary file, write the file in append mode
    ofstream ofs(cfg_file, ios::trunc | ios::binary);
    if (! ofs.is_open())
    {
        cout << "File open failed!" << endl;
        return;
    }

    Log l;
    int row = ui->tableWidget_logs->rowCount();
    for(int i = 0; i < row; i++){//Save the currently displayed rule
        l = logs[i];
        ofs.write((const char *) &l, sizeof(l));
    }
    ofs.close();
}
void MainWindow::on_datalog_pushButton_clicked(){//Get the data of the packet
    ui->textBrowser_logs->clear();
    int pos = ui->tableWidget_logs->currentRow();
    int len = logs[pos].length;
    char str[256] = {0};
    char str_v[128] = {0};
    int cnt = 0;
    int cnt2 = 0;
    char tmp[5] = {0};
    for (int i = 0; i < len; i ++){
        sprintf(tmp, "%02X", logs[pos].data[i]);
        str[cnt ++] = tmp[0], str[cnt ++] = tmp[1], str[cnt ++] = ' ';
        if (logs[pos].data[i] > 32 && logs[pos].data[i] < 127)//printable character
            str_v[cnt2 ++] = logs[pos].data[i];
        else    
            str_v[cnt2 ++] = '.';
        if (i == len - 1)//align
        {
            int p_sp = i;
            while((p_sp + 1) % 16)
                str[cnt ++] = ' ', str[cnt ++] = ' ', str[cnt ++] = ' ', p_sp ++;
        }
        if ((! ((i + 1) % 16)) || i == len - 1){
             str[cnt ++] = '\t', str[cnt ++] = '\0', str_v[cnt2 ++] = '\0', cnt = cnt2 = 0;
             strcat(str, str_v);
             ui->textBrowser_logs->append(str);
        }
    }
}
void MainWindow::on_detailslog_pushButton_clicked(){//Packet detailed data analysis
    ui->textBrowser_logs->clear();
    int pos = ui->tableWidget_logs->currentRow();
    char *result = nullptr;
    result = ParsePacket(logs[pos].length, logs[pos].data);
    char str_res[65536] = {0};
    memcpy(str_res, result, 65535);
    ui->textBrowser_logs->append(str_res);
}




