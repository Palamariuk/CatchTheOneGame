#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTimer>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTableWidget *table;

private slots:
    void setBgColorField(QTableWidget *table);
    void setRandomCell(QTableWidget *table);
    void on_tableWidget_cellClicked(int row, int column);
    void startGame();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void updateLevel();
    void updateTimer();
    void minusLife();
    void gameOver();
};
#endif // MAINWINDOW_H
