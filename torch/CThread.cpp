#include "CThread.h"
// Создание нового соединения
void CThread::NewConnection(QString sURL, quint16 uiPort)                     // Создание нового соединения
{
    if(pSocket!=NULL)
    {
        // Производится отключение сигналов
        pSocket->disconnect();
        pSocket->deleteLater();                                          // Удаление отключенного сокета тогда, когда это будет возможным
    }
    pSocket =NULL;                                                       // Отвязать указатель обязательно!
    pSocket = new QTcpSocket(0);
    pSocket->connectToHost(sURL, uiPort);
    connect(pSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(OnSocketError()), Qt::QueuedConnection);
    connect(pSocket, SIGNAL(connected()), this, SLOT(OnConnected()), Qt::QueuedConnection);
    connect(pSocket, SIGNAL(readyRead()), this, SLOT(OnRead()), Qt::QueuedConnection);
    connect(pSocket, SIGNAL(disconnected()), this, SLOT(DelSocket()), Qt::QueuedConnection);
    IsConnected = false;
}
// Удаление сокета
void CThread::DelSocket()
{
    if(pSocket!=NULL)
    {
        // Производится отключение сигналов
        pSocket->disconnect();
        pSocket->deleteLater();                                          // Удаление отключенного сокета тогда, когда это будет возможным
    }
    pSocket =NULL;                                                       // Отвязать указатель обязательно!
    emit SendResult(CONNECTION_DISCARDED);
    IsConnected = false;
}
// Соединение получено (можно читать данные из сокета, это разрешение)
void CThread::OnConnected()
{
    IsConnected = true;
    emit SendResult(STARTED);                                            // Сообщение что соединение установлено
}
// Ошибка соединения
void CThread::OnSocketError()
{
    if(pSocket!=NULL)
    {
        // Производится отключение сигналов
        pSocket->disconnect();
        pSocket->deleteLater();                                          // Удаление отключенного сокета тогда, когда это будет возможным
    }
    pSocket =NULL;                                                       // Отвязать указатель обязательно!
    emit SendResult(CONNECTION_ERROR);
    IsConnected = false;
}
// Команды управления
void CThread::CommandConnection(quint16 bCommand, QString sURL, quint16 uiPort)
{
    // Обработка команд от окна
    switch (bCommand) {
    case ONSTART:
    {
        // Если не передали никаких данных с командой, тогда на остановку
        if((sURL.isEmpty())||(uiPort ==0))
        {
            OnSocketError();
            break;
        }
        // Создание нового соединения
        NewConnection(sURL, uiPort);
        break;
    }
    case ONSTOP:
    {
        // Просто остановка
        DelSocket();
        break;
    }
    case ONDELETE:
    {
        // Удаление сокета
        DelSocket();
        emit SendResult(THREAD_DELETED);
        emit SendStop();
        break;
    }
    default:
        break;
    }
}
// Чтение данных из сокета
void CThread::OnRead()
{
    QByteArray aArray = pSocket->readAll();
    quint8 ucCommand;
    quint16 length;
    quint8 *uiData;
    quint32 uiColor;
    QString sColor;
    // Получено слишком мало данных
    if(aArray.size() < 3)return;
    // Получение команды
    ucCommand = (quint8)*(aArray.data());
    switch (ucCommand) {
    // Включение фонаря
    case 0x12:
        emit SendServerCommand(0x12, "");
        break;
    // Выключение фонаря
    case 0x13:
        emit SendServerCommand(0x13, "");
        break;
    // Передача цвета
    case 0x20:
    {
        if(aArray.size() < 6)return;
        length =0;
        length += (((quint16)((unsigned char)*(aArray.data() + 1))) << 8);
        length += ((quint16)((unsigned char)*(aArray.data() + 2)));
        if(length!=3)break;
        uiData = new quint8[length];
        for(int i=0; i < length; i++)
            uiData[i] = ((quint8)((unsigned char)*(aArray.data() + 3 + i)));
        uiColor =0;
        uiColor += (0xff << 24);                                         // Альфа
        uiColor += (((quint32)uiData[0]) << 16);                         // RR
        uiColor += (((quint32)uiData[1]) << 8);                          // GG
        uiColor += ((quint32)uiData[2]);                                 // BB
        sColor =QString::number(uiColor,16);
        emit SendServerCommand(0x20, sColor);
        delete [] uiData;
        break;
    }
    default:
        break;
    }
}
