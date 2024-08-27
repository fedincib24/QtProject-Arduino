#ifndef CLIENT_H
#define CLIENT_H
#include"clients.h"
#include "histo.h"
#include <QDialog>
#include <QTimer>

namespace Ui {
class client;
}

class client : public QDialog
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();

    void on_ajouterClient_4_clicked();



   // void combo();

    void on_ajouterProduit_clicked();

    //void on_supprimerAchat_clicked();

    void on_modifierProduit_3_clicked();

    void on_rechercherClient_4_clicked();

    //void on_tri_nom_clicked();

   /* void on_QRCode_clicked();

    void sendMail();
    void mailSent(QString);
    void browse();*/

    /*void on_browse_clicked();

    void on_envoyer_clicked();



    void on_afficherHisto_clicked();

    void update_label();
*/
   // void on_pdf_6_clicked();
private slots:
    void on_ajoutClient_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_home1_clicked();

    void on_pushButton_start_musique_clicked();

    void on_pushButton_stop_musique_clicked();

    void on_slidervolume_sliderMoved(int position);

    // void on_pushButton_4_clicked();

    void on_QRCode_clicked();

    void on_cherchercom_2_clicked();

    void on_tri_nom_clicked();

    void on_pfd_6_clicked();

    void on_pushButton_calcul_clicked();

    void on_pushButton_blocnote_clicked();

    void on_pushButton_2_clicked();
void showTime();
    void on_afficherHisto_clicked();

private:
    Ui::client *ui;
    Clients Etmp;
QTimer *timer;
    histo histor;
    histo histor1;
    histo histor2;

    QStringList files;



};

#endif // CLIENT_H
