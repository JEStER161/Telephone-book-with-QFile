#include "search.h"
#include "ui_search.h"
#include <QMessageBox>

Search::Search(std::map<QString, Human> book, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Search)
{
    this->book = book;
    ui->setupUi(this);
}


Search::~Search()
{
    delete ui;
}

//Вывод найденого контакта
void Search::on_pushButton_clicked()
{
    second_name_for_search = ui->lineEdit->text();

    if(book.find(second_name_for_search) != book.end()){
        QString ans = book[second_name_for_search].second_name + "\t" + book[second_name_for_search].first_name + "\t" +
                      book[second_name_for_search].third_name + "\n" + book[second_name_for_search].address + "\t" +
                      book[second_name_for_search].date_of_birth + "\t" + book[second_name_for_search].email + "\n";
        for(int i = 0; i < book[second_name_for_search].number.size(); i++){
            ans += book[second_name_for_search].number[i];
            ans += "\n";
        }

        ui->answer->setText(ans);
        ui->lineEdit->clear();
    }
    else{
        QMessageBox::warning(0, "Предупреждение", "Контакта с такой фамилией нет!");
    }
}

