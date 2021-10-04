#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();

    QPen pen;
    QImage imaMuros(Imag_NoBorr),imaLadrillos(Imag_Borr);
    QBrush brush1(imaMuros),brush2(imaLadrillos);



    LecturaMapa();
    int posicion =0;
    for (int i = 0;i< cont ; i ++) {
        for ( int j = 0;j < longi ; j++){

            if (partMap[j+posicion] == 1){
                muro.push_back(scene->addRect(j*50,i*50,50,50, pen,brush1));
            }
            else if(partMap[j+posicion] == 2){
                scene->addRect(j*50,i*50,50,50,pen,brush2);
            }
        }
        posicion+=longi;
    }

    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LecturaMapa()
{
    string contenido;

    ifstream archi;

    archi.open("../Bomberman/Mapa/Mapa.txt");

    if (!archi.is_open())
    {
      cout << "Error abriendo el archivo" << endl;
      exit(1);
    }
    archi >> contenido;

    string linea;
    while(!archi.eof()){

        getline(archi,linea);
        if (linea ==""){
            linea=contenido;
        }

        int longitud =linea.length();
        for (int i =0;i < longitud;i++){
            if (linea[i]!=','){
                partMap.push_back(linea[i]-48);
                if (cont ==0){
                    longi++;
                }
            }
        }
        cont++;
    }
    archi.close();

}

