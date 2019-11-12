//
//  workwavefront.cpp
//  ComputerScience
//
//  Created by David Reeves on 11/11/19.
//  Copyright © 2019 David Reeves. All rights reserved.
//

#include "workwavefront.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <array>
using namespace std;
int pathway[5][5] = {
    {0,1,0,0,0},
    {0,0,0,1,0},
    {1,1,1,1,0},
    {0,0,0,1,0},
    {0,1,0,0,0}
};

int directional[5][5] = {
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
};
//North = 3, East = 4, West = 5, South = 6
int currentWave = 2;
bool finished = false;
void changesdv(){
    int x = 0;
    int y = 0;
    bool replacement = false;
    while(!replacement){
        cout << "Current Layout:" << endl;
        for(int i = 0;i< 5;i++){
          for(int j = 0;j< 5;j++){
            if(pathway[i][j] == 2){
              cout << " *  ";
            }
            else if (pathway[i][j] == 1){
              cout << " x  ";
            }
            else if (pathway[i][j] == 99){
              cout << " #  ";
            }
            else if (pathway[i][j] == 0){
              cout << " .  ";
            }
            
          }
            cout << endl;
        }
        bool valid = false;
        while(!valid){
            cout << "Please choose an X-VALUE to place the SDV in (1 to 5):" << endl << "> ";
            cin >> x;
            cout << endl;
            if (!cin || x > 5 || x < 1){
                cout << "Input invalid! Try again" << endl;
                valid = false;
            }else{
                valid = true;
            }
        }
        valid = false;
        while(!valid){
            cout << "Please choose a Y-VALUE to place the SDV in (1 to 5):" << endl << "> ";
            cin >> y;
            cout << endl;
            if (!cin || y > 5 || y < 1){
                cout << "Input invalid! Try again" << endl;
                valid = false;
            }else{
                valid = true;
            }
            }
        if(pathway[5-y][x-1] == 0){
            replacement = true;
            pathway[5-y][x-1] = 99;
        }else{
            cout << "Replacement value must not occupy another space! Please choose a value on the grid that is a '.'!";
        }
    }
    
}
void changegoal(){
    int x = 0;
    int y = 0;
    bool replacement = false;
    while(!replacement){
        cout << "Current Layout:" << endl;
        for(int i = 0;i< 5;i++){
          for(int j = 0;j< 5;j++){
            if(pathway[i][j] == 2){
              cout << " *  ";
            }
            else if (pathway[i][j] == 1){
              cout << " x  ";
            }
            else if (pathway[i][j] == 99){
              cout << " #  ";
            }
            else if (pathway[i][j] == 0){
              cout << " .  ";
            }
            
          }
            cout << endl;
        }
        bool valid = false;
        while(!valid){
            cout << "Please choose an X-VALUE to place the GOAL in (1 to 5):" << endl << "> ";
            cin >> x;
            cout << endl;
            if (!cin || x > 5 || x < 1){
                cout << "Input invalid! Try again" << endl;
                valid = false;
            }else{
                valid = true;
            }
        }
        valid = false;
        while(!valid){
            cout << "Please choose a Y-VALUE to place the GOAL in (1 to 5):" << endl << "> ";
            cin >> y;
            cout << endl;
            if (!cin || y > 5 || y < 1){
                cout << "Input invalid! Try again" << endl;
                valid = false;
            }else{
                valid = true;
            }
            }
        if(pathway[5-y][x-1] == 0){
            replacement = true;
            pathway[5-y][x-1] = 2;
        }else{
            cout << "Replacement value must not occupy another space! Please choose a value on the grid that is a '.'!";
        }
    }
    
}
int buildwf(){
    for(int i = 0;i< 5;i++){
      for(int j = 0;j< 5;j++){
        if(pathway[i][j] == currentWave){
          //NORTH
          if(i > 0){
              if(pathway[i - 1][j] == 0){
                  pathway[i - 1][j]=currentWave + 1;
                  directional[i-1][j]=6;
                  finished = false;
              }
              else if(pathway[i - 1][j] == 99){
                  directional[i-1][j]=10;
              }
          }
            //EAST
            if(j < 4){
                if(pathway[i][j + 1] == 0){
                    pathway[i][j + 1]=currentWave + 1;
                    directional[i][j + 1]=5;
                    finished = false;
                }
                else if(pathway[i][j+1] == 99){
                    directional[i][j+1]=9;
                }
            }
            //WEST
            if(j > 0){
                if(pathway[i][j - 1] == 0){
                    pathway[i][j - 1]=currentWave + 1;
                    directional[i][j - 1]=4;
                    finished = false;
                }
                else if(pathway[i][j-1] == 99){
                    directional[i][j-1]=8;
                }
            }
            //SOUTH
            if(i < 4){
                if(pathway[i + 1][j] == 0){
                    pathway[i + 1][j]=currentWave + 1;
                    directional[i+1][j]=3;
                    finished = false;
                }
                else if(pathway[i + 1][j] == 99){
                    directional[i+1][j]=7;
                }
            }
        }
        
      }
        cout << endl;
    }
    for(int i = 0;i< 5;i++){
      for(int j = 0;j< 5;j++){
        if(pathway[i][j] == 2){
          cout << " *  ";
        }
        else if (pathway[i][j] == 1){
          cout << " x  ";
        }
        else if (pathway[i][j] == 99){
          cout << " #  ";
        }
        else if (pathway[i][j] == 0){
          cout << "    ";
        }else{
            if(pathway[i][j]-2 > 9){
                cout << " ";
                cout << pathway[i][j]-2;
                cout << " ";
            }else{
                cout << " ";
                cout << pathway[i][j]-2;
                cout << "  ";
            }
                
        }
        
      }
        cout << endl;
    }
    currentWave++;
    return 0;
}

