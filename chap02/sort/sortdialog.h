#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QtWidgets/qdialog.h>      // grostig
#include <QtWidgets/qboxlayout.h>   // grostig
#include <QtWidgets/qpushbutton.h>  // grostig
#include <QtWidgets/qslider.h>      // grostig
#include <QtWidgets/qspinbox.h>     // grostig
#include <QtWidgets/qtablewidget.h> // grostig
#include <QtWidgets/QApplication>
#include "ui_sortdialog.h"

class SortDialog : public QDialog, public Ui::SortDialog
{
    Q_OBJECT

public:
    SortDialog(QWidget *parent = 0);

    void setColumnRange(QChar first, QChar last);
};

#endif
