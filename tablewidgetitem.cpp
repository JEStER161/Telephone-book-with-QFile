#include "tablewidgetitem.h"

TableWidgetItem::TableWidgetItem(const QString &text, int type) :
    QTableWidgetItem(text,type)
{
}

bool TableWidgetItem::operator < (const QTableWidgetItem&  other) const
{
    if(other.column() == 4){
        return(QDate::fromString(other.data( Qt::DisplayRole ).toString(), "dd.MM.yyyy") > QDate::fromString(data(Qt::DisplayRole ).toString(), "dd.MM.yyyy"));
    }
    else{
        return(other.data( Qt::DisplayRole ).toString() > data(Qt::DisplayRole ).toString());
    }
}
