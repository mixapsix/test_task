#include<iostream>
#include<fstream>
#include<time.h>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream visitors;
    float buffer;
    float hour;
    float minuts;
    float vis[10][2];

    if(argv[1]!= NULL)
    {
        visitors.open(argv[1]);
        while(!visitors.eof())
        {
            for(int x = 0; x < 10; x++)
            {
                for(int y = 0; y < 2; y++)
                {

                    vis[x,y] = buffer;
                    visitors.ignore(1,':');
                    vis[x,y] >> buffer;
                    minuts = buffer;
                }
            }
            cout << hour << minuts <<" ";
        }
    }
    else
    {
        cout << "Enter arguments in command line\n";
    }
}
