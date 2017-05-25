#ifndef VISUALSCENEBUILDER_H
#define VISUALSCENEBUILDER_H

#include "visualcard.h"
#include "visualrow.h"
#include "visualnullrow.h"
#include "visualmessage.h"

class VisualSceneBuilder
{
public:
    VisualSceneBuilder() = default;
    virtual ~VisualSceneBuilder() = default;

    virtual VisualRow *buildRow(QWidget *parent = nullptr);
    virtual VisualMessage *buildMessage(QWidget *parent = 0, QString _text = "", QColor _bgColor = Qt::gray, QColor _textColor = Qt::red);
    virtual VisualNullRow *buildNullRow(QWidget *parent = nullptr);
    // TODO: VisualHand, MainCard, etc...


};

#endif // VISUALSCENEBUILDER_H
