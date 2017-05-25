#ifndef VISUALSCENEBUILDER_H
#define VISUALSCENEBUILDER_H

#include "visualcard.h"
#include "visualrow.h"
#include "visualnullrow.h"
#include "visualmessage.h"
#include "visualhand.h"

class VisualSceneBuilder
{
public:
    VisualSceneBuilder() = default;
    virtual ~VisualSceneBuilder() = default;

    virtual VisualRow *buildRow(QWidget *parent = nullptr);
    virtual VisualMessage *buildMessage(QWidget *parent = nullptr, QString text = "",
                                        QColor bgColor = Qt::gray, QColor textColor = Qt::red);
    virtual VisualNullRow *buildNullRow(QWidget *parent = nullptr);
    virtual VisualCard *buildVisualCard(QWidget *parent = 0, const std::shared_ptr<Card> &card = std::shared_ptr<Card>(nullptr),
                                        QString description = "Default descr", QString textureFile = nullptr);
    virtual VisualHand *buildVisualHand(QWidget *parent = nullptr);
    // TODO: VisualHand, MainCard, etc...


};

#endif // VISUALSCENEBUILDER_H
