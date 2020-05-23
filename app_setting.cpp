

#include "app_setting.h"

App_Setting::App_Setting(QWidget *parent) : QDialog(parent)

{
    tab_widget_ = new QTabWidget;
    tab_widget_->addTab(new QWidget(), tr("Main"));
    tab_widget_->addTab(new QWidget(), tr("Files"));
    tab_widget_->addTab(new QWidget(), tr("E-mail"));

    main_layout_ = new QGridLayout;
    main_layout_->addWidget(tab_widget_, 0, 0);
    setLayout(main_layout_);
    setWindowTitle("Setup");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    resize(800, 600);
}

App_Setting::~App_Setting()
{
    delete tab_widget_;
    delete main_layout_;
    delete set_main_layout_;
    delete file_layout_;
    delete mail_layout_;
}
