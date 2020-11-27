#include "clamp.h"

CLamp::CLamp(quint16 mID, QWidget* pwgt, Qt::WindowFlags f) : QWidget(pwgt, f)
{
    this->setFixedSize(200,200);                                         // Установка постоянного размера лампочки
    IsSet = false;                                                       // По данному флагу определяется цвет лампочки
    ID = mID;                                                            // Присвоение идентификатора лампочке
    sColor = "ff000000"; //"ffff8866";                                   // Изначально выключенный
}
void CLamp::paintEvent(QPaintEvent*)
{
    // Рисование лампочки
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QBrush(QColor::fromRgb(QRgb(sColor.toUInt(0,16))).darker(130)));
    QPen pen(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawEllipse(QRect(20, 20, 165, 165));
    // Делается блик
    QColor color;
    color = QColor::fromRgb(QRgb(sColor.toUInt(0,16))).darker(110);
    painter.setBrush(color);
    pen.setColor(color);
    painter.setPen(pen);
    painter.drawEllipse(QRect(24, 24, 155, 155));
    color = QColor::fromRgb(QRgb(sColor.toUInt(0,16))).lighter(110);
    painter.setBrush(color);
    pen.setColor(color);
    painter.setPen(pen);
    painter.drawEllipse(QRect(24, 24, 145, 145));
    color = QColor::fromRgb(QRgb(sColor.toUInt(0,16))).lighter(120);
    painter.setBrush(color);
    pen.setColor(color);
    painter.setPen(pen);
    painter.drawEllipse(QRect(38, 28, 80, 80));
    color = QColor::fromRgb(QRgb(sColor.toUInt(0,16))).lighter(130);
    painter.setBrush(color);
    pen.setColor(color);
    painter.setPen(pen);
    painter.drawEllipse(QRect(43, 33, 60, 60));
    // Белый отблеск
    painter.setBrush(Qt::white);
    pen.setColor(Qt::white);
    painter.setPen(pen);
    painter.drawEllipse(QRect(50, 42, 30, 30));
    painter.end();
}
// Перерисовка по полученным данным
void CLamp::ReDraw(QString sColor)
{
    if(sColor.size()!=8)return;
    this->sColor = sColor;
    this->update();
}

