#include <iostream>

#define N 50
#define M 5

using namespace std;

int main()
{
    int man[N] = {0};
    int dead[N] = {0};
    int count = 0;
    int i = 0,pos = -1;

    while(count < N)
    {
        do{
            pos = (pos+1)%N;
            if(dead[pos] == 0)
                i++;
            if(i == M)
            {
                man[count] = pos+1; //第count个死的人是再pos+1位置（为了转换为以1开始数才加一)的人！
                dead[pos] = 1;
                i = 0;
                break;
            }
        }while(true);
        count++;
    }

    for(int i = 0;i<N;i++)
    {
        cout<<"the "<<i+1<<"th dead is "<<man[i]<<endl;
    }

    return 0;
}
