#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char* argv[])
{
    //variables
    ifstream figureIn, pointsIn;
    float minX,minY,maxX,maxY;
    float square[4][2];
    float buff;
    float buffX, buffY;
    //open stream for figure coordinates
    figureIn.open(argv[1]);
    if(!figureIn.is_open()) //open stream for figure coordinates
    {
        cout << "Cant open file with figure coordinates\n";
    }
    else
    {
        pointsIn.open(argv[2]); //open stream for coordinates
        if(!pointsIn.is_open()) //protect from errors
        {
            cout << "Cant open file with points coordinates\n";
        }
        else
        {
            //record all vertices of the figure
            for(int x = 0; x < 4; x++)
            {
                for(int y = 0; y < 2; y++)
                {
                    figureIn >> buff;
                    square[x][y] = buff;
                }
            }
            figureIn.close();
            //first initialization
            maxX = minX = square[0][0];
            maxY = minY = square[0][1];
            //find min and max
            for(int x = 0; x < 4; x++)
            {
                if(square[x][0] > maxX)
                {
                    maxX = square[x][0];
                }
                if(square[x][0] < minX)
                {
                    minX = square[x][0];
                }
                if(square[x][1] > maxY)
                {
                    maxY = square[x][1];
                }
                if(square[x][1] < minY)
                {
                    minY = square[x][1];
                }
            }
            //Calculating result
            while(!pointsIn.eof())
            {
                pointsIn >> buffX;
                pointsIn >> buffY;
                if((buffX > maxX || buffY > maxY) || (buffX < minX || buffY < minY))
                {
                    cout << 3 << "\n";
                }
                else if((buffX == maxX && buffY == maxY) || (buffX == minX && buffY == minY))
                {
                    cout << 0 << "\n";
                }
                else if(buffX < maxX && buffX > minX && buffY < maxY && buffY > minY)
                {
                    cout << 2 << "\n";
                }
                else if((buffX == maxX || buffX == minX) && (buffY < maxY && buffY > minY))
                {
                    cout << 1 << "\n";
                }
                else if((buffY == maxY || buffY == minY) && (buffX < maxX && buffX > minX))
                {
                    cout << 1 << "\n";
                }
            }
            pointsIn.close();
        }
    }
}
