#include "CSetup.h"

CSetup::CSetup(QWidget *pwgt, Qt::WindowFlags f):QDialog(pwgt, f)
{
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    QFont font("Times", 10);
    font.setBold(true);
    // Лэйбл хоста
    plHost = new QLabel(this);
    plHost->setAlignment(Qt::AlignCenter);
    plHost->setFont(font);
    plHost->setText("Адрес хоста");
    // Лэйбл порта
    plPort = new QLabel(this);
    plPort->setAlignment(Qt::AlignCenter);
    plPort->setFont(font);
    plPort->setText("Порт");
    // Эдит хоста
    peHost = new QLineEdit(this);
    peHost->setAlignment(Qt::AlignCenter);
    peHost->setFont(font);
    peHost->setText("emb2.extcam.xyz");
    // Эдит порта
    pePort = new QLineEdit(this);
    pePort->setAlignment(Qt::AlignCenter);
    pePort->setFont(font);
    pePort->setInputMask("99999");
    pePort->setText("9991");
    // Кнопка на передачу
    pbOk = new QPushButton("OK", this);
    pbOk->setStyleSheet("text-align: center");
    pbOk->setFont(font);
    connect(pbOk, SIGNAL(clicked(bool)),
            this, SLOT(OnOk()),
            Qt::QueuedConnection);
    QGridLayout *mLayout_1 = new QGridLayout;
    mLayout_1->setSpacing(2);
    mLayout_1->addWidget(plHost, 0, 0, 1, 1, Qt::AlignCenter);
    mLayout_1->addWidget(plPort, 0, 1, 1, 1, Qt::AlignCenter);
    mLayout_1->addWidget(peHost, 1, 0, 1, 1, Qt::AlignCenter);
    mLayout_1->addWidget(pePort, 1, 1, 1, 1, Qt::AlignCenter);
    mLayout_1->addWidget(pbOk, 2, 0, 1, 2, Qt::AlignCenter);
    this->setLayout(mLayout_1);
}
CSetup::~CSetup()
{
}
void CSetup::OnOk()
{
    QString sHost = peHost->text();
    quint16 uiPort;
    if(sHost.isEmpty())return;
    uiPort = pePort->text().toUInt();
    if(uiPort ==0)return;
    emit SendConfig(sHost, uiPort);
    this->close();
}
