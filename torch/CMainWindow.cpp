#include "CMainWindow.h"

CMainWindow::CMainWindow(QWidget *parent, Qt::WindowFlags f)
    : QWidget(parent, f)
{   
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    this->setAttribute( Qt::WA_TranslucentBackground, true );
    pCentralWidget = this;
    IsRunned =false;
    ClosePermit =true;
    MoveWidget =false;
    pLamp = new CLamp(1, pCentralWidget);
    pbSetup = new QPushButton(QIcon(":/Set_1.png"),"", this);
    pbSetup->setFixedSize(47,47);
    pbSetup->setStyleSheet("QPushButton{ \
                              background-color: qradialgradient(cx:0.5, cy:0.5, radius: 0.7, fx:0.5, fy:0.5, \
                              stop:0 #DFDFFF, stop:1 #A6A6B8 ); \
                              border-style: outset; border-width: 2px; border-color: #5A5A5A; text-align: center; \
                              color: #404040; } \
                              QPushButton:pressed { \
                              background-color: qradialgradient(cx:0.5, cy:0.5, radius: 0.7, fx:0.5, fy:0.5, \
                              stop:0 #A6A6B8 , stop:1 #DBDBFF ); \
                              border-style: inset; border-width: 2px; border-color: #383838; text-align: center;\
                              color: #404040; } \
                              QPushButton:hover:!pressed { \
                              background-color: qradialgradient(cx:0.5, cy:0.5, radius: 0.7, fx:0.5, fy:0.5, \
                              stop:0 #DFDFFF, stop:1 #9090A2 ); \
                              border-style: outset; border-width: 2px; border-color: #5A5A5A; text-align: center; \
                              color: #404040; }\
                              QPushButton:!enabled { \
                              background-color: qradialgradient(cx:0.5, cy:0.5, radius: 0.7, fx:0.5, fy:0.5, \
                              stop:0 #82829A, stop:1 #686889 ); \
                              border-style: outset; border-width: 2px; border-color: #383838; text-align: center;\
                              color: #404040; }");
    pbRun = new QPushButton(QIcon(":/Start_1.png"), "", this);
    pbRun->setFixedSize(47,47);
    pbRun->setStyleSheet("QPushButton{ \
                              background-color: qradialgradient(cx:0.5, cy:0.5, radius: 0.7, fx:0.5, fy:0.5, \
                              stop:0 #DFDFFF, stop:1 #A6A6B8 ); \
                              border-style: outset; border-width: 2px; border-color: #5A5A5A; text-align: center; \
                              color: #404040; } \
                              QPushButton:pressed { \
                              background-color: qradialgradient(cx:0.5, cy:0.5, radius: 0.7, fx:0.5, fy:0.5, \
                              stop:0 #A6A6B8 , stop:1 #DBDBFF ); \
                              border-style: inset; border-width: 2px; border-color: #383838; text-align: center;\
                              color: #404040; } \
                              QPushButton:hover:!pressed { \
                              background-color: qradialgradient(cx:0.5, cy:0.5, radius: 0.7, fx:0.5, fy:0.5, \
                              stop:0 #DFDFFF, stop:1 #9090A2 ); \
                              border-style: outset; border-width: 2px; border-color: #5A5A5A; text-align: center; \
                              color: #404040; }\
                              QPushButton:!enabled { \
                              background-color: qradialgradient(cx:0.5, cy:0.5, radius: 0.7, fx:0.5, fy:0.5, \
                              stop:0 #82829A, stop:1 #686889 ); \
                              border-style: outset; border-width: 2px; border-color: #383838; text-align: center;\
                              color: #404040; }");
    pbClose = new QPushButton(QIcon(":/images7.png"), "", this);
    pbClose->setFixedSize(47,47);
    pbClose->setStyleSheet("QPushButton{ \
                              background-color: qradialgradient(cx:0.5, cy:0.5, radius: 0.7, fx:0.5, fy:0.5, \
                              stop:0 #DFDFFF, stop:1 #A6A6B8 ); \
                              border-style: outset; border-width: 2px; border-color: #5A5A5A; text-align: center; \
                              color: #404040; } \
                              QPushButton:pressed { \
                              background-color: qradialgradient(cx:0.5, cy:0.5, radius: 0.7, fx:0.5, fy:0.5, \
                              stop:0 #A6A6B8 , stop:1 #DBDBFF ); \
                              border-style: inset; border-width: 2px; border-color: #383838; text-align: center;\
                              color: #404040; } \
                              QPushButton:hover:!pressed { \
                              background-color: qradialgradient(cx:0.5, cy:0.5, radius: 0.7, fx:0.5, fy:0.5, \
                              stop:0 #DFDFFF, stop:1 #9090A2 ); \
                              border-style: outset; border-width: 2px; border-color: #5A5A5A; text-align: center; \
                              color: #404040; }\
                              QPushButton:!enabled { \
                              background-color: qradialgradient(cx:0.5, cy:0.5, radius: 0.7, fx:0.5, fy:0.5, \
                              stop:0 #82829A, stop:1 #686889 ); \
                              border-style: outset; border-width: 2px; border-color: #383838; text-align: center;\
                              color: #404040; }");
    QGridLayout *mLayout_1 = new QGridLayout;
    mLayout_1->setSpacing(2);
    mLayout_1->addWidget(pbRun, 0, 0, 1, 1, Qt::AlignCenter);
    mLayout_1->addWidget(pbSetup, 0, 1, 1, 1, Qt::AlignCenter);
    mLayout_1->addWidget(pbClose, 0, 2, 1, 1, Qt::AlignCenter);
    mLayout_1->addWidget(pLamp, 1, 0, 1, 3, Qt::AlignCenter);
    pCentralWidget->setLayout(mLayout_1);
    // Сигналы/ слоты
    connect(pbRun,SIGNAL(clicked(bool)),
            this, SLOT(OnRunTorch()),
            Qt::QueuedConnection);
    connect(pbClose, SIGNAL(clicked(bool)),
            this, SLOT(OnClose()),
            Qt::QueuedConnection);
    connect(pbSetup, SIGNAL(clicked(bool)),
            this, SLOT(OnSetup()),
            Qt::QueuedConnection);
    // Создание потока связи с сервером
    pThread = new CThread(0);
    connect(pThread, SIGNAL(SendResult(quint16)),
            this, SLOT(OnResult(quint16)),
            Qt::QueuedConnection);                                       // Обработка сигналов отработанных команд
    connect(this, SIGNAL(SendThreadCommand(quint16,QString,quint16)),
            pThread, SLOT(CommandConnection(quint16,QString,quint16)),
            Qt::QueuedConnection);                                       // Отправка команд в поток
    connect(pThread, SIGNAL(SendStop()),
            pThread, SLOT(quit()),
            Qt::QueuedConnection);                                       // Удаление потока
    connect(pThread, SIGNAL(SendServerCommand(quint16,QString)),
            this, SLOT(OnCommandServer(quint16, QString )),
            Qt::QueuedConnection);                                       // Передача данных сервера на отрисовку
    pThread->moveToThread(pThread);
    pThread->start();
    connect(this, SIGNAL(SendRedraw(QString)),
            pLamp, SLOT(ReDraw(QString)),
            Qt::QueuedConnection);                                       // Передача данных на отрисовку
    sColor ="ff000000";
    TimerID = startTimer(4);
}
// Обработка ответных сообщений из потока
void CMainWindow::OnResult(quint16 result)
{
    // Если поток запущен, то запрет на удаление
    if(result == READY)
    {
        ClosePermit =false;
        return;
    }
    // Если поток удаляется
    if(result ==THREAD_DELETED)
    {
        if(ClosePermit ==true)return;
        SendRedraw("ff000000");
        pThread->wait();
        delete pThread;
        pThread = NULL;
        ClosePermit =true;
        OnClose();
        return;
    }
    // Если подключились
    if(result ==STARTED)
    {
        IsRunned = true;
        pbRun->setIcon(QIcon(":/Stop_1.png"));
        pbSetup->setEnabled(false);
        return;
    }
    // Если была ошибка подключения или сброс
    if((result ==CONNECTION_DISCARDED)||(result ==CONNECTION_ERROR))
    {
        IsRunned = false;
        pbRun->setIcon(QIcon(":/Start_1.png"));
        pbSetup->setEnabled(true);
        sColor ="ff000000";
        return;
    }
}
// Запуск и останов работы фонаря
void CMainWindow::OnRunTorch()
{
    if(!IsRunned)
    {
        emit SendThreadCommand(ONSTART,sURL,uiPort);
    }
    else
    {
        emit SendThreadCommand(ONSTOP,"",0);
    }
}
// Закрытие приложения
void CMainWindow::OnClose()
{
    QCloseEvent* e = new QCloseEvent();
    QApplication::sendEvent(this, e);
}
// Настройка
void CMainWindow::OnSetup()
{
    CSetup* pSetup = new CSetup(this, Qt::WindowCloseButtonHint);
    connect(pSetup, SIGNAL(SendConfig(QString,quint16)),
            this, SLOT(OnTakeSetup(QString,quint16)),
            Qt::QueuedConnection);
    pSetup->setWindowIcon(QIcon(":/Set_1.png"));
    pSetup->setWindowTitle("Настройка соединения");
    pSetup->setModal(true);
    pSetup->show();
    pSetup->setFixedSize(pSetup->size());
}
// Получение настроек
void CMainWindow::OnTakeSetup(QString sHost, quint16 uiPort)
{
    this->sURL = sHost;
    this->uiPort = uiPort;
}
void CMainWindow::OnCommandServer(quint16 uiCommand, QString sColor)
{
    switch (uiCommand) {
    case 0x12:
        this->sColor ="ffffffff";
        break;
    case 0x13:
        this->sColor ="ff000000";
        break;
    case 0x20:
        this->sColor = sColor;
        break;
    default:
        break;
    }
}
CMainWindow::~CMainWindow()
{
}
// Закрытие если только разрешено
void CMainWindow::closeEvent(QCloseEvent *event)
{
    if(ClosePermit)
    {
        if(TimerID!=0)
        {
            killTimer(TimerID);
            TimerID =0;
        }
        event->accept();
        this->close();
        return;
    }
        event->ignore();
        emit SendThreadCommand(ONDELETE,"",0);
}
// Для перемещения
void CMainWindow::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        this->posPrev = e->globalPos();
        MoveWidget =true;
    }
}
// Прекращение перемещения
void CMainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
        MoveWidget =false;
}
void CMainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(!MoveWidget)return;
     QPoint dt = QPoint(this->posPrev - e->globalPos());
     this->move(this->pos()-dt);
     this->posPrev = e->globalPos();
 }
