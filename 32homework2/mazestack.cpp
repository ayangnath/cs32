//
//  mazestack.cpp
//  32homework2
//
//  Created by Ayan Nath on 2/4/23.
//
#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Coord
{
public:
    Coord(int r, int c) : m_row(r), m_col(c) {}
    int r() const { return m_row; }
    int c() const { return m_col; }
private:
    int m_row;
    int m_col;
};

// return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise
bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    stack<Coord> coordStack;

    coordStack.push(Coord(sr, sc));
    maze[sr][sc] = '#';

    while(!coordStack.empty())
    {
        Coord cur = coordStack.top();
        coordStack.pop();
        //cout << cur.r() << " " << cur.c() << endl;
        if (cur.r()==er && cur.c()==ec)
            return true;

        //for East
        if (cur.c() +1 < nCols && maze[cur.r()][cur.c()+1]=='.')
        {
            coordStack.push(Coord(cur.r(), cur.c()+1));
            maze[cur.r()][cur.c()+1]='#';
        }

        //for North
        if (cur.r() -1 >= 0 && maze[cur.r()-1][cur.c()]=='.')
        {
            coordStack.push(Coord(cur.r()-1, cur.c()));
            maze[cur.r()-1][cur.c()]='#';
        }

        //for west
        if (cur.c() -1 >= 0 && maze[cur.r()][cur.c()-1]=='.')
        {
            coordStack.push(Coord(cur.r(), cur.c()-1));
            maze[cur.r()][cur.c()-1]='#';
        }

        //for South
        if (cur.r() +1 < nRows && maze[cur.r()+1][cur.c()]=='.')
        {
            coordStack.push(Coord(cur.r()+1, cur.c()));
            maze[cur.r()+1][cur.c()]='#';
        }
    }

    return false;
}

int main()
        {
            string maze[10] = {
                "XXXXXXXXXX",
                "X..X...X.X",
                "X.XXXX.X.X",
                "X.X.X..X.X",
                "X...X.XX.X",
                "XXX......X",
                "X.X.XXXX.X",
                "X.XXX....X",
                "X...X..X.X",
                "XXXXXXXXXX"
            };
        
            if (pathExists(maze, 10,10, 5,3, 8,8))
                cout << "Solvable!" << endl;
            else
                cout << "Out of luck!" << endl;
        }
