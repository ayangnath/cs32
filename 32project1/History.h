//
//  History.h
//  32 Project 1
//
//  Created by Ayan Nath on 1/12/23.
//

#ifndef History_h
#define History_h

#include "globals.h"

class History
    {
      public:
        //constructor
        History(int nRows, int nCols);
        bool record(int r, int c);
        void display() const;
        
    private:
        int m_rows;
        int m_cols;
        char mArena[MAXROWS][MAXCOLS];
        
    };

#endif /* History_h */
