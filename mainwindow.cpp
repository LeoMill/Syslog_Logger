#include <QDebug>
#include <QMessageBox>

#include "app_setting.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Syslog Logger");
    QMenu *file = menuBar()->addMenu(tr("&Setting"));
    QAction *settingAct = file->addAction(tr("&Setting"), this, &MainWindow::setting);
    settingAct->setToolTip(tr("Show the application's Setting"));

    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    QAction *aboutAct = helpMenu->addAction(tr("&About"), this, &MainWindow::about);
    aboutAct->setStatusTip(tr("Show the application's About box"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Syslog Logger"),
                             tr("The <b>Syslog Logger</b> demonstrates how to "
                             "write modern GUI applications using Qt. "
                             "Credits: Icon made by ... from ..."));
}

void MainWindow::setting()
{
    int value;
    Setup_Info_s setup_info = {0, 0, 0, 0, 0};

    App_Setting *setting = new App_Setting(this);
    setting->Set_Info_Parameter(&setup_info);
    value = setting->exec();
    if(value)
    {
        setting->~App_Setting();
    }
}
