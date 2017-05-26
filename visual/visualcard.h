#ifndef VISUALCARD_H
#define VISUALCARD_H

#include "visualcomponent.h"
#include "../logic/card.h"
#include "visualcardinfo.h"
#include "visual_cards_state/visualcardstate.h"

class VisualCard : public VisualComponent
{
public:
    explicit VisualCard(QWidget *parent = nullptr, const std::shared_ptr<Card> &_card = std::shared_ptr<Card>(nullptr),
             QString _description = "Default descr", QString textureFile = nullptr);
    explicit VisualCard(const VisualCard &other);
    ~VisualCard();

    void draw();

private:
    vcInfo *info;
    VisualCardState *curState;


protected:
    void resizeEvent(QResizeEvent *re) override;
};

#endif // VISUALCARD_H
