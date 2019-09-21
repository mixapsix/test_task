#include<iostream>
#include<fstream>
#include<iomanip>
#include<list>
#include<algorithm>
#include<math.h>

using namespace std;

int main(int argc, char* argv[])
{
    //variables
    list<short> allCounts;
    short buff, count;
    float min, max;
    float average, median, perc;
    bool first = true;
    short temp1, temp2;
    double whole, fract;
    min = max = 0;
    ifstream fin;
    fin.open(argv[1]);
    //protect from error
    if(!fin.is_open())
    {
        cout << "Can`t open file";
    }
    //count and populate the collection
    else
    {
        //first initialization
        fin >> buff;
        min = max = average = buff;
        allCounts.push_back(buff);
        //main loop
        while(!fin.eof())
        {
            fin >> buff;
            if(max < buff) //getting  max
            {
                max = buff;
            }
            else if(min > buff) //getting  min
            {
                min = buff;
            }
            allCounts.push_back(buff);//
            average+=buff;
        }
        //closing the stream and sorting
        fin.close();
        allCounts.sort();
        count = allCounts.size();
        //percentile
        list<short>::iterator num = allCounts.begin();
        fract = modf(((0.9 * (count-1))+1), &whole);
        advance(num,whole-1);
        temp1=*(num);
        advance(num,+1);
        temp2=*(num);
        perc = (temp1 + fract*(temp2-temp1));
        //median
        num = allCounts.begin();
        if((count%2)==0)
        {
            advance(num,(count/2-1));
            temp1=*(num);
            advance(num,+1);
            temp2=*(num);
            median = ((temp1+temp2)/2);
        }
        else
        {
            advance(num,(count/2));
            median = *(num);
        }
       allCounts.erase(allCounts.begin(), allCounts.end());
        //output
        printf("%.2f\n", perc);
        printf("%.2f\n", median);
        printf("%.2f\n", max);
        printf("%.2f\n", min);
        printf("%.2f\n",average/count);
    }
    return 0;
}
