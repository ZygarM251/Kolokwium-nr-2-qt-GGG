#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QPixmap>
#include "klient.h"
#include "dodaj.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_dodajButton_clicked();
    void dodajKlienta(QString nazwa, QString adres, int wartosc, double rabat);

    void suma();
    void on_sumaButton_clicked();

private:
    Ui::MainWindow *ui;
    QList<klient> listaKlientow;
};
#endif // MAINWINDOW_H
