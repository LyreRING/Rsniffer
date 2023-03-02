#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStringList>
#include <QHeaderView>
#include <QDebug>
#include <QComboBox>
#include <QFileDialog>
#include <QByteArray>

/******************************************************************
    This file define the functions required for the RsnifferGui
*******************************************************************/

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void InitRuleTable();
    void InitLogTable();
    
private slots:
//  function of RulesFilter:
    void on_select_pushButton_clicked();
    void on_load_pushButton_clicked();
    void on_save_pushButton_clicked();
    void on_add_pushButton_clicked();
    void on_delete_pushButton_clicked();
    void on_clear_pushButton_clicked();
    void on_apply_pushButton_clicked();
    void on_accept_radioButton_clicked();
    void on_reject_radioButton_clicked();
//  function of LogView:   
    void on_flashlog_pushButton_clicked();
    void on_clearlog_pushButton_clicked();
    void on_selectlog_pushButton_clicked();
    void on_loadlog_pushButton_clicked();
    void on_savelog_pushButton_clicked();
    void on_datalog_pushButton_clicked();
    void on_detailslog_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
