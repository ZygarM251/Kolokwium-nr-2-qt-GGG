#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/student/Desktop/kolt0b-MateuszGuzy02-1/logo.png");
    ui->logo->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dodajKlienta(QString nazwa, QString adres, int wartosc, double rabat)
{
    // Dodanie nowego klienta do listy
    listaKlientow.append(klient(nazwa, adres, wartosc, rabat));

    // Sortowanie listy zawodników względem punktów
    std::sort(listaKlientow.begin(), listaKlientow.end(),
              [](const klient& k1, const klient& k2)
              { return k1.getWartoscZRabatem() > k2.getWartoscZRabatem(); });

    ui->listaKlientow->clear();

    for(const klient& kl : listaKlientow)
    {
        ui->listaKlientow->append(QString("<b>Adres:</b> %1 <b>Nazwa:</b> %2 <b>Wartość:</b> %3")
                                      .arg(kl.getAdres())
                                      .arg(kl.getNazwa())
                                      .arg(kl.getWartoscZRabatem()));
    }
}

void MainWindow::suma()
{
    if(listaKlientow.isEmpty())
    {
        ui->sumaEdit->setText("Brak danych.");
        return;
    }

    ui->sumaEdit->clear();

    double suma = 0.0;

    for(int i = 0; i < listaKlientow.size(); i++)
    {
        const klient& kl = listaKlientow.at(i);

        suma +=kl.getWartoscZRabatem();
    }

    ui->sumaEdit->append(QString("<b>Suma wartości wszystkich zamówień wynosi:</b> %1")
                             .arg(suma));
}


void MainWindow::on_dodajButton_clicked()
{
    dodaj* dodajOkno = new dodaj(this);
    dodajOkno->show();

    // Połącz sygnał z okna dodawania z funkcją obsługującą dodawanie klienta
    connect(dodajOkno, SIGNAL(dodajKlienta(QString, QString, int, double)), this, SLOT(dodajKlienta(QString, QString, int, double)));
}


void MainWindow::on_sumaButton_clicked()
{
    suma();
}

