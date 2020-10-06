#include<bits/stdc++.h>
#include <limits>
using namespace std;


class Hexagon
{
    public:
        string hexagonName;   
        pair<int,int> hexagonXY; 
        Hexagon()
        {
            hexagonName = "NULL";
            hexagonXY.first = numeric_limits<int>::min();
            hexagonXY.second = numeric_limits<int>::min();
        }

        Hexagon(string strtemp, int xCo, int yCo)
        {
            hexagonName = strtemp;
            hexagonXY.first = xCo;
            hexagonXY.second = yCo;
        }

        pair<int,int> getNewHexagonXY(int borderNumber);
        
        bool operator==(const pair<int,int>& temp) const
        {
            if( (this->hexagonXY).first == temp.first && (this->hexagonXY).second == temp.second )
                return true;
            else 
                return false;
        }
                bool operator==(const Hexagon& temp) const
        {
            if(this->hexagonXY.first == temp.hexagonXY.first && this->hexagonXY.second == temp.hexagonXY.second)
                return true;
            else 
                return false;
        }

        bool operator==(const string& temp) const
        {
            if(this->hexagonName == temp)
                return true;
            else 
                return false;
        }

        bool operator<(const pair<int,int>& XY_temp) const
        {
            if( (this->hexagonXY).first<XY_temp.first)
                return true;
            else 
            if((this->hexagonXY).first==XY_temp.first)
            {
                if((this->hexagonXY).second<XY_temp.second)
                    return true;
                else
                    return false;
            }
            else
                return false;    
        }
         bool operator<(const Hexagon& a) const 
        {
            if( (this->hexagonXY).first<a.hexagonXY.first)
                return true;
            else 
            if((this->hexagonXY).first==a.hexagonXY.first)
            {
                if((this->hexagonXY).second<a.hexagonXY.second)
                    return true;
                else
                    return false;
            }
            else
                return false;    
        }


        
};