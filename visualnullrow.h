#ifndef VISUALNULLROW_H
#define VISUALNULLROW_H

#include "visualrow.h"

class VisualNullRow: public VisualRow
{
public:
    explicit VisualNullRow(QWidget *parent = 0);
    explicit VisualNullRow(const VisualNullRow &other) = delete;// TODO: maybe make a copy constructor for prototyping
    ~VisualNullRow() = default;

    void draw() override;
};

#endif // VISUALNULLROW_H
