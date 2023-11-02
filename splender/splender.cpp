#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Map {
    public:
        vector<string> coordinates;
        int xScale;
        int yScale;

    public:
        Map(){}

        Map(istream& istr);

        friend class Robot;

        void getArray() const {
            int length = this->coordinates.size();
            for (int i = 0; i < length; i++) {
                cout << coordinates[i] << endl;
            }
        }

        


};

Map::Map(istream& istr) {
    istr >> this->xScale;
    istr >> this->yScale;
    istr.ignore();

    string textFromTheConsole;

    for (int g = 0; g < yScale; g++) {
        getline(istr, textFromTheConsole);
        coordinates.push_back(textFromTheConsole);
    }
}

class Robot {
    private:
        int currentPositionXXX = 0;
        int currentPositionYYY = 0;

        vector <string> arrayOfMovements;

    public:
        friend class Map;

        

        Robot(const Map& map);

        void getStartingCoordinates() const {
            cout << currentPositionXXX << endl;
            cout << currentPositionYYY << endl;
        }



        void  coordinatesChanger(Map& map) {

            bool B = false;
            bool I = false;

            int counterForB = 0;
            int counterForI = 0;


            while (map.coordinates[currentPositionYYY][currentPositionXXX] != '$'){
                
                if (map.coordinates[currentPositionYYY][currentPositionXXX] == 'B') {
                    counterForB++;
                }

                if (counterForB % 2 != 0) {
                    B = true;
                }
                else {
                    B = false;
                }

                if (map.coordinates[currentPositionYYY][currentPositionXXX] == 'I') {
                    counterForI++;
                }

                if (counterForI % 2 != 0) {
                    I = true;
                }
                else {
                    I = false;
                }

                if (map.coordinates[currentPositionYYY][currentPositionXXX] == 'N') {
                    headingN(currentPositionYYY, currentPositionXXX, map,counterForI,I,counterForB,B);
                    if (map.coordinates[currentPositionYYY][currentPositionXXX] == 'B' || map.coordinates[currentPositionYYY][currentPositionXXX] == 'I') {
                        goto avoidingAmbiguity;
                    }
                    continue;
                }

                if (map.coordinates[currentPositionYYY][currentPositionXXX] == 'S') {
                    headingS(currentPositionYYY, currentPositionXXX, map,counterForI,I,counterForB, B);
                    if (map.coordinates[currentPositionYYY][currentPositionXXX] == 'B' || map.coordinates[currentPositionYYY][currentPositionXXX] == 'I') {
                        goto avoidingAmbiguity;
                    }
                    continue;
                }

                if (map.coordinates[currentPositionYYY][currentPositionXXX] == 'E') {
                    headingE(currentPositionYYY, currentPositionXXX, map,counterForI,I, counterForB, B);
                    if (map.coordinates[currentPositionYYY][currentPositionXXX] == 'B' || map.coordinates[currentPositionYYY][currentPositionXXX] == 'I') {
                        goto avoidingAmbiguity;
                    }
                    continue;
                }

                if (map.coordinates[currentPositionYYY][currentPositionXXX] == 'W') {
                    headingW(currentPositionYYY, currentPositionXXX, map,counterForI,I, counterForB, B);
                    if (map.coordinates[currentPositionYYY][currentPositionXXX] == 'B' || map.coordinates[currentPositionYYY][currentPositionXXX] == 'I') {
                        goto avoidingAmbiguity;
                    }
                    continue;
                }

                if (map.coordinates[currentPositionYYY][currentPositionXXX] == 'T') {
                    teleport(currentPositionYYY, currentPositionXXX, map);
                    //counterForT++;
                    //continue;
                }

                avoidingAmbiguity:
                if (I == false) {
                    if (South(currentPositionYYY, currentPositionXXX, map, B)) {
                        continue;
                    }

                    if (East(currentPositionYYY, currentPositionXXX, map, B)) {
                        continue;
                    }

                    if (North(currentPositionYYY, currentPositionXXX, map, B)) {
                        continue;
                    }

                    if (West(currentPositionYYY, currentPositionXXX, map, B)) {
                        continue;
                    }
                }
                else {
                    if (West(currentPositionYYY, currentPositionXXX, map, B)) {
                        continue;
                    }

                    if (North(currentPositionYYY, currentPositionXXX, map, B)) {
                        continue;
                    }

                    if (East(currentPositionYYY, currentPositionXXX, map, B)) {
                        continue;
                    }

                    if (South(currentPositionYYY, currentPositionXXX, map, B)) {
                        continue;
                    }
                }

                /*if (map.coordinates[currentPositionYYY + 1][currentPositionXXX] != '#') {
                    
                    if (map.coordinates[currentPositionYYY + 1][currentPositionXXX] != 'X') {
                        this->currentPositionXXX = currentPositionXXX;
                        this->currentPositionYYY = currentPositionYYY + 1;
                        cout << "South" << endl;
                        continue;
                    }
                    
                    if (map.coordinates[currentPositionYYY + 1][currentPositionXXX] == 'X')
                    {   
                        if (B == true) {
                            this->currentPositionXXX = currentPositionXXX;
                            this->currentPositionYYY = currentPositionYYY + 1;
                            cout << "South" << endl;
                            continue;
                        }
                    }   
                }
                */

                /* if (map.coordinates[currentPositionYYY][currentPositionXXX + 1] != '#') {

                    if (map.coordinates[currentPositionYYY][currentPositionXXX + 1] != 'X') {
                        this->currentPositionXXX = currentPositionXXX + 1;
                        this->currentPositionYYY = currentPositionYYY;
                        cout << "East" << endl;
                        continue;
                    }

                    if (map.coordinates[currentPositionYYY][currentPositionXXX + 1] == 'X') {

                        if (B == true) {
                            this->currentPositionXXX = currentPositionXXX + 1;
                            this->currentPositionYYY = currentPositionYYY;
                            cout << "East" << endl;
                            continue;
                        }
                    }
                }
                */

                /*if (map.coordinates[currentPositionYYY - 1][currentPositionXXX] != '#') {

                    if (map.coordinates[currentPositionYYY - 1][currentPositionXXX] != 'X') {
                        this->currentPositionXXX = currentPositionXXX;
                        this->currentPositionYYY = currentPositionYYY - 1;
                        cout << "North" << endl;
                        continue;
                    }

                    if (map.coordinates[currentPositionYYY - 1][currentPositionXXX] == 'X') {
                        
                        if (B == true) {
                            this->currentPositionXXX = currentPositionXXX;
                            this->currentPositionYYY = currentPositionYYY - 1;
                            cout << "North" << endl;
                            continue;
                        }
                    }       
                }
                */

                /*if (map.coordinates[currentPositionYYY][currentPositionXXX - 1] != '#') {

                    if (map.coordinates[currentPositionYYY][currentPositionXXX - 1] != 'X') {
                        this->currentPositionXXX = currentPositionXXX - 1;
                        this->currentPositionYYY = currentPositionYYY;
                        cout << "West" << endl;
                        continue;
                    }

                    if (map.coordinates[currentPositionYYY][currentPositionXXX - 1] == 'X') {
                        if (B == true) {
                            this->currentPositionXXX = currentPositionXXX - 1;
                            this->currentPositionYYY = currentPositionYYY;
                            cout << "West" << endl;
                            continue;
                        }
                    }    
                }
                */
            }
        }
        bool South(int& y, int& x, Map& map, bool B) {
            if (map.coordinates[y + 1][x] != '#') {

                if (map.coordinates[y + 1][x] != 'X') {
                    y = y + 1;
                    cout << "South" << endl;
                    return true;
                    
                }

                if (map.coordinates[y + 1][x] == 'X')
                {
                    if (B == true) {
                        
                        y = y + 1;
                        cout << "South" << endl;
                        return true;
                        
                    }
                }
            }
            else {
                return false;
            }
            
        }

