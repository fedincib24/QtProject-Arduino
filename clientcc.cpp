#include "clientcc.h"

#include <QSqlQuery>
#include<QtDebug>
#include <QObject>

CLIENTCC::CLIENTCC()
{
    a=0;
    b=0;


}
CLIENTCC::CLIENTCC(int a ,int b )
{
        this->a=a;
        this->b=b;

}

bool CLIENTCC::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENTCC (a,b) VALUES (:a,:b)");
    query.bindValue(":a",a);
    query.bindValue(":b",b);


    return query.exec();
}

QSqlQueryModel*  CLIENTCC::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM CLIENTCC");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("incorrect"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("correct"));


    return model;
}
