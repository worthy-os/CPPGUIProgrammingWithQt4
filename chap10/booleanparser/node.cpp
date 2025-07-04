#include <QtCore>
#include <QDialog>
#include <QtGui>
#include <QtNetwork>
#include <QtQml>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QSortFilterProxyModel>
#include <QtWidgets>

#include "booleanparser.h"

Node::Node(Type type, const QString &str)
{
    this->type = type;
    this->str = str;
    parent = 0;
}

Node::~Node()
{
    qDeleteAll(children);
}
