#ifndef VISUALROW_H
#define VISUALROW_H

#include "visualcomponent.h"
#include "../core/row.h"

class VisualRow : public VisualComponent
{
public:
    explicit VisualRow(QWidget *parent = nullptr, enum Row row = Row::melee);
    explicit VisualRow(const VisualRow &other);
    ~VisualRow() = default;

    void draw() override;
    Row getRow();

private:
    Row rowType;

};

#endif // VISUALROW_H
