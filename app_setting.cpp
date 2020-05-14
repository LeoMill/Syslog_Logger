#include <QTabWidget>
#include <QGridLayout>

#include "app_setting.h"

App_Setting::App_Setting()
{
    QTabWidget *tab_widget = new QTabWidget;
    tab_widget->addTab(new QWidget(),tr("Main"));
    tab_widget->addTab(new QWidget(),tr("Files"));
    tab_widget->addTab(new QWidget(),tr("E-mail"));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(tab_widget, 0, 0);
    setLayout(mainLayout);
    setWindowTitle("Setup");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

App_Setting::~App_Setting()
{
    ;
}
