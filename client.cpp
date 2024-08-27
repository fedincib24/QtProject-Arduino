#include "client.h"
#include "ui_client.h"
#include "qrcode.h"
#include "dialog.h"
#include "home.h"
#include "histo.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "clients.h"
#include <QMessageBox>
#include <QDate>
#include <QIntValidator>
#include <QRegExpValidator>
#include <QDebug>
#include<QWidget>
#include <QTextDocument>
#include <QTextEdit>
#include <fstream>
#include <QTextStream>
#include <QRadioButton>
#include <QFileDialog>
#include <QPixmap>
#include <QPainter>
#include <QtSvg/QSvgRenderer>
#include <QtSvg/QSvgGenerator>
#include <QDirModel>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QAbstractPrintDialog>
#include <QDirModel>
#include <QtPrintSupport/QPrintDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QErrorMessage>
#include <QFile>
#include <QDataStream>

client::client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
    ui->affichageClient->setModel(Etmp.afficher());
   // ui->affichageProduit_3->setModel(Etmp_h.afficherP());

     //combo();

     // Controle saisie
     ui->ajout_cin_4->setValidator(new QIntValidator(0,999999,this));

     QRegExp rx("[A-Z][a-z]{0,30}");
     ui->ajout_nom_4->setValidator(new QRegExpValidator(rx,this));
     ui->ajout_prenom_4->setValidator(new QRegExpValidator(rx,this));
     ui->ajout_adresse_4->setValidator(new QRegExpValidator(rx,this));

     QRegExp rxM("[a-z]{0,10}@[a-z]{0,10}.[a-z]{0,10}");
     ui->ajout_adresseMail_4->setValidator(new QRegExpValidator(rxM,this));


     //datetime

         QTimer *timer=new QTimer(this);
         connect(timer ,SIGNAL(timeout()),this,SLOT(showTime()));
         timer->start();


         QDateTime dateTime=QDateTime::currentDateTime();
         QString datetimetext=dateTime.toString();
         ui->DateTime_->setText(datetimetext);
     //fin

}

client::~client()
{
    delete ui;
}





void client::showTime()
{
  QTime time=QTime::currentTime ();
  QString time_text=time.toString("hh : mm :ss");
  ui->Digital_clock->setText(time_text);
}









/*
void client::on_modifierClient_4_clicked()
{
    int res=ui->cinClient_8->text().toInt();
    QString nom=ui->modifier_nom_4->text();
    QString prenom=ui->modifier_prenom_4->text();
    QString adresse=ui->modifier_adresse_4->text();
    QString adresse_mail=ui->modifier_adresseMail_4->text();
    QString date_naissance=ui->modifier_dateN_4->text();


    Clients c(res,nom, prenom, adresse, adresse_mail, date_naissance);

    bool test=c.modifier();

    if(test)
    {
        ui->affichageClient->setModel(Etmp.afficher());  //Actualiser

        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification effectuée! \n" "Click cancel to exit"),QMessageBox::Cancel);
       // histor.save2("SUPPRIMER","cin :"+ui->cinClient_8->text(),"nom :"+ui->modifier_nom_4->text(),"prenom :"+ui->modifier_prenom_4->text(),"adresse :"+ui->modifier_adresse_4->text(),"adresse mail :"+ui->modifier_adresseMail_4->text());

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Modification non effectuée! \n" "Click cancel to exit"),QMessageBox::Cancel);
    }

}*/

//Historique
/*
void client:: combo()
{
    QSqlQueryModel *m=new QSqlQueryModel();
              QSqlQuery *querry=new QSqlQuery();
              querry->prepare("SELECT cin FROM client");
              querry->exec();
              m->setQuery(*querry);
              ui->cin_client->setModel(m);
}

*/






//Metiers
/*
void client::on_rechercherClient_4_clicked()
{
    QString nom=ui->recherche_4->text();
    if(nom=="")
    {
        QMessageBox::information(nullptr,QObject::tr("Champ vide"),QObject::tr("Veuiller insérer un NOM!"),QMessageBox::Cancel);
        ui->affichageClient->setModel(Etmp.afficher());
    }
    else
    {
        ui->affichageClient->setModel(Etmp.rechercherNom(nom));
    }
}

*/

/* void client::on_tri_nom_clicked()
{
    ui->affichageClient->setModel(Etmp.triNom());
}
*/












void client::on_ajoutClient_4_clicked()
{
    int res=ui->ajout_cin_4->text().toInt();
    QString nom=ui->ajout_nom_4->text();
    QString prenom=ui->ajout_prenom_4->text();
    QString adresse=ui->ajout_adresse_4->text();
    QString adresse_mail=ui->ajout_adresseMail_4->text();
    QString date_naissance=ui->ajout_dateN_4->text();


    Clients c(res,nom, prenom, adresse, adresse_mail, date_naissance);

    bool test=c.ajouter();

    if(test)
    {
        ui->affichageClient->setModel(Etmp.afficher());  //Actualiser

        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué! \n" "Click cancel to exit"),QMessageBox::Cancel);
        histor.save("cin :"+ui->ajout_cin_4->text(),"nom :"+ui->ajout_nom_4->text(),"prenom :"+ui->ajout_prenom_4->text(),"adresse :"+ui->ajout_adresse_4->text(),"adresse mail :"+ui->ajout_adresseMail_4->text());

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout non effectué! \n" "Click cancel to exit"),QMessageBox::Cancel);
    }
}




