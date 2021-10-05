#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(0,0,ui->graphicsView->width()-5,ui->graphicsView->height()-5);
    ui->graphicsView->setScene(scene);


    QPen pen;
    QImage imaMuros(Imag_NoBorr),imaLadrillos(Imag_Borr);
    QBrush brush1(imaMuros),brush2(imaLadrillos);

    //personaje
    personaje = scene->addEllipse(55,55,30,30);

    scene->setFocusItem(personaje);

    LecturaMapa();
    int posicion =0;
    for (int i = 0;i< cont ; i ++) {
        for ( int j = 0;j < longi ; j++){

            if (partMap[j+posicion] == 1){
                muro.push_back(scene->addRect(j*50,i*50,50,50, pen,brush1));
            }
            else if(partMap[j+posicion] == 2){
                ladrillo.push_back(scene->addRect(j*50,i*50,50,50,pen,brush2));
            }
        }
        posicion+=longi;
    }


    //colisionador();



    QTimer *timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()),this, SLOT(colisionador()));
    timer->start(40);



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

void MainWindow::colisionador()
{
    static int timer = 0;
    personaje->setPos(PosX,PosY);
    if (!scene->collidingItems(personaje).isEmpty()){
        MovONo=0;
        for (auto parMuro : muro){
            if( personaje->collidesWithItem(parMuro)){
                if(tecla== 'A'){
                    PosX+=1;
                }
                else if(tecla=='W'){
                    PosY+=1;
                }
                else if(tecla=='D'){
                    PosX-=1;
                }
                else if(tecla=='S'){
                    PosY-=1;
                }
            }
        }
        for(auto parLadrillo : ladrillo){
            if( personaje->collidesWithItem(parLadrillo)){
                if(tecla== 'A'){
                    PosX+=1;
                }
                else if(tecla=='W'){
                    PosY+=1;
                }
                else if(tecla=='D'){
                    PosX-=1;
                }
                else if(tecla=='S'){
                    PosY-=1;
                }
            }
        }
        if( bomba!= NULL){
            MovONo=1;
        }
    }

    else{
        MovONo=1;
    }

    if(bom == false){
        timer+=40;
        if(timer == (40*100) ){
            QGraphicsRectItem *bombaD=scene->addRect(PosicionBomX+50,PosicionBomY,50,50);
            QGraphicsRectItem *bombaW=scene->addRect(PosicionBomX,PosicionBomY-50,50,50);
            QGraphicsRectItem *bombaA=scene->addRect(PosicionBomX-50,PosicionBomY,50,50);
            QGraphicsRectItem *bombaS=scene->addRect(PosicionBomX,PosicionBomY+50,50,50);

            for(auto parLadrillo = ladrillo.begin(); parLadrillo != ladrillo.end();){
                if(bombaD->collidesWithItem(*parLadrillo)){
                    //qDebug()<<"hola";
                    delete *parLadrillo;

                    parLadrillo = ladrillo.erase(parLadrillo);
                    break;

                }
                else{
                    parLadrillo++;
                }


            //bomba=scene->addRect(PosicionBomX,PosicionBomY,50,50);
            //bomba=scene->addRect(PosicionBomX,PosicionBomY,50,50);
            //bomba=scene->addRect(PosicionBoamX,PosicionBomY,50,50);

               }

            delete bombaD;
            delete bombaA;
            delete bombaS;
            delete bombaW;

            delete bomba;
            bom=true;
            timer=0;
            bomba=NULL;

        }
    }
}


void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(MovONo){
        switch (e->key()){
        case Qt::Key_A:
            PosX-=10;
            personaje->setPos(PosX,PosY);
            tecla='A';
            break;

        case Qt::Key_W:
            PosY-=10;
            personaje->setPos(PosX,PosY);
            tecla='W';
            break;

        case Qt::Key_D:
            PosX+=10;
            personaje->setPos(PosX,PosY);
            tecla='D';
            break;

        case Qt::Key_S:
            PosY+=10;
            personaje->setPos(PosX,PosY);
            tecla='S';
            break;
        case Qt::Key_Space:
            tecla=' ';

            if(bom){
                PosicionBomX =((PosX/50)*50)+50;
                PosicionBomY =((PosY/50)*50)+50;

                bomba=scene->addRect(PosicionBomX,PosicionBomY,50,50);
                bom=false;
            }
            break;


        }
    }
    //ui->graphicsView->setSceneRect(PosX-100,PosY-100,700,700);
}

