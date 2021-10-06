#include "enemigo.h"

Enemigo::Enemigo(int _posX, int _PosY, int _ancho, int _largo)
{
    PosX = _posX;
    PosY = _PosY;
    Ancho = _ancho;
    Largo = _largo;
}

QRectF Enemigo::boundingRect() const
{
    return QRectF(PosX, PosY, Ancho, Largo);
}

void Enemigo::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap pixMap(":/Mapa/Texturas/rompible.png");
    pixMap = pixMap.scaled(Ancho, Largo);
    painter->drawPixmap(PosX,PosY,pixMap);
}

void Enemigo::advance(int phase)
{
    if(! phase) return;
    static char mov = 'W';
    //QPointF location = this->pos();
    setPos(mapToParent(0,velocidad)));

    if( mov == 'W'){
        setPos(mapToParent(0,-(velocidad)));
        if(!scene()->collidingItems(this).isEmpty()){
           mov ='D';
        }
    }
    else if(mov == 'D'){
        setPos(mapToParent(velocidad,0));
        if(!scene()->collidingItems(this).isEmpty()){
           mov ='S';
        }
    }
    else if(mov == 'S'){
        setPos(mapToParent(0,velocidad));
        if(!scene()->collidingItems(this).isEmpty()){
           mov ='A';
        }
    }
    else if(mov == 'A'){
        setPos(mapToParent(-(velocidad),0));
        if(!scene()->collidingItems(this).isEmpty()){
           mov ='W';
        }
    }
    //setPos(mapToParent(velocidad,0));
    //colision();




}

void Enemigo::colision()
{
    if (!scene()->collidingItems(this).isEmpty()){
        QPointF location = this->pos();
        setPos(mapToParent(0,-velocidad));
    }
}

int Enemigo::getPosX() const
{
    return PosX;
}
