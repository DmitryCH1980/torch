#ifndef CLAMP_H
#define CLAMP_H

#include <QWidget>
#include <qpainter.h>
#include <QString>

// Класс маленькой лампочки
class CLamp : public QWidget
{
    Q_OBJECT
public:
    CLamp(quint16 mID =0, QWidget* pwgt =0, Qt::WindowFlags f=0);
    bool IsSet;
    quint16 ID;
    QString sColor;
protected:
    void paintEvent(QPaintEvent*);
public slots:
    void ReDraw(QString sColor);                                         // Обработчик цветов
};

#endif // CLAMP_H
