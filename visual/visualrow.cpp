#include <QPainter>
#include <iostream>
#include "visualrow.h"

VisualRow::VisualRow(QWidget *parent, Row _row): VisualComponent(parent), rowType(_row)
{
}

VisualRow::VisualRow(const VisualRow &other): VisualComponent(other)
{
}

void VisualRow::draw()
{
    QPainter p(buffer);
    p.setPen(Qt::yellow);

    p.drawRoundedRect(10, 10, width()-20, height()-20, 10, 10);

    p.end();
}

Row VisualRow::getRow()
{
    return rowType;
}

