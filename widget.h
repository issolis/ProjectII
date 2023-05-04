#ifndef WIDGET_H
#define WIDGET_H

#include <QObject>
#include <QGraphicsView>

class Widget : public QObject
{
    Q_OBJECT
public:
    explicit Widget(QObject *parent = nullptr);
    QGraphicsView view;

signals:

};

#endif // WIDGET_H
