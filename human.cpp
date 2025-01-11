#include "human.h"

Human::Human(QString first_name, QString second_name, QString third_name, QString address, QString date_of_birth, QString email,
             QVector<QString> number){
    this->first_name = first_name;
    this->second_name = second_name;
    this->third_name = third_name;
    this->address = address;
    this->date_of_birth = date_of_birth;
    this->email = email;
    this->number = number;
}

void Human::Print(){
    qDebug() << second_name << "\t" << first_name << "\t" << third_name
           << "\t" << address << "\t" << date_of_birth << "\t" << email << "\t";
    for(int i = 0; i < number.size(); i++){
        qDebug() << i+1 << ") " << number[i] << "\t";
    }
    qDebug() << "\n";
}


void Human::write(QTextStream &fout){
    fout << first_name << " ";
    fout << second_name << " ";
    fout << third_name << " ";
    fout << address << " ";
    fout << date_of_birth << " ";
    fout << email << " ";
    size_t l = number.size();
    fout << l << " ";
    for(int i = 0; i < number.size(); i++){
        fout << number[i] << " ";
    }
}

void Human::read(QTextStream &fin){
    fin >> first_name;
    fin >> second_name;
    fin >> third_name;
    fin >> address;
    fin >> date_of_birth;
    fin >> email;
    size_t l;
    fin >> l;
    for(int i = 0; i < l; i++){
        QString tmp;
        fin >> tmp;
        number.push_back(tmp);
    }
}

