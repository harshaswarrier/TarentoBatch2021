/*
1. Write a program to generate unique random numbers between two given numbers without using math.random().
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int u, l;
    std::cin>>l>>u;
    //interchange if lower limit is bigger
    if(l>u){
        int temp=l;
        l=u;
        u=temp;
    }
    if (l==u || u-l==1){
        std::cout<<l;//check if both limits are same or consecutive
        return 0;//returns lower limit & exits
    }
    time_t t=time(0);//system time which changes frequently
    int ru = t%u;//modulus functions to bring within limits
    int rl = t%l;
    int rdm = ru;
    //if not within limits
    while(!(rdm<u && rdm>l)){
        if(rdm>u)
            rdm=rdm/2;
        if(rdm<l)
            rdm=rdm*3;
        //2&3 taken to change the numbers
    }
    //output
    std::cout<<rdm;
    return 0;
}
