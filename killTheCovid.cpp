#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "cluster.h"
using namespace std;

int main()
{
    Cluster cluster;
    int val;
    do
    {
        cout<<endl;
        cout<<"Select from 1-4"<<endl;
        cout<<"1. Find hexagon neighbours"<<endl;
        cout<<"2. Add a hexagon"<<endl;
        cout<<"3. Remove a hexagon"<<endl;
        cout<<"4. Exit"<<endl;

        cin>>val;
        if(val == 1)
        {
            cout<<"Enter the Hexagon Name"<<endl;
            string hexagon_name;
            cin>>hexagon_name;
            cluster.getNeighbour(hexagon_name);
        }
        else 
        if(val == 2)
        {
            cout<<"Enter Name of already present Hexagon, its borderNumberder and the name of new Hexagon"<<endl;
            string hex_present, hex_new;
            int borderNumber;
            cin>>hex_present>>borderNumber>>hex_new;
            cluster.addNewHexagon(hex_present, borderNumber, hex_new);
        }
        else 
        if(val == 3)
        {
            cout<<"Enter the hexagon name you want to remove"<<endl;
            string hex_name;
            cin>>hex_name;
            cluster.removeHexagon(hex_name);
        }
        else
        if(val == 4)
        {
            break;
        }
        else
        {
            cout<<"Enter a valid number";
        }
        

    } 
    while(true);

    return 0;
}
