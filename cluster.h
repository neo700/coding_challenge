#include <bits/stdc++.h>
#include <limits>
#include "hexagon.h"
using namespace std;

class Cluster
{
public:
    Hexagon hexagon;
    set<Hexagon> hexagonSet;
    map<string, int> visited;

    Cluster()
    {
        hexagon.hexagonName = "NULL";
        (hexagon.hexagonXY).first = numeric_limits<int>::min();
        (hexagon.hexagonXY).second = numeric_limits<int>::min();
        Hexagon firstHex("A", 0, 0);
        hexagonSet.insert(firstHex);
    }

    // Compare a hexagon with a coordinate
    bool hexagonXYCmp(Hexagon &temp, pair<int, int> XY_temp);
    // Returns Hexagon with the specified name
    Hexagon getHexagonFromName(string hex_name);
    // Returns Hexagon with the specified coordinates
    Hexagon getHexagonFromXY(int xCo, int yCo);
    // Checks if Border is free to add a new hexagon
    bool checkborderNumberderFree(string hexagon_name, int borderNumber);
    // Adds new Hexagon to the cluster
    void addNewHexagon(string hex_present, int borderNumber, string hex_new);
    // Gets name of neighbours
    void getNeighbour(string hexagon_name);
    // Dfs to find whether all the hexagons are reachable from first hexagon
    void dfs(Hexagon root);
    // Checks whether all the hexagons are connected or not
    bool IsConnected();
    // Removes the hexagon from the cluster
    void removeHexagon(string hex_name); 
};