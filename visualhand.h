#ifndef VISUALHAND_H
#define VISUALHAND_H

#include <QVector>
#include <memory>
#include <QLayout>
#include "visualcard.h"

class VisualHand : public VisualComponent
{
public:
    explicit VisualHand(QWidget *parent = nullptr);
    explicit VisualHand(const VisualHand &other);
    virtual ~VisualHand() = default;

    void insertCard(const std::shared_ptr<VisualCard> &card, int id); // If id >= current hand size -> push back
    void removeCard(int id) throw(std::out_of_range); // Prefer to use size_t for ids, but Qt is kinda against that

    void draw() override;

private:
    QVector<std::shared_ptr<VisualCard>> cards;
    QHBoxLayout *horizontalLayout;
};

#endif // VISUALHAND_H
