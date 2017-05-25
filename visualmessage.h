#ifndef VISUALMESSAGE_H
#define VISUALMESSAGE_H

#include "visualcomponent.h"

class VisualMessage : public VisualComponent
{
public:
    explicit VisualMessage(QWidget *parent = nullptr, QString _text = "", QColor _bgColor = Qt::gray, QColor _textColor = Qt::red);
    explicit VisualMessage(const VisualMessage &other);
    ~VisualMessage() = default;

    void draw() override;

private:
    QString text;
    QColor bgColor;
    QColor textColor;

};

#endif // VISUALMESSAGE_H