        bool East(int& y, int& x, Map& map, bool B) {
            if (map.coordinates[y][x + 1] != '#') {

                if (map.coordinates[y][x + 1] != 'X') {
                    x = x + 1;
                    cout << "East" << endl;
                    return true;

                }

                if (map.coordinates[y][x + 1] == 'X')
                {
                    if (B == true) {

                        x = x + 1;
                        cout << "East" << endl;
                        return true;

                    }
                }
            }
            else {
                return false;
            }
        }

        bool North(int& y, int& x, Map& map, bool B) {
            if (map.coordinates[y - 1][x] != '#') {

                if (map.coordinates[y - 1][x] != 'X') {
                    y = y - 1;
                    cout << "North" << endl;
                    return true;

                }

                if (map.coordinates[y - 1][x] == 'X')
                {
                    if (B == true) {

                        y = y - 1;
                        cout << "North" << endl;
                        return true;

                    }
                }
            }
            else {
                return false;
            }
        }

        bool West(int& y, int& x, Map& map, bool B) {
            if (map.coordinates[y][x - 1] != '#') {

                if (map.coordinates[y][x - 1] != 'X') {
                    x = x - 1;
                    cout << "West" << endl;
                    return true;

                }

                if (map.coordinates[y][x - 1] == 'X')
                {
                    if (B == true) {

                        x = x - 1;
                        cout << "West" << endl;
                        return true;

                    }
                }
            }
            else {
                return false;
            }
        }
        
        
        void headingN(int & y, int & x, Map & map,int & Icounter,bool & I, int & Bcounter, bool & B) {
            
            while (true) {
              
                if (map.coordinates[y][x] == 'W') {
                    break;
                }
                if (map.coordinates[y][x] == 'E') {
                    break;
                }
                if (map.coordinates[y][x] == 'S') {
                    break;
                }
                if (map.coordinates[y][x] == '$') {
                    break;
                }
                if (map.coordinates[y][x] == 'T') {
                    break;
                }
                if (map.coordinates[y][x] == 'I') {
                    Icounter++;
                    if (Icounter % 2 != 0) {
                        I = true;
                    }
                    else {
                        I = false;
                    }
                }
                if (map.coordinates[y][x] == 'B') {
                    Bcounter++;
                    if (Bcounter % 2 != 0) {
                        B = true;
                    }
                    else {
                        B = false;
                    }
                }
                if (map.coordinates[y][x] == 'X') {
                    if (B == false) {
                        y++;
                        break;
                    }
                }
                if (map.coordinates[y][x] == '#') {
                    y++;
                    break;
                }
                if (map.coordinates[y - 1][x] != '#') {
                    if (map.coordinates[y - 1][x] == 'X' && B == false) {

                    }
                    else {
                        cout << "North" << endl;
                    }
                }
                y--;
            }
        }
        void headingS(int & y, int & x, Map& map, int & Icounter,bool & I, int& Bcounter, bool& B) {
            while (true) {
                
                if (map.coordinates[y][x] == 'N') {
                    break;
                }
                if (map.coordinates[y][x] == 'E') {
                    break;
                }
                if (map.coordinates[y][x] == 'W') {
                    break;
                }
                if (map.coordinates[y][x] == '$') {
                    break;
                }
                if (map.coordinates[y][x] == 'T') {
                    break;
                }
                if (map.coordinates[y][x] == 'I') {
                    Icounter++;
                    if (Icounter % 2 != 0) {
                        I = true;
                    }
                    else {
                        I = false;
                    }
                }
                if (map.coordinates[y][x] == 'B') {
                    Bcounter++;
                    if (Bcounter % 2 != 0) {
                        B = true;
                    }
                    else {
                        B = false;
                    }
                }
                if (map.coordinates[y][x] == 'X') {
                    if (B == false) {
                        y--;
                        break;
                    }
                }
                if (map.coordinates[y][x] == '#') {
                    y--;
                    break;
                }
                if (map.coordinates[y + 1][x] != '#') {
                    if (map.coordinates[y + 1][x] == 'X' && B == false) {

                    }
                    else {
                        cout << "South" << endl;
                    }
                }
                y++;
             
            }
        }
        void headingE(int& y, int& x, Map& map, int & Icounter,bool & I, int& Bcounter, bool& B){
            while (true) {
                
                if (map.coordinates[y][x] == 'N') {
                    break;
                }
                if (map.coordinates[y][x] == 'W') {
                    break;
                }
                if (map.coordinates[y][x] == 'S') {
                    break;
                }
                if (map.coordinates[y][x] == '$') {
                    break;
                }
                if (map.coordinates[y][x] == 'T') {
                    break;
                }
                if (map.coordinates[y][x] == 'I') {
                    Icounter++;
                    if (Icounter % 2 != 0) {
                        I = true;
                    }
                    else {
                        I = false;
                    }
                }
                if (map.coordinates[y][x] == 'B') {
                    Bcounter++;
                    if (Bcounter % 2 != 0) {
                        B = true;
                    }
                    else {
                        B = false;
                    }
                }
                if (map.coordinates[y][x] == 'X') {
                    if (B == false) {
                        x--;
                        break;
                    }
                }
                if (map.coordinates[y][x] == '#') {
                    x--;
                    break;
                }

                if (map.coordinates[y][x + 1] != '#') {
                    if (map.coordinates[y][x + 1] == 'X' && B == false) {

                    }
                    else {
                        cout << "East" << endl;
                    }
                }
                x++;
            }

        }
        void headingW(int& y, int& x, Map& map, int & Icounter,bool& I, int& Bcounter, bool& B) {
            while (true) {
               
                if (map.coordinates[y][x] == 'N') {
                    break;
                }
                if (map.coordinates[y][x] == 'E') {
                    break;
                }
                if (map.coordinates[y][x] == 'S') {
                    break;
                }
                if (map.coordinates[y][x] == '$') {
                    break;
                }
                if (map.coordinates[y][x] == 'T') {
                    break;
                }
                if (map.coordinates[y][x] == 'I') {
                    Icounter++;
                    if (Icounter % 2 != 0) {
                        I = true;
                    }
                    else {
                        I = false;
                    }
                }
                if (map.coordinates[y][x] == 'B') {
                    Bcounter++;
                    if (Bcounter % 2 != 0) {
                        B = true;
                    }
                }
                if (map.coordinates[y][x] == 'X') {
                    if (B == false) {
                        x++;
                        break;
                    }
                    else {
                        B = false;
                    }
                }
                if (map.coordinates[y][x] == '#') {
                    x++;
                    break;
                }
                if (map.coordinates[y][x - 1] != '#') {
                    if (map.coordinates[y][x - 1] == 'X' && B == true) {

                    }
                    else {
                        cout << "West" << endl;
                    }
                }
                x--;
            }
        }
        void teleport(int& y, int& x, Map& map) {
            if (map.coordinates[y][x] == 'T') {
                for (int i = 0; i < map.yScale; i++) {
                    for (int g = 0; g < map.xScale; g++){
                        if (map.coordinates[i][g] == 'T') {
                            if (y != i || x != g) {
                                y = i;
                                x = g;
                                goto breakingFor;
                            }
                        }
                    }                   
                }
            breakingFor:;
            }
        }


};

