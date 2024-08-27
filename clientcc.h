#ifndef CLIENTCC_H
#define CLIENTCC_H


#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class CLIENTCC
{
    int a,b;

public:
    CLIENTCC();
    CLIENTCC(int,int);
    //getters
    int geta(){return a; }
    int getb(){return b; }

    //setters
    void seta(int a){this->a=a;}
    void setb(int b){this->b=b;}

    //fonctionalite de class revenue
    bool ajouter();
    QSqlQueryModel* afficher();

};

#endif // CLIENTCC_H
