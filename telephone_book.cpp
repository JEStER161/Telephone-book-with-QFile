#include "telephone_book.h"
#include "ui_telephone_book.h"
#include <QMessageBox>
#include "tablewidgetitem.h"


void update_table(Ui::Telephone_book* ui, std::map<QString, Human>& book){
    ui->tableWidget->setRowCount(book.size());
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(70);
    for(int i = 0; i < 7; i++){
        if(i == 1 or i == 4){
            ui->tableWidget->setColumnWidth(i, 100);
        }
        else{
            ui->tableWidget->setColumnWidth(i, 170);
        }
    }

    int row = 0;
    for(auto it = book.cbegin(); it != book.cend(); it++, row++){

        QString temp_str_for_number;
        for(int i = 0; i < (*it).second.number.size(); i++){
            temp_str_for_number = temp_str_for_number + (*it).second.number[i] + "\n";
        }

        TableWidgetItem* item_1 = new TableWidgetItem((*it).second.second_name);
        item_1->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 0, item_1);

        TableWidgetItem* item_2 = new TableWidgetItem((*it).second.first_name);
        item_2->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 1, item_2);

        TableWidgetItem* item_3 = new TableWidgetItem((*it).second.third_name);
        item_3->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 2, item_3);

        TableWidgetItem* item_4 = new TableWidgetItem((*it).second.address);
        item_4->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 3, item_4);

        TableWidgetItem* item_5 = new TableWidgetItem((*it).second.date_of_birth);
        item_5->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 4, item_5);

        TableWidgetItem* item_6 = new TableWidgetItem((*it).second.email);
        item_6->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 5, item_6);

        TableWidgetItem* item_7 = new TableWidgetItem(temp_str_for_number);
        item_7->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 6, item_7);
    }
}
Telephone_book::Telephone_book(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Telephone_book)
{
    ui->setupUi(this);
    connect(insert_contact, &MainWindow::signal_for_update_table, this, &Telephone_book::slot_for_update_table);
    ui->tableWidget->setColumnCount(7);
    QStringList arr = { "Second name", "First name", "Third name", "Address", "Date of birth", "Email", "Phone number" };
    ui->tableWidget->setHorizontalHeaderLabels(arr);
    ui->tableWidget->setSortingEnabled(true);

    update_table(ui, insert_contact->book);
}

Telephone_book::~Telephone_book()
{
    delete insert_contact;
    delete ui;
}

//Открытие окна для добавления контакта
void Telephone_book::on_pushButton_2_clicked()
{
    insert_contact->show();
}


//Удаление контакта
void Telephone_book::on_pushButton_clicked()
{

    if(insert_contact->book.erase(second_name_for_erase) == 0){
        QMessageBox::warning(this, "Предупреждение", "Для удаления контакта выделите second_name данного контакта!");
    }
    else{
         ui->tableWidget->removeRow(row);
    }
}

//Сохранеиние выделенной ячейки
void Telephone_book::on_tableWidget_clicked(const QModelIndex &index)
{
    row = index.row();
    second_name_for_erase = index.data().toString();
}

//Открытие окна поиска
void Telephone_book::on_pushButton_5_clicked()
{
    search_window = new Search(insert_contact->book);
    search_window->show();
}

void Telephone_book::slot_for_update_table()
{
    update_table(ui, insert_contact->book);
}

