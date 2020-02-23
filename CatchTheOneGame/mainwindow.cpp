#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "time.h"
#include "cmath"


int level = 1;
int lifes = 10;
int score = 10;
int interval = (int)(10000*pow(0.9,level-1));
QTimer *timer;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(minusLife()));

    setBgColorField(ui->tableWidget);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setBgColorField(QTableWidget *table){
    for(int i = 0; i < table->rowCount(); i++)
        for(int j = 0; j < table->columnCount(); j++){
            QTableWidgetItem *itm = new QTableWidgetItem();
            itm->setData(0,QVariant(0));
            itm->setForeground(QBrush(QColor(255,200,0)));
            itm->setBackground(QBrush(QColor(255,200,0)));
            ui->tableWidget->setItem(i,j,itm);
        }
}

void MainWindow::setRandomCell(QTableWidget *table)
{
    setBgColorField(table);
    srand(time(NULL));
    int i = random()%20;
    int j = random()%20;
    QTableWidgetItem *itm = new QTableWidgetItem();
    itm->setData(0,QVariant(1));
    itm->setForeground(QBrush(QColor(100,200,50)));
    itm->setBackground(QBrush(QColor(100,200,50)));
    table->setItem(i,j,itm);

}


void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    if(ui->tableWidget->item(row,column)->text() != "1"){
        lifes = lifes==0?lifes:lifes-1;
        ui->label_3->setNum(lifes);
        if(lifes==0) gameOver();
        updateTimer();
    } else{
        score--;
        if(score == 0) {
            level++;
            if(level==11) QMessageBox::information(this, "You winner!", "Congratulation!");
            updateLevel();
            score=10;
        }
        updateTimer();
        setRandomCell(ui->tableWidget);
    }
}

void MainWindow::startGame()
{
     ui->label_3->setNum(lifes);
     updateLevel();
     updateTimer();
     setRandomCell(ui->tableWidget);
}

void MainWindow::on_pushButton_2_clicked()
{
    close();
}

void MainWindow::on_pushButton_clicked()
{
    startGame();
}

void MainWindow::updateLevel()
{
    ui->spinBox->setValue(level);
}

void MainWindow::updateTimer()
{
    interval = (int)(10000*pow(0.9,level-1));
    timer->start(interval);

}

void MainWindow::minusLife()
{
    lifes--;
    ui->label_3->setNum(lifes);
    if(lifes==0) gameOver();
    updateTimer();
}

void MainWindow::gameOver()
{
    QMessageBox::information(this, "GAMEOVER", "This is game over!");
}