Robot::Robot(const Map& map) {
    for (int i = 0; i < map.yScale; i++) {
        for (int g = 0; g < map.xScale; g++) {
            if (map.coordinates[i][g] == '@') {
                this->currentPositionXXX = g;
                this->currentPositionYYY = i;
            }
        }
    }
}

int main()
{   
    Map theMap(cin);
    //theMap.getArray();
    Robot r1(theMap);
    //rumencho.getStartingCoordinates();
    r1.coordinatesChanger(theMap);
    return 0;

}
/*
10 10
##########
#        #
#  S   W #
#        #
#        #
#  $     #
#@       #
#        #
#E     N #
##########
*/
/*
5 5
#####
#@ T#
#T  #
#  $#
#####
*/

/*
8 8
########
# @    #
#     X#
# XXX  #
#   XX #
#   XX #
#     $#
########

*/
/*
5 5
#####
#@ T#
#   #  
#T$N#
#####
*/
/*
5 5
#####
#   #
#$ I#
#  @#
#####
*/
/*
5 5
#####
#@  #
#   #
#  $#
#####
*/
/*
8 8
########
#      #
#      #
#      #
#$     #
# I   W#
#X   @ #
########
*/
/*
8 8
########
#T$   I#
#      #
#E    N#
#      #
#      #
#  @  T#
########
*/
/*
8 8
########
# $   I#
#      #
#    @N#
#    X #
#      #
#      #
########
*/
/*
8 8
########
# $   I#
#      #
#    @N#
#    X #
#      #
#      #
########
*/
/*
8 8
########
#      #
#      #
#  @   #
#  S   #
#      #
#$ I   #
########
*/
/*
8 8
########
#  @   #
#  S   #
#  B   #
#   $  #
#  X   #
#$ I   #
########
*/
