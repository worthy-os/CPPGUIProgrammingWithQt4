#include <QtGui>
#include <cmath>

#include "cityview.h"

CityView::CityView(QWidget *parent)
    : QGraphicsView(parent)
{
    setDragMode(ScrollHandDrag);
}

void CityView::wheelEvent(QWheelEvent *event)
{
    double numDegrees = -event->angleDelta().y() / 8.0;  // grostig
    double numSteps = numDegrees / 15.0;
    double factor = std::pow(1.125, numSteps);
    scale(factor, factor);
}
