#include <QTabWidget>

#include "app_setting.h"

App_Setting::App_Setting()
{
    setWindowTitle("Setup");
    QTabWidget *tab_widget = new QTabWidget;
    tab_widget->addTab(new QWidget(),tr("Tab 1"));

}

App_Setting::~App_Setting()
{
    ;
}
