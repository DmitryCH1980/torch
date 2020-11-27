#ifndef CTHREAD_H
#define CTHREAD_H
#include <QThread>
#include <QTcpSocket>
#include "defs.h"
// Обертка для объектов отправки, получения и прослушивания
class CThread : public QThread
{
    Q_OBJECT
public:
    explicit CThread(QObject* parent) : QThread(parent)
    {
       qRegisterMetaType<QAbstractSocket::SocketError>("QAbstractSocket::SocketError");
    }
    QTcpSocket *pSocket = NULL;
    bool IsConnected =false;
    void run()
    {
        emit SendResult(READY);
        exec();
    }
public slots:
    void NewConnection(QString sURL, quint16 uiPort);                    // Создание нового соединения
    void CommandConnection(quint16 bCommand,
                           QString sURL ="", quint16 uiPort =0);         // Команды управления
    void DelSocket();                                                    // Удаление сокета при разрыве соединения
    void OnRead();                                                       // Чтение данных из сокета
    void OnConnected();                                                  // Соединение получено
    void OnSocketError();                                                // Ошибка соединения
    void quit(/*quint32 nid*/)
    {
        this->exit(0);
    }
signals:
    void SendStop();                                                     // Остановка потока
    void SendResult(quint16);                                            // Отправка кода результата
    void SendServerCommand(quint16, QString);                            // Отправка данных сервера в фонарь
};
#endif // CTHREAD_H
