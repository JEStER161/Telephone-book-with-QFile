/********************************************************************************
** Form generated from reading UI file 'telephone_book.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELEPHONE_BOOK_H
#define UI_TELEPHONE_BOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Telephone_book
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton;

    void setupUi(QDialog *Telephone_book)
    {
        if (Telephone_book->objectName().isEmpty())
            Telephone_book->setObjectName("Telephone_book");
        Telephone_book->resize(1120, 600);
        Telephone_book->setMinimumSize(QSize(1120, 600));
        verticalLayout = new QVBoxLayout(Telephone_book);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(Telephone_book);
        label->setObjectName("label");
        QFont font;
        font.setWeight(QFont::Black);
        font.setStrikeOut(false);
        font.setKerning(false);
        font.setHintingPreference(QFont::PreferNoHinting);
        label->setFont(font);

        verticalLayout->addWidget(label);

        tableWidget = new QTableWidget(Telephone_book);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_2 = new QPushButton(Telephone_book);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        pushButton_5 = new QPushButton(Telephone_book);
        pushButton_5->setObjectName("pushButton_5");

        horizontalLayout->addWidget(pushButton_5);

        pushButton = new QPushButton(Telephone_book);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Telephone_book);

        QMetaObject::connectSlotsByName(Telephone_book);
    } // setupUi

    void retranslateUi(QDialog *Telephone_book)
    {
        Telephone_book->setWindowTitle(QCoreApplication::translate("Telephone_book", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Telephone_book", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275\320\275\320\260\321\217 \320\272\320\275\320\270\320\263\320\260", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Telephone_book", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\276\320\275\321\202\320\260\320\272\321\202/\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Telephone_book", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        pushButton->setText(QCoreApplication::translate("Telephone_book", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\272\320\276\320\275\321\202\320\260\320\272\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Telephone_book: public Ui_Telephone_book {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELEPHONE_BOOK_H
