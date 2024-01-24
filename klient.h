#ifndef KLIENT_H
#define KLIENT_H
#include <QString>


class klient
{

private:
    QString nazwa;
    QString adres;
    int wartosc;
    double rabat;
    double wartoscZRabatem;


public:
    klient(QString naz, QString adr, int wart, double rab);

    QString getNazwa() const { return nazwa; }
    QString getAdres() const { return adres; }
    int getWartosc() const { return wartosc; }
    double getRabat() const { return rabat; }
    double getWartoscZRabatem() const { return wartoscZRabatem; }

    void obliczWartoscZRabatem();
};

#endif // KLIENT_H
