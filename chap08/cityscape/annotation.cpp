#include <cmath>
#include <QtCore>
#include <QDialog>
#include <QtGui>
#include <QtNetwork>
#include <QtQml>
#include <QtWidgets>
#include "annotation.h"

Annotation::Annotation(const QString &text, bool major)
{
    font = qApp->font();
    font.setBold(true);
    if (major) {
        font.setPointSize(font.pointSize() + 2);
        font.setStretch(QFont::SemiExpanded);
    }

    if (major) {
        threshold = 0.01 * (40 + (std::rand() % 40));
    } else {
        threshold = 0.01 * (100 + (std::rand() % 100));
    }

    str = text;
    this->major = major;
    y = 20 - (std::rand() % 40);

    setZValue(1000);
    setFlag(ItemIgnoresTransformations, true);
}

void Annotation::setText(const QString &text)
{
    prepareGeometryChange();
    str = text;
    update();
}

QString Annotation::text() const
{
    return str;
}

QRectF Annotation::boundingRect() const
{
    QFontMetricsF metrics(font);
    QRectF rect = metrics.boundingRect(str);
    rect.moveCenter(QPointF(0, y));
    rect.adjust(-4, 0, +4, 0);
    return rect;
}

void Annotation::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget * /* widget */) { // reorg and delta code. grostig
    painter->setFont(font);
    QRectF rect = boundingRect();

    // for some reason AI thinks we don't need option variable??

    // grostig change from commented block below
    qreal levelOfDetail{painter->transform().m11()};
    //threshold = ADJUSTED_VALUE for m11();  // todo??: needed, AI suggests it is.
    if (levelOfDetail <= threshold){
       // low detail level of rendering?   // todo??: needed, AI suggests it is.
    }
    else {
       int alpha = int(30 * std::log(levelOfDetail));
       if (alpha >= 32) painter->fillRect(rect, QColor(255, 255, 255, qMin(alpha, 63)));
    }

    /* if (option->levelOfDetail <= threshold)
        return;
    int alpha = int(30 * std::log(option->levelOfDetail));
    if (alpha >= 32)
        painter->fillRect(rect, QColor(255, 255, 255, qMin(alpha, 63))); */

    painter->setPen(Qt::white);
    painter->drawText(rect.translated(+1, +1), str, QTextOption(Qt::AlignCenter));
    painter->setPen(Qt::blue);
    painter->drawText(rect, str, QTextOption(Qt::AlignCenter));
}
