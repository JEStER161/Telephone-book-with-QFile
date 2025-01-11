#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include "human.h"

namespace Ui {
class Search;
}

class Search : public QWidget
{
    Q_OBJECT

public:
    explicit Search(std::map<QString, Human> book, QWidget *parent = nullptr);
    ~Search();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Search *ui;

    std::map<QString, Human> book;

    QString second_name_for_search;
};

#endif // SEARCH_H
