#ifndef VISUALCARDINFO_H
#define VISUALCARDINFO_H

#include <QString>
#include <QPixmap>
#include <memory>

struct vcInfo
{
    std::shared_ptr<Card> card; // Card itself
    QString description; // It's description
    QPixmap *texture; // And it's texture map

    // constructor-destructor section
    vcInfo(const std::shared_ptr<Card> &_card, QString _description, QPixmap *_texture):
        card(_card), description(_description), texture(_texture){}
    ~vcInfo()
    {
        delete texture;
    }

    vcInfo(const vcInfo &other) = delete; // Prohibit copy-constructor
};

#endif // VISUALCARDINFO_H
