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


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    vector <QGraphicsRectItem *> muro;
    list <QGraphicsRectItem *> ladrillo;
    vector <int> partMap;

    QGraphicsEllipseItem *personaje;

    int longi=0,cont;


protected:
    void keyPressEvent(QKeyEvent *e);
};
#endif // MAINWINDOW_H
