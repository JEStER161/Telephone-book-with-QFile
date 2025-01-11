#ifndef TELEPHONE_BOOK_H
#define TELEPHONE_BOOK_H

#include <QDialog>
#include "mainwindow.h"
#include "search.h"
namespace Ui {
class Telephone_book;
}

class Telephone_book : public QDialog
{
    Q_OBJECT

public:
    explicit Telephone_book(QWidget *parent = nullptr);
    ~Telephone_book();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

    void on_pushButton_5_clicked();
public slots:
    void slot_for_update_table();

private:
    Ui::Telephone_book *ui;
    MainWindow* insert_contact = new MainWindow;
    Search* search_window;

    int row;
    QString second_name_for_erase;

};
void update_table(Ui::Telephone_book* ui, std::map<QString, Human>& book);
#endif // TELEPHONE_BOOK_H
