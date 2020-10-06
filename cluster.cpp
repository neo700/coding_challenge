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

// Compare a hexagon with a coordinate
bool Cluster::hexagonXYCmp(Hexagon &temp, pair<int, int> XY_temp)
{
    if (temp.hexagonXY.first == XY_temp.first && temp.hexagonXY.second == XY_temp.second)
        return true;
    else
        return false;
}

// Returns Hexagon with the specified name
Hexagon Cluster::getHexagonFromName(string hex_name)
{
    auto it = hexagonSet.begin();
    for (; it != hexagonSet.end(); it++)
    {
        if ((*it) == hex_name)
            break;
    }
    if (it == hexagonSet.end())
        return hexagon;
    else
        return (*it);
}

// Returns Hexagon with the specified coordinates
Hexagon Cluster::getHexagonFromXY(int xCo, int yCo)
{
    pair<int, int> toFind = make_pair(xCo, yCo);
    auto it = find_if(hexagonSet.begin(), hexagonSet.end(), [&toFind](const Hexagon &temp) { return ((temp.hexagonXY.first == toFind.first) && (temp.hexagonXY.second == toFind.second)); });

    if (it != hexagonSet.end())
        return *it;
    else
        return hexagon;
}

// Checks if Border is free to add a new hexagon
bool Cluster::checkborderNumberderFree(string hexagon_name, int borderNumber)
{
    Hexagon hexa = getHexagonFromName(hexagon_name);
    Hexagon temp;
    bool flag = false;
    pair<int, int> temp_hexXY;
    temp_hexXY = hexa.getNewHexagonXY(borderNumber);
    temp = getHexagonFromXY(temp_hexXY.first, temp_hexXY.second);
    if (!(temp == hexagon))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Adds new Hexagon to the cluster
void Cluster::addNewHexagon(string hex_present, int borderNumber, string hex_new)
{
    Hexagon hexAp = getHexagonFromName(hex_present);
    bool val = checkborderNumberderFree(hex_present, borderNumber);
    if (val == true)
    {
        cout << "Border already occupied" << endl;
    }
    else
    {
        pair<int, int> newHexCo = hexAp.getNewHexagonXY(borderNumber);
        Hexagon newHex(hex_new, newHexCo.first, newHexCo.second);
        hexagonSet.insert(newHex);
        cout << "Hexagon " << hex_new << " added" << endl;
    }
}

// Gets name of neighbours
void Cluster::getNeighbour(string hexagon_name)
{
    Hexagon hexa = getHexagonFromName(hexagon_name);
    Hexagon temp;
    bool flag = false;
    pair<int, int> temp_hexXY;
    cout << "Neighbours of " << hexagon_name << " are - " << endl;
    cout << "Border  Hexagon" << endl;
    for (int i = 0; i < 6; i++)
    {
        temp_hexXY = hexa.getNewHexagonXY(i);
        temp = getHexagonFromXY(temp_hexXY.first, temp_hexXY.second);
        if (!(temp == hexagon))
        {
            cout << i << "        " << temp.hexagonName << endl;
            flag = true;
        }
    }
    if (flag == false)
    {
        cout << "No Neighbour Present!" << endl;
    }
}

// Dfs to find whether all the hexagons are reachable from first hexagon
void Cluster::dfs(Hexagon root)
{
    visited[root.hexagonName] = 1;
    pair<int, int> temp_hexXY;
    Hexagon temp;
    for (int i = 0; i < 6; i++)
    {
        temp_hexXY = root.getNewHexagonXY(i);
        temp = getHexagonFromXY(temp_hexXY.first, temp_hexXY.second);
        if (visited[temp.hexagonName] == 0)
            dfs(temp);
    }
}

// Checks whether all the hexagons are connected or not
bool Cluster::IsConnected()
{
    auto it = hexagonSet.begin();
    Hexagon temp, hexRoot;
    visited.clear();

    hexRoot = *it;

    for (; it != hexagonSet.end(); it++)
    {
        temp = *it;
        visited[temp.hexagonName] = 0; // initializing the visited map. 0 means not visited, 1 means visited.
    }

    dfs(hexRoot);

    bool ans = true;
    for (it = hexagonSet.begin(); it != hexagonSet.end(); it++)
    {
        temp = *it;
        if (visited[temp.hexagonName] == 0)
        {
            ans = false;
            break;
        }
    }

    return ans;
}

// Removes the hexagon from the cluster
void Cluster::removeHexagon(string hex_name)
{
    Hexagon hexToRem = getHexagonFromName(hex_name);
    if (hexToRem.hexagonName == "NULL")
    {
        cout << "Hexagon name not present in the grid" << endl;
    }
    else
    {
        hexagonSet.erase(hexToRem);
        if (!IsConnected())
        {
            // case where cluster gets divided so we do not remove the hexagon
            hexagonSet.insert(hexToRem);
            cout << "Hexagon did not get removed as it connects two hotspots." << endl;
        }
        else
            cout << "Hexagon got removed." << endl;
    }
}