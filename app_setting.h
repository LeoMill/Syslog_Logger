#ifndef APP_SETTING_H
#define APP_SETTING_H

#include <QDialog>
#include <QObject>
#include <QGridLayout>
#include <QTabWidget>

class App_Setting : public QDialog
{
    Q_OBJECT
public:
    //App_Setting();
    explicit App_Setting(QWidget *parent = nullptr);
    ~App_Setting();

private slots:
    ;

private:
    QTabWidget *tab_widget_ = nullptr;
    QGridLayout *main_layout_ = nullptr, *set_main_layout_ = nullptr, *file_layout_ = nullptr, *mail_layout_ = nullptr;
};

#endif // APP_SETTING_H
