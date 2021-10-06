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
    static char mov = 'W';
    static int velocidad =10;
    static bool flag=false;

    if(flag){
        if(!scene()->collidingItems(this).isEmpty()){
            switch(mov){
                case 'S':
                    setPos(mapToParent(0,-10));
                    mov = 'D';
                break;
                case 'W':
                    setPos(mapToParent(0,10));
                    mov='S';



                break;
                case 'D':
                    setPos(mapToParent(-10,0));
                    mov='A';


                break;
                case 'A':
                    setPos(mapToParent(10,0));
                    mov='W';
                break;
            }


        }
        else{
            switch(mov){
                case 'S':
                    setPos(mapToParent(0,10));

                break;
                case 'W':
                    setPos(mapToParent(0,-10));

                break;
                case 'D':
                    setPos(mapToParent(10,0));
                break;
                case 'A':
                    setPos(mapToParent(-10,0));
                break;
            }
        }
    }
    else{
      //setPos(mapToParent(-10,0));
      flag=true;
      mov='S';
    }




}

void Enemigo::colision()
{

}

int Enemigo::getPosX() const
{
    return PosX;
}
