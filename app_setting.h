#ifndef APP_SETTING_H
#define APP_SETTING_H

#include <QCheckBox>
#include <QDialog>
#include <QObject>
#include <QGridLayout>
#include <QLineEdit>
#include <QTabWidget>

#define ENABLE_UDP_LISTEN   1
#define ENABLE_TCP_LISTEN   2
#define ENABLE_HL_3D        4
#define ENABLE_RAW_FILE     8

typedef struct
{
    unsigned short Enable_Bitmask;
    unsigned int TCP_IP;
    unsigned int UDP_IP;
    unsigned int TCP_Port;
    unsigned int UDP_Port;
}Setup_Info_s;

class App_Setting : public QDialog
{
    Q_OBJECT
public:
    //App_Setting();
    explicit App_Setting(QWidget *parent = nullptr);
    ~App_Setting();
    void Set_Info_Parameter(Setup_Info_s *set_info);

private slots:

private:
    // override
    void closeEvent(QCloseEvent *event);

    QTabWidget *tab_widget_ = nullptr;
    QWidget *tab_main_ = nullptr, *tab_file_ = nullptr, *tab_mail_ = nullptr;
    QGridLayout *main_layout_ = nullptr, *set_main_layout_ = nullptr, *file_layout_ = nullptr, *mail_layout_ = nullptr;
    QCheckBox *cb_udp_ = nullptr, *cb_tcp_ = nullptr, *cb_hightlight_3d_ = nullptr, *cb_raw_ = nullptr;
    QLineEdit *le_ip_ = nullptr, *le_port_ = nullptr;
    Setup_Info_s setup_info_;
};

#endif // APP_SETTING_H
