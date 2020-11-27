#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QWidget>
#include "clamp.h"
#include "CThread.h"
#include "defs.h"
#include <qmath.h>
#include "CSetup.h"
#include <QtWidgets/QPushButton>
#include <QGridLayout>
#include <QCloseEvent>
#include <QApplication>

class CMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CMainWindow(QWidget *parent, Qt::WindowFlags f);
    QWidget *pCentralWidget;
    CLamp *pLamp;                                                        // Указатель на фонарь
    QPushButton *pbSetup, *pbRun, *pbClose;                              // Кнопки управления
    CThread *pThread;                                                    // Указатель на поток обертку
    bool IsRunned;
    bool ClosePermit;
    bool MoveWidget;
    QPoint posPrev;                                                      // Позиция мыши
    QString sURL ="emb2.extcam.xyz";                                     // Хост
    quint16 uiPort =9991;                                                // Порт сервера
    int TimerID;                                                         // Таймер
    QString sColor;                                                      // Цвет полученный от сервера
    ~CMainWindow();
public slots:
    void OnCommandServer(quint16 uiCommand, QString sColor ="");         // Обработка данных от сервера
    void OnRunTorch();                                                   // Обработка запуска фонаря и его отключение
    void OnClose();                                                      // Обработка закрытия
    void OnSetup();                                                      // Настройка
    void OnTakeSetup(QString sHost, quint16 uiPort);                     // Получение настроек
    void OnResult(quint16 result);                                       // Обработка ответных сообщений из потока
protected:
    void timerEvent(QTimerEvent *event);                                 // Таймер
    void closeEvent(QCloseEvent* event);                                 // Переопределение
    void mousePressEvent(QMouseEvent *e);                                // Фиксация перемещения
    void mouseReleaseEvent(QMouseEvent *e);                              // Прекращение перемещения
    void mouseMoveEvent(QMouseEvent *e);                                 // Перемещение
signals:
    void SendRedraw(QString);                                            // Сигнал отрисовки
    void SendThreadCommand(quint16, QString, quint16);                   // Сигнал управления потоком
};
#endif // CMAINWINDOW_H
