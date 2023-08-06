//
//  History.cpp
//  32 Project 1
//
//  Created by Ayan Nath on 1/12/23.
//

#include <iostream>
#include "History.h"
#include "globals.h"

History::History(int nRows, int nCols)
{
    m_rows=nRows;
    m_cols=nCols;
    
    for (int r = 0; r <= m_rows;r++)
    {
        for (int c = 0; c <= m_cols; c++)
            mArena[r][c]= '.';
    }
}

bool History::record(int r, int c)
{
    
    if (r > m_rows || c > m_cols || r < 1 || r < 1)
    {
        return false;
    }
    
// if . change to A
// if Z do nothing
//if anything else increment by one
    if (mArena[r-1][c-1]=='.')
    {
        mArena[r-1][c-1]='A';
    }
    
    else if (mArena[r-1][c-1]=='Z')
    {
        //do nothing
    }
    
    else mArena[r-1][c-1]++;
    
    return true;
}

void History::display() const
{
    clearScreen();
    
    for (int r = 1; r <= m_rows; r++)
    {
        for (int c = 1; c <= m_cols; c++)
            std::cout<<mArena[r-1][c-1];
        
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


