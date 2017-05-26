#ifndef VISUALCARD_H
#define VISUALCARD_H

#include <memory>
#include "visualcomponent.h"
#include "../logic/card.h"

class VisualCard : public VisualComponent
{
public:
    explicit VisualCard(QWidget *parent = nullptr, const std::shared_ptr<Card> &_card = std::shared_ptr<Card>(nullptr),
             QString _description = "Default descr", QString textureFile = nullptr);
    explicit VisualCard(const VisualCard &other);
    ~VisualCard() = default;

    void draw();

private:
    std::shared_ptr<Card> card;
    QString description;
    QPixmap *texture;

protected:
    void resizeEvent(QResizeEvent *re) override;
};

#endif // VISUALCARD_H
