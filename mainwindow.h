#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <fstream>
#include <iostream>
#include <vector>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>

#include "bricks.h"
#include "enemigo.h"

#include <stdlib.h>
#include <time.h>

#define Imag_Borr "../Bomberman/Mapa/Texturas/rompible.png"
#define Imag_NoBorr "../Bomberman/Mapa/Texturas/NoRompible.png"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void LecturaMapa();
    void GeneradorPuerta();

public slots:
    void colisionador();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    vector <QGraphicsRectItem *> muro;
    list <Bricks *> ladrillos;
    list <Enemigo *> enemigos;
    array <QGraphicsRectItem *,4> ExpBoom;
    vector <int> partMap;

    QGraphicsEllipseItem *personaje;
    QGraphicsRectItem *bomba;
    QGraphicsRectItem *puerta;

    bool bom=true;
    char tecla;
    int longi=0,cont=0;
    int PosX=0,PosY=0;
    int PosicionBomX,PosicionBomY;

    int MovONo=1;



protected:
    void keyPressEvent(QKeyEvent *e);
};
#endif // MAINWINDOW_H
