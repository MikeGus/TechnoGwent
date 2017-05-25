#ifndef VISUALROW_H
#define VISUALROW_H

#include "visualcomponent.h"
#include "row.h"

class VisualRow : public VisualComponent
{
public:
    explicit VisualRow(QWidget *parent = 0, enum Row row = Row::melee);
    explicit VisualRow(const VisualRow &other);
    ~VisualRow() = default;

    void draw() override;
    Row getRow();

private:
    Row rowType;

};

#endif // VISUALROW_H
