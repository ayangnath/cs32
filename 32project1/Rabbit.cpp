//
//  Rabbit.cpp
//  32 Project 1
//
//  Created by Ayan Nath on 1/11/23.
//

#include <iostream>

#include "Rabbit.h"
#include "Arena.h"
#include "globals.h"


///////////////////////////////////////////////////////////////////////////
//  Rabbit implementation
///////////////////////////////////////////////////////////////////////////

class Arena;

Rabbit::Rabbit(Arena* ap, int r, int c)
{
    if (ap == nullptr)
    {
        std::cout << "***** A rabbit must be created in some Arena!" << std::endl;
        exit(1);
    }
    if (r < 1  ||  r > ap->rows()  ||  c < 1  ||  c > ap->cols())
    {
        std::cout << "***** Rabbit created with invalid coordinates (" << r << ","
             << c << ")!" << std::endl;
        exit(1);
    }
    m_arena = ap;
    m_row = r;
    m_col = c;
    m_health = INITIAL_RABBIT_HEALTH;
    m_idleTurnsRemaining = 0;
}

int Rabbit::row() const
{
    return m_row;
}

int Rabbit::col() const
{
    return m_col;
}

bool Rabbit::isDead() const
{
    return m_health == 0;
}

void Rabbit::move()
{
    if (m_idleTurnsRemaining > 0)
    {
        m_idleTurnsRemaining--;
        return;
    }

      // Attempt to move in a random direction; if can't move, we don't move
    if (attemptMove(*m_arena, randInt(0, NUMDIRS-1), m_row, m_col))
    {
        if (m_arena->getCellStatus(m_row, m_col) == HAS_POISON)
        {
            m_arena->setCellStatus(m_row, m_col, EMPTY);
            m_health--;
        }
    }

    if (m_health < INITIAL_RABBIT_HEALTH)
        m_idleTurnsRemaining = POISONED_IDLE_TIME;
}
