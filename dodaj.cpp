#include "dodaj.h"
#include "ui_dodaj.h"

dodaj::dodaj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dodaj)
{
    ui->setupUi(this);
}

dodaj::~dodaj()
{
    delete ui;
}

void dodaj::on_buttonBox_accepted()
{
    // Pobieranie danych z pól wprowadzania
    QString nazwa = ui->nazwaEdit->toPlainText();
    QString adres = ui->adresEdit->toPlainText();
    int wartosc = ui->wartoscBox->value();
    double rabat = ui->rabatBox->value();

    // Emitowanie sygnału
    emit dodajKlienta(nazwa, adres, wartosc, rabat);
    close();
}

