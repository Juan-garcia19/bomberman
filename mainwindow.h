#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <fstream>
#include <iostream>
#include <vector>

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

    vector <int> partMap;

    int longi=0,cont;
};
#endif // MAINWINDOW_H
