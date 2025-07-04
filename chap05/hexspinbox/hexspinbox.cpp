#include <QtCore>
#include <QDialog>
#include <QtGui>
#include <QtNetwork>
#include <QtQml>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QtWidgets>
#include "hexspinbox.h"

HexSpinBox::HexSpinBox(QWidget *parent)
    : QSpinBox(parent)
{
    setRange(0, 255);
    QRegularExpression reg_exp{"[0-9A-Fa-f]{1,8}"}; // validator = new QRegExpValidator(QRegExp("[0-9A-Fa-f]{1,8}"), this);
    validator = new QRegularExpressionValidator( reg_exp, this ); // validator = new QRegExpValidator(QRegExp("[0-9A-Fa-f]{1,8}"), this);
}

QValidator::State HexSpinBox::validate(QString &text, int &pos) const
{
    return validator->validate(text, pos);
}

int HexSpinBox::valueFromText(const QString &text) const
{
    bool ok;
    return text.toInt(&ok, 16);
}

QString HexSpinBox::textFromValue(int value) const
{
    return QString::number(value, 16).toUpper();
}
