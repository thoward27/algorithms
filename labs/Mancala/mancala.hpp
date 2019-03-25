#ifndef __MANCALA_SOLVER_H__
#define __MANCALA_SOLVER_H__

#ifndef NULL
#define NULL 0x00
#endif

class Pit {

private:
    Pit* next;
    int index;
    int num_pieces;

public:
    Pit(int idx, int pieces);
    ~Pit();

    friend class MancalaSolver;

};

class MancalaSolver {

private:
    Pit* head;
    Pit* curr;
    unsigned int n_elem;

public:
    MancalaSolver();
    ~MancalaSolver();

    int removeByIndex(unsigned int idx);

    void append(int idx, int num_pieces);

    int solve(int idx);

    unsigned int getSize();
    void print();
};
#endif
