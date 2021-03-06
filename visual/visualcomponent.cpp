#include <QPainter>
#include <iostream>
#include "visualcomponent.h"

VisualComponent::VisualComponent(QWidget *parent) : QWidget(parent),
    buffer(new QPixmap(size()))
{
}

VisualComponent::VisualComponent(const VisualComponent &other): QWidget(other.parentWidget()),
    buffer(new QPixmap(*other.buffer))
{
}

VisualComponent::~VisualComponent()
{
    delete buffer;
}

void VisualComponent::draw()
{
    buffer->fill(Qt::black);
}

void VisualComponent::show()
{
    draw();
    QWidget::show();
}

void VisualComponent::drawBuffer()
{
    QPainter p(this);

    p.drawPixmap(0, 0, *buffer);

    p.end();
}

void VisualComponent::paintEvent(QPaintEvent *pe)
{
    QWidget::paintEvent(pe);

    draw();
    drawBuffer();
}

void VisualComponent::resizeEvent(QResizeEvent *re)
{
    QWidget::resizeEvent(re);

    delete buffer;
    buffer = new QPixmap(size());

    repaint();
}
