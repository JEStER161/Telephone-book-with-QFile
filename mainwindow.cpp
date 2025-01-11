#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

using namespace std;

bool Check_numbers(vector<QLineEdit*> line_edit_vector, QRegularExpression regular_for_number, QRegularExpression regular_for_number_2, QString number_1, QVector<QString>& numbers){
    if(regular_for_number.match(number_1).hasMatch() or regular_for_number_2.match(number_1).hasMatch()){
        numbers.push_back(number_1);
        for(int i = 0; i < line_edit_vector.size(); i++){
            if(regular_for_number.match(line_edit_vector[i]->text()).hasMatch() or regular_for_number_2.match(line_edit_vector[i]->text()).hasMatch()){
                numbers.push_back(line_edit_vector[i]->text());
            }
            else{
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Чтение данных из файла
    QFile file(path);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Ошибка открытия файла для чтения";
        file.open(QFile::WriteOnly | QFile::Text)
    }
    else{
        qDebug() << "Файл открыт для чтения";

        QTextStream fin(&file);
        if(!fin.atEnd()){
            size_t size;
            fin >> size;
            for(int i = 0; i < size; i++){
                Human human;
                human.read(fin);
                book.emplace(human.second_name, human);
            }
        }
        qDebug() << "Данные считаны";
    }
    file.flush();
    file.close();
}

MainWindow::~MainWindow()
{
    QFile file(path);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        qDebug() << "Ошибка открытия файла для записи ";
    }
    else{
        qDebug() << "Файл открыт для записи";

        //Запись данных в файл
        QTextStream fout(&file);
        size_t l = book.size();
        fout << l << " ";
        for(auto element : book){
            element.second.write(fout);
        }
         qDebug() << "Данные записаны";
    }
    file.flush();
    file.close();

    delete ui;
}
//Добавление контакта
void MainWindow::on_pushButton_clicked()
{
    QRegularExpression regular_for_name("(^[A-Za-z]{1}[-0-9A-z\\.]{0,}[0-9A-Za-z]{1}$)"); //для фио
    QRegularExpression regular_for_number("(^((8|\\+7)[\\- ]?)?(\\(?\\d{3}\\)?[\\- ]?)?[\\d\\- ]{7,10}$)");// для телефона
    QRegularExpression regular_for_number_2("(^$)");// для удаления телефона
    QRegularExpression regular_for_email("(^((([0-9A-Za-z]{1}[-0-9A-z\\.]{1,}[0-9A-Za-z]{1}))@([-A-Za-z]{1,}\\.){1,2}[-A-Za-z]{2,})$)");// для email

    QString first_name = ui->first_name->text();
    QString second_name = ui->second_name->text();
    QString third_name = ui->third_name->text();
    QString address = ui->address->text();
    QString date_of_birth = ui->dateEdit->date().toString("dd.MM.yyyy");
    QString email = ui->email->text();
    QString number_1 = ui->phone->text();

    if(regular_for_name.match(first_name).hasMatch()){
        if(regular_for_name.match(second_name).hasMatch()){
            if(regular_for_name.match(third_name).hasMatch()){
                if(ui->dateEdit->date() < current_date){
                    if(regular_for_email.match(email).hasMatch()){
                        if(Check_numbers(line_edit_vector, regular_for_number, regular_for_number_2, number_1, numbers)){
                            //Запись в map
                            Human tmp(first_name, second_name, third_name, address, date_of_birth, email, numbers);
                            book.emplace(second_name, tmp);

                            ui->statusbar->showMessage("Контакт зарегистрирован!");

                            //отчистка полей ввода
                            ui->first_name->clear();
                            ui->second_name->clear();
                            ui->third_name->clear();
                            ui->dateEdit->setDate(QDate::fromString("01.01.2000","dd.MM.yyyy"));
                            ui->address->clear();
                            ui->email->clear();
                            ui->phone->clear();
                            ui->lineEdit->clear();

                            for(int i = 0; i < line_edit_vector.size(); i++){
                                line_edit_vector[i]->clear();
                                delete line_edit_vector[i];
                                delete layout_vector[i];
                                delete label_vector[i];
                            }

                            line_edit_vector.clear();
                            layout_vector.clear();
                            label_vector.clear();
                            numbers.clear();
                        }
                        else{
                            ui->statusbar->showMessage("Телефон введен некорректно!");
                            numbers.clear();
                        }
                    }
                    else{
                        ui->statusbar->showMessage("email введен некорректно!");
                    }
                }
                else{
                    ui->statusbar->showMessage("Дата рождения не может быть больше сегодняшнего дня!");
                }
            }
            else{
                ui->statusbar->showMessage("Отчество введено некорректно!");
            }
        }
        else{
            ui->statusbar->showMessage("Фамилия введена некорректно!");
        }
    }
    else{
        ui->statusbar->showMessage("Имя введено некорректно!");
    }
    emit signal_for_update_table();
}



//Добавление дополнительного телефона
void MainWindow::on_insert_number_clicked()
{
    QHBoxLayout* new_layout = new QHBoxLayout;
    QLabel* label_1 = new QLabel("Телефон:");
    QLineEdit* new_line_edit = new QLineEdit;

    layout_vector.push_back(new_layout);
    label_vector.push_back(label_1);
    line_edit_vector.push_back(new_line_edit);

    new_layout->addWidget(label_1);
    new_layout->addWidget(new_line_edit);

    ui->verticalLayout->addLayout(new_layout);
}

//Вывод данных найденного пользователя на экран
void MainWindow::on_pushButton_2_clicked()
{
    second_name_for_update = ui->lineEdit->text();

    if(book.find(second_name_for_update) != book.end()){
        ui->first_name->setText(book[second_name_for_update].first_name);
        ui->second_name->setText(book[second_name_for_update].second_name);
        ui->third_name->setText(book[second_name_for_update].third_name);
        ui->address->setText(book[second_name_for_update].address);
        ui->dateEdit->setDate(QDate::fromString(book[second_name_for_update].date_of_birth,"dd.MM.yyyy"));
        ui->email->setText(book[second_name_for_update].email);
        ui->phone->setText(book[second_name_for_update].number[0]);

        for(int i = 1; i < book[second_name_for_update].number.size(); i++){

            QHBoxLayout* new_layout = new QHBoxLayout;
            QLabel* label_1 = new QLabel("Телефон:");
            QLineEdit* new_line_edit = new QLineEdit;

            layout_vector.push_back(new_layout);
            label_vector.push_back(label_1);
            line_edit_vector.push_back(new_line_edit);

            new_layout->addWidget(label_1);
            new_layout->addWidget(new_line_edit);
            new_line_edit->setText(book[second_name_for_update].number[i]);

            ui->verticalLayout->addLayout(new_layout);
        }

    }
    else{
        QMessageBox::warning(0, "Предупреждение", "Контакта с такой фамилией нет!");
        ui->lineEdit->clear();
    }
}

//Обновление данных пользователя
void MainWindow::on_pushButton_3_clicked()
{
    QRegularExpression regular_for_name("(^[A-Za-z]{1}[-0-9A-z\\.]{0,}[0-9A-Za-z]{1}$)"); //для фио
    QRegularExpression regular_for_number("(^((8|\\+7)[\\- ]?)?(\\(?\\d{3}\\)?[\\- ]?)?[\\d\\- ]{7,10}$)");// для телефона
    QRegularExpression regular_for_number_2("(^$)");// для телефона
    QRegularExpression regular_for_email("(^((([0-9A-Za-z]{1}[-0-9A-z\\.]{1,}[0-9A-Za-z]{1}))@([-A-Za-z]{1,}\\.){1,2}[-A-Za-z]{2,})$)");// для email

    QString first_name = ui->first_name->text();
    QString second_name = ui->second_name->text();
    QString third_name = ui->third_name->text();
    QString address = ui->address->text();
    QString date_of_birth = ui->dateEdit->date().toString("dd.MM.yyyy");
    QString email = ui->email->text();
    QString number_1 = ui->phone->text();

    if(regular_for_name.match(first_name).hasMatch()){
        if(regular_for_name.match(second_name).hasMatch()){
            if(regular_for_name.match(third_name).hasMatch()){
                if(ui->dateEdit->date() < current_date){
                    if(regular_for_email.match(email).hasMatch()){
                        if(Check_numbers(line_edit_vector, regular_for_number, regular_for_number_2, number_1, numbers)){

                            book[second_name_for_update].first_name = first_name;
                            book[second_name_for_update].second_name = second_name;
                            book[second_name_for_update].third_name = third_name;
                            book[second_name_for_update].address = address;
                            book[second_name_for_update].date_of_birth = date_of_birth;
                            book[second_name_for_update].email = email;
                            book[second_name_for_update].number = numbers;

                            if(second_name_for_update != ui->second_name->text()){
                                auto it = book.find(second_name_for_update);
                                book[ui->second_name->text()] = (*it).second;
                                book.erase(it);
                            }

                            ui->statusbar->showMessage("Информация о контакте обновлена!");
                            ui->first_name->clear();
                            ui->second_name->clear();
                            ui->third_name->clear();
                            ui->dateEdit->setDate(QDate::fromString("01.01.2000","dd.MM.yyyy"));
                            ui->address->clear();
                            ui->email->clear();
                            ui->phone->clear();
                            ui->lineEdit->clear();

                            for(int i = 0; i < line_edit_vector.size(); i++){
                                line_edit_vector[i]->clear();
                                delete line_edit_vector[i];
                                delete layout_vector[i];
                                delete label_vector[i];
                            }

                            line_edit_vector.clear();
                            layout_vector.clear();
                            label_vector.clear();
                            numbers.clear();
                        }
                        else{
                            ui->statusbar->showMessage("Телефон введен некорректно!");
                            numbers.clear();
                        }
                    }
                    else{
                        ui->statusbar->showMessage("email введен некорректно!");
                    }
                }
                else{
                    ui->statusbar->showMessage("Дата рождения не может быть больше сегодняшнего дня!");
                }
            }
            else{
                ui->statusbar->showMessage("Отчество введено некорректно!");
            }
        }
        else{
            ui->statusbar->showMessage("Фамилия введена некорректно!");
        }
    }
    else{
        ui->statusbar->showMessage("Имя введено некорректно!");
    }
    emit signal_for_update_table();
}

