#ifndef DODAJ_H
#define DODAJ_H

#include <QDialog>
#include <QTextEdit>

namespace Ui {
class dodaj;
}

class dodaj : public QDialog
{
    Q_OBJECT

signals:
    void dodajKlienta(QString nazwa, QString adres, int wartosc, double rabat);

public:
    explicit dodaj(QWidget *parent = nullptr);
    ~dodaj();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::dodaj *ui;
};

#endif // DODAJ_H
