#ifndef HUMAN_H
#define HUMAN_H
#include <QVector>
#include <QTextStream>
#include <QDebug>
using namespace std;

struct Human{
    QString first_name;
    QString second_name;
    QString third_name;
    QString address;
    QString date_of_birth;
    QString email;
    QVector<QString> number;

    Human(QString first_name = "", QString second_name = "", QString third_name = "", QString address = "", QString date_of_birth = "",
          QString email = "", QVector<QString> number = {});
    void Print();
    void write(QTextStream& fout);
    void read(QTextStream& fin);
};


#endif // HUMAN_H
