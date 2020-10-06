#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "hexagon.h"
using namespace std;

pair<int, int> Hexagon::getNewHexagonXY(int borderNumber)
{
    int x = hexagonXY.first;
    int y = hexagonXY.second;
    // Pattern of coordinates of neighborderNumber's heads according to the borderNumberder shared.
    if(borderNumber == 0)
        return {x, y + 2};
    else 
    if(borderNumber == 1)
        return {x + 2, y + 1};
    else 
    if(borderNumber == 2)
        return {x + 2, y - 1};
    else 
    if(borderNumber == 3)
        return {x, y - 2};
    else 
    if(borderNumber == 4)
        return {x - 2, y - 1};
    else
        return {x - 2, y + 1};
}