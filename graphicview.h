#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>

class GraphicsView : public QGraphicsView
{
public:
    explicit GraphicsView(QWidget* parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent* event) override;
};

#endif // MYGRAPHICSVIEW_H
