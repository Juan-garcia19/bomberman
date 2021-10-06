#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

class Enemigo : public QGraphicsItem
{
public:
    Enemigo(int _posX, int _PosY, int _ancho, int _largo);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

    int getPosX() const;

protected slots:
    void advance(int phase);


private:
    void colision();

    int PosX, PosY;
    int Ancho, Largo;
    int velocidad = 10;
};

#endif // ENEMIGO_H
