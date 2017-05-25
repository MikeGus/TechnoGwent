#ifndef CARDPOOL_H
#define CARDPOOL_H

#include <QVector>
#include "card.h"

class CardPool
{
public:
    CardPool(size_t size = 36, int mixKey = 0);
    ~CardPool() = default;

    Card getCard();
    void returnDead(const Card &deadCard);

private:
    QVector<Card> available;
    QVector<Card> dead;

    void mixCards(int mixKey);
    void generate(size_t size);

};

#endif // CARDPOOL_H
