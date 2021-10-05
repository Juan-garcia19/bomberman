#ifndef BRICKS_H
#define BRICKS_H

#include <QGraphicsItem>
#include <QPainter>

class Bricks : public QGraphicsItem
{
public:
    Bricks( int _posX, int _PosY, int _ancho, int _largo);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

    int getPosX() const;

    int getPosY() const;

private:
    int PosX, PosY;
    int Ancho, Largo;
    QBrush brush;
};

#endif // BRICKS_H
