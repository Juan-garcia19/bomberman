#include "bricks.h"

Bricks::Bricks(int _posX, int _PosY, int _ancho, int _largo)
{
    PosX = _posX;
    PosY = _PosY;
    Ancho = _ancho;
    Largo = _largo;
}

QRectF Bricks::boundingRect() const
{
    return QRectF(PosX, PosY, Ancho, Largo);
}

int Bricks::getPosX() const
{
    return PosX;
}

int Bricks::getPosY() const
{
    return PosY;
}

void Bricks::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap pixMap(":/Mapa/Texturas/rompible.png");
    pixMap = pixMap.scaled(Ancho, Largo);
    painter->drawPixmap(PosX,PosY,pixMap);

}