int workwavefront(){
    changesdv();
    changegoal();
    for(int i = 0;i< 5;i++){
      for(int j = 0;j< 5;j++){
        if(pathway[i][j] == 2){
            directional[i][j] = 2;
        }
        else if (pathway[i][j] == 99){
            directional[i][j] = 99;
        }
        
      }
        
    }
    
    //SET DIRECTIONAL
    
    
    
    for(int i = 0;i< 5;i++){
      for(int j = 0;j< 5;j++){
        if(pathway[i][j] == 2){
          cout << " *  ";
        }
        else if (pathway[i][j] == 1){
          cout << " x  ";
        }
        else if (pathway[i][j] == 99){
          cout << " #  ";
        }
        else if (pathway[i][j] == 0){
          cout << "    ";
        }else{
            if(pathway[i][j] > 9){
                cout << " ";
                cout << pathway[i][j];
                cout << " ";
            }else{
                cout << " ";
                cout << pathway[i][j];
                cout << "  ";
            }
                
        }
        
      }
        cout << endl;
    }
    int moves = 0;
    while(true){
        finished = true;
        int build = buildwf();
        if(finished == true){
            break;
        }
        moves = currentWave-2;
        sleep(1);
    }
    int check = 0;
    int amount = 99;
    int waysin = 0;
    for(int i = 0;i< 5;i++){
      for(int j = 0;j< 5;j++){
        
        if (pathway[i][j] == 99){
          //NORTH
          if(i > 0){
              if(pathway[i - 1][j] > 0){
                  check = pathway[i-1][j];
                  if(check < amount && check > 1){
                      amount = check;
                      waysin++;
                  }
              }
          }
            //EAST
            if(j < 4){
                if(pathway[i][j + 1] > 0){
                    check = pathway[i][j+1];
                    if(check < amount && check > 1){
                        amount = check;
                        waysin++;
                    }
                }
            }
            //WEST
            if(j > 0){
                if(pathway[i][j - 1] > 0){
                    check = pathway[i][j-1];
                    if(check < amount && check > 1){
                        amount = check;
                        waysin++;
                    }
                }
            }
            //SOUTH
            if(i < 4){
                if(pathway[i + 1][j] > 0){
                    check = pathway[i+1][j];
                    if(check < amount && check > 1){
                        amount = check;
                        waysin++;
                    }
                }
            }
        }
        
      }
        cout << endl;
    }
    amount++;
    amount = amount - 2;
    
    if(amount < 25){
        cout << endl;
        cout << "Directional Map:";
        cout << endl;
        for(int i = 0;i< 5;i++){
          for(int j = 0;j< 5;j++){
            if(directional[i][j] == 3){
              cout << " ^  ";
            }
            else if (directional[i][j] == 4){
              cout << " >  ";
            }
            else if (directional[i][j] == 5){
              cout << " <  ";
            }
            else if (directional[i][j] == 6){
              cout << " v  ";
            }
              else if (directional[i][j] == 7){
                cout << " ^# ";
              }
              else if (directional[i][j] == 8){
                cout << " ># ";
              }
              else if (directional[i][j] == 9){
                cout << " <# ";
              }
              else if (directional[i][j] == 10){
                cout << " v# ";
              }
            else if (directional[i][j] == 0){
                cout << " .  ";
            }
            else if (directional[i][j] == 2){
                cout << " *  ";
            }
            else if (directional[i][j] == 99){
                  cout << " #  ";
            }
            
          }
            cout << endl;
        }
        
        
        
        //FIND START
        int strow = 0;
        int stcol = 0;
        int nerow = 0;
        int necol = 0;
        int direct = 0;
        //UP = 1, LEFT = 2, DOWN = 3, RIGHT = 4
        int retrace[90];
        //FORWARD = 1, TURN LEFT = 2, TURN RIGHT = 3, END = 4
        for(int i = 0;i< 5;i++){
          for(int j = 0;j< 5;j++){
              if (directional[i][j] == 7){
                  strow = i;
                  stcol = j;
                  nerow = i-1;
                  necol = j;
                  direct = 1;
                  retrace[0] = 1;
              }
              else if (directional[i][j] == 8){
                  strow = i;
                  stcol = j;
                  nerow = i;
                  necol = j+1;
                  direct = 2;
                  retrace[0] = 1;
              }
              else if (directional[i][j] == 9){
                  strow = i;
                  stcol = j;
                  nerow = i;
                  necol = j-1;
                  direct = 4;
                  retrace[0] = 1;
              }
              else if (directional[i][j] == 10){
                  strow = i;
                  stcol = j;
                  nerow = i+1;
                  necol = j;
                  direct = 3;
                  retrace[0] = 1;
              }
            
          }
            cout << endl;
        }
        bool maps = true;
        int retracecount = 1;
        while(maps){
            strow = nerow;
            stcol = necol;
            if (directional[strow][stcol] == 3){
                if(direct == 1){
                    
                }else if(direct == 2){
                    retrace[retracecount] = 2;
                    retracecount++;
                }
                else if(direct == 4){
                    retrace[retracecount] = 3;
                    retracecount++;
                }
                nerow = strow-1;
                necol = stcol;
                direct = 1;
                retrace[retracecount] = 1;
            }
            else if (directional[strow][stcol] == 4){
              
                if(direct == 2){
                    
                }else if(direct == 3){
                    retrace[retracecount] = 2;
                    retracecount++;
                }
                else if(direct == 1){
                    retrace[retracecount] = 3;
                    retracecount++;
                }
                nerow = strow;
                necol = stcol+1;
                direct = 2;
                retrace[retracecount] = 1;
            }
            else if (directional[strow][stcol] == 5){
                if(direct == 4){
                    
                }else if(direct == 1){
                    retrace[retracecount] = 2;
                    retracecount++;
                }
                else if(direct == 3){
                    retrace[retracecount] = 3;
                    retracecount++;
                    
                }
                nerow = strow;
                necol = stcol-1;
                direct = 4;
                retrace[retracecount] = 1;
            }
            else if (directional[strow][stcol] == 6){
                if(direct == 3){
                    
                }else if(direct == 2){
                    retrace[retracecount] = 2;
                    retracecount++;
                }
                else if(direct == 4){
                    retrace[retracecount] = 3;
                    retracecount++;
                }
                nerow = strow+1;
                necol = stcol;
                direct = 3;
                retrace[retracecount] = 1;
            }
            else if (directional[strow][stcol] == 2){
                break;
            }
            sleep(1);
            retracecount++;
        }
        retrace[retracecount] = 4;
        for(int i = 0; i < sizeof(retrace);i++){
            if(retrace[i] == 1){
                cout << "FORWARD";
            }else if(retrace[i] == 2){
                cout << "TURN";
            }
            else if(retrace[i] == 3){
                cout << "TURN";
            }
            else if(retrace[i] == 4){
                cout << "Finished!" << endl;
                break;
            }
            cout << endl;
            sleep(1);
        }
        cout << "The shortest path will take the SDV ";
        cout << retracecount-1;
        cout << " moves (including turns) to reach the goal!";
    }else{
        cout << "There is no possible pathway to reach the goal from the SDV!";
    }
    return 0;
}

