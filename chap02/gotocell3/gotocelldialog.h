#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QtWidgets/qdialog.h>      // grostig
#include <QtWidgets/qboxlayout.h>   // grostig
#include <QtWidgets/qslider.h>      // grostig
#include <QtWidgets/qspinbox.h>     // grostig
#include "ui_gotocelldialog.h"

class GoToCellDialog : public QDialog, public Ui::GoToCellDialog
{
    Q_OBJECT

public:
    GoToCellDialog(QWidget *parent = 0);

private slots:
    void on_lineEdit_textChanged();
};

#endif
