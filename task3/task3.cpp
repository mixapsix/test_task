#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
    //variables
    ifstream cash1, cash2, cash3, cash4, cash5;
    float buffer;
    float max = 0; //max people
    float people;
    int interval = 1;
    int maxInterval = 1;
    if(argv[1] != NULL) //protect from error
    {
        //Create string for the path
        string command = argv[1];
        string filename = "\\Cash";
        string folder = command + filename;
        //Open streams
        cash1.open(folder + "1.txt");
        cash2.open(folder + "2.txt");
        cash3.open(folder + "3.txt");
        cash4.open(folder + "4.txt");
        cash5.open(folder + "5.txt");

       while(!cash1.eof())
        {
            people = 0;
            //Collecting people in the queue
            cash1 >> buffer;
            people = buffer;
            cash2 >> buffer;
            people += buffer;
            cash3 >> buffer;
            people += buffer;
            cash4 >> buffer;
            people += buffer;
            cash5 >> buffer;
            people += buffer;
            //earn max from all day
            if(people > max)
            {
                max = people;
                maxInterval = interval;
            }
            interval++;
        }
    cout << maxInterval << "\n";
    }
    else
    {
       cout << "Input arguments in command line\n";
    }
}
