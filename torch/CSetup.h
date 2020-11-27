#ifndef CSETUP_H
#define CSETUP_H
#include <QDialog>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QCloseEvent>
// Окно настроек
class CSetup : public QDialog
{
    Q_OBJECT
public:
    explicit CSetup(QWidget *pwgt =NULL, Qt::WindowFlags f =0);
    QLineEdit *peHost, *pePort;
    QPushButton *pbOk;
    QLabel *plHost, *plPort;
    ~CSetup();
public slots:
    void OnOk();
signals:
    void SendConfig(QString, quint16);                                   // Отправка настроек
};

#endif // CSETUP_H
