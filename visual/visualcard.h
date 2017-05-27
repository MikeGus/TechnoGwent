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
             QString _description = "Default descr", QString textureFile = nullptr, bool bFaceUp = true);
    VisualCard(const VisualCard &other) = delete; // No copy-constructor allowed
    ~VisualCard();

    void setFaceUp(bool bUp = true);
    bool isFaceUp();

    void changeState(VisualCardState *newState);

    void draw();
    void drawBasic(); // Basic drawing stuff, implemented inside card

private:
    vcInfo *info;
    VisualCardState *curState;
    bool bFaceUp; // Is facing up or down


protected:
    void resizeEvent(QResizeEvent *re) override;
    // Mouse events are completely implemented in states
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
};

#endif // VISUALCARD_H