void CMainWindow::timerEvent(QTimerEvent *event)
{
    // Наш ли таймер
    if(event->timerId()!=TimerID)return;
    quint32 currentColor = pLamp->sColor.toUInt(0,16);
    quint32 newColor = this->sColor.toUInt(0,16);
    quint32 uiOldRR =0, uiOldGG =0, uiOldBB =0;
    quint32 uiNewRR =0, uiNewGG =0, uiNewBB =0;
    quint32 uiRR =0, uiGG =0, uiBB =0;
    // Разложение старого цвета
    uiOldRR = ((currentColor <<8)>>24);
    uiOldGG = ((currentColor <<16)>>24);
    uiOldBB = ((currentColor <<24)>>24);
    // Разложение нового цвета
    uiNewRR = ((newColor <<8)>>24);
    uiNewGG = ((newColor <<16)>>24);
    uiNewBB = ((newColor <<24)>>24);
    // Расчет по каждому каналу
    // Красный
    if(uiOldRR < uiNewRR)
    {
        uiRR =uiOldRR + 1;
    }
    else if(uiOldRR > uiNewRR)
    {
        uiRR =uiOldRR -1 ;
    }
    // Зеленый
    if(uiOldGG < uiNewGG)
    {
        uiGG =uiOldGG + 1;
    }
    else if(uiOldGG > uiNewGG)
    {
        uiGG =uiOldGG - 1;
    }
    // Синий
    if(uiOldBB < uiNewBB)
    {
        uiBB =uiOldBB + 1;
    }
    else if(uiOldBB > uiNewBB)
    {
        uiBB =uiOldBB - 1;
    }
    // Сборка цвета
    currentColor =0;
    currentColor = (0xff <<24);                                          // Альфа
    currentColor += (uiRR <<16);                                         // RR
    currentColor += (uiGG <<8);                                          // GG
    currentColor += uiBB;                                                // BB
    emit SendRedraw(QString::number(currentColor,16));
}