void client::on_pushButton_clicked()
{
    int cin =ui->cinClient_8->text().toInt();
    bool test=Etmp.supprimer(cin);

    if(test)
    {
        ui->affichageClient->setModel(Etmp.afficher());  //Actualiser

        QMessageBox::information(nullptr,QObject::tr("OK"), QObject::tr("Suppression effectuée \n" "Click cancel to exit"), QMessageBox::Cancel);
        histor1.save1("SUPPRIMER","cin :"+ui->cinClient_8->text());

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"), QObject::tr("Suppression non effectuée \n" "Click cancel to exit"), QMessageBox::Cancel);
    }
}

void client::on_pushButton_3_clicked()
{
    int res=ui->cinClient_8->text().toInt();
    QString nom=ui->modifier_nom_4->text();
    QString prenom=ui->modifier_prenom_4->text();
    QString adresse=ui->modifier_adresse_4->text();
    QString adresse_mail=ui->modifier_adresseMail_4->text();
    QString date_naissance=ui->modifier_dateN_4->text();


    Clients c(res,nom, prenom, adresse, adresse_mail, date_naissance);

    bool test=c.modifier();

    if(test)
    {
        ui->affichageClient->setModel(Etmp.afficher());  //Actualiser

        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification effectuée! \n" "Click cancel to exit"),QMessageBox::Cancel);
        histor.save2("SUPPRIMER","cin :"+ui->cinClient_8->text(),"nom :"+ui->modifier_nom_4->text(),"prenom :"+ui->modifier_prenom_4->text(),"adresse :"+ui->modifier_adresse_4->text(),"adresse mail :"+ui->modifier_adresseMail_4->text());

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Modification non effectuée! \n" "Click cancel to exit"),QMessageBox::Cancel);
    }
}

QMediaPlayer *a;


void client::on_pushButton_home1_clicked()
{
    if(a)
    {
    a->stop();
    home *mainWindow = new home();
    hide();
      mainWindow->show();  }
    else
    {
     home *mainWindow = new home();
        hide();
           mainWindow->show();
    }
}

void client::on_pushButton_start_musique_clicked()
{
    a= new QMediaPlayer;
        a->setMedia(QUrl("C:/Users/ncib/Desktop/fedincib_tacheqt/musique.wav"));
           a->play();
           qDebug()<<a->errorString();
}

void client::on_pushButton_stop_musique_clicked()
{
    a->stop();
}

void client::on_slidervolume_sliderMoved(int position)
{
     a->setVolume(position);
}



void client::on_QRCode_clicked()
{
    if(ui->affichageClient->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                 QObject::tr("Veuillez Choisir un employé du Tableau.\n"
                                             "Click Ok to exit."), QMessageBox::Ok);
    else
    {
         int  Code=ui->affichageClient->model()->data(ui->affichageClient->model()->index(ui->affichageClient->currentIndex().row(),0)).toInt();
        //const QrCode qr = QrCode::encodeText(std::to_string(Code).c_str(), QrCode::Ecc::LOW);
         const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(std::to_string(Code).c_str(),qrcodegen::QrCode::Ecc::LOW);
         std::ofstream myfile;
         myfile.open ("qrcode.svg") ;
         myfile << qr.toSvgString(1);
         myfile.close();
         QSvgRenderer svgRenderer(QString("qrcode.svg"));
         QPixmap pix( QSize(90, 90) );
         QPainter pixPainter( &pix );
         svgRenderer.render(&pixPainter);
         ui->label_6->setPixmap(pix);
    }
}

void client::on_cherchercom_2_clicked()
{
    QString nom=ui->recherche_4->text();
    if(nom=="")
    {
        QMessageBox::information(nullptr,QObject::tr("Champ vide"),QObject::tr("Veuiller insérer un NOM!"),QMessageBox::Cancel);
        ui->affichageClient->setModel(Etmp.afficher());
    }
    else
    {
        ui->affichageClient->setModel(Etmp.rechercherNom(nom));
    }
}

void client::on_tri_nom_clicked()
{
     ui->affichageClient->setModel(Etmp.triNom());
}

void client::on_pfd_6_clicked()
{
    QPrinter printer;
    printer.setPrinterName("Printer Name");

    QPrintDialog pDialog(&printer, this);

    if(pDialog.exec() == QDialog::Rejected){
        QMessageBox::warning(this, "Warning", "Cannot Access Printer");
        return;
    }
    ui->affichageClient->render(&printer);

}

void client::on_pushButton_calcul_clicked()
{

}

void client::on_pushButton_blocnote_clicked()
{

}

void client::on_pushButton_2_clicked()
{
    Dialog w;
    w.exec();
}

void client::on_afficherHisto_clicked()
{
    QFile file("C:/Users/ncib/Desktop/fedincib_tacheqt/historique.txt");

        if (!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"info",file.errorString());
        QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());
}
