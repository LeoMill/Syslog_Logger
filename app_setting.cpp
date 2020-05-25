#include <stdio.h>
#include <string.h>

#include "app_setting.h"

App_Setting::App_Setting(QWidget *parent) : QDialog(parent)
{
    tab_widget_ = new QTabWidget;
    tab_main_ = new QWidget;
    tab_file_ = new QWidget;
    tab_mail_ = new QWidget;
    tab_widget_->addTab(tab_main_, tr("Main"));
    tab_widget_->addTab(tab_file_, tr("Files"));
    tab_widget_->addTab(tab_mail_, tr("E-mail"));

    main_layout_ = new QGridLayout;
    main_layout_->addWidget(tab_widget_, 0, 0);
    setLayout(main_layout_);
    setWindowTitle("Setup");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    resize(800, 600);
    set_main_layout_ = new QGridLayout;
    cb_udp_ = new QCheckBox(tr("Enable UDP listener"));
    cb_tcp_ = new QCheckBox(tr("Enable TCP listener"));
    cb_hightlight_3d_ = new QCheckBox(tr("Enable highlight with 3D fill"));
    cb_raw_ = new QCheckBox(tr("Write all messages to raw data"));
    set_main_layout_->addWidget(cb_udp_, 0, 0);
    set_main_layout_->addWidget(cb_tcp_, 1, 0);
    set_main_layout_->addWidget(cb_hightlight_3d_, 2, 0);
    set_main_layout_->addWidget(cb_raw_, 3, 0);
    tab_main_->setLayout(set_main_layout_);
    memset(&setup_info_, 0, sizeof(Setup_Info_s));
}

void App_Setting::closeEvent(QCloseEvent *e)
{
    if(Qt::Checked == cb_udp_->checkState())
        setup_info_.Enable_Bitmask |= ENABLE_UDP_LISTEN;

    if(Qt::Checked == cb_tcp_->checkState())
        setup_info_.Enable_Bitmask |= ENABLE_TCP_LISTEN;

    if(Qt::Checked == cb_hightlight_3d_->checkState())
        setup_info_.Enable_Bitmask |= ENABLE_HL_3D;

    if(Qt::Checked == cb_raw_->checkState())
        setup_info_.Enable_Bitmask |= ENABLE_RAW_FILE;
}

App_Setting::~App_Setting()
{
    delete tab_file_;
    delete tab_mail_;
    delete cb_udp_;
    delete cb_tcp_;
    delete cb_hightlight_3d_;
    delete cb_raw_;
    delete set_main_layout_;
    delete tab_main_;
    delete main_layout_;
    delete file_layout_;
    delete mail_layout_;
    delete tab_widget_;
}
