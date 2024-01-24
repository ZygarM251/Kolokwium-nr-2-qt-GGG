#include "klient.h"

klient::klient(QString naz, QString adr, int wart, double rab) : nazwa(naz), adres(adr), wartosc(wart), rabat(rab)
{
    obliczWartoscZRabatem();
}

void klient::obliczWartoscZRabatem()
{
    double wartoscBezRabatu = getWartosc();
    double rabatWartosc = wartoscBezRabatu * (getRabat() / 100.0);
    wartoscZRabatem = wartoscBezRabatu - rabatWartosc;
}
