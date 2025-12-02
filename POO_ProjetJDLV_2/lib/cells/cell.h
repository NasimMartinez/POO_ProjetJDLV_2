#pragma once
// Classe abstraite de cellule
class Cell {
public:
    virtual ~Cell() = default;

    virtual bool isAlive() const = 0;
    virtual Cell* clone() const = 0;
};

//Types de cellules
class LivingCell : public Cell {
public:
    bool isAlive() const override { return true; };
    Cell* clone() const override { return new LivingCell(*this); };
};


class DeadCell : public Cell {
public:
    bool isAlive() const override { return false; };
    Cell* clone() const override { return new DeadCell(*this); };
};