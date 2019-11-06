#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Maze {
  string playerPosition, exitPosition;



  public:
      int exitRow, exitColumn;
      int playerRow, playerColumn;
      int width, height;
    std::vector<std::string> createMaze() {
      std::vector<std::string> maze; // Empty on creation
          std::ifstream file("maze1");
  std::string str;
  int counter = 0;
  while (std::getline(file, str)) {
    std::stringstream ss(str);
    if (counter == 0) {
      //std::cout << " in here" << "\n";
              
      ss >> height >> width;
      //std::cout << "Found integer: " << width <<" and " <<height<< "\n";
    }  else if (counter <= height ) {
      maze.push_back(str);
      //std::cout << "In maze "<< str << "\n";
  } else if(counter == height +1){
    
    ss >> exitRow >> exitColumn;
    //std::cout << "Found integer for exit row: " << exitRow <<" and exit column " <<exitColumn<< "\n";
  } else if (counter == height +2){
    
    ss >> playerRow >> playerColumn;
    //std::cout << "Found integer for player row: " << playerRow <<" and player column " <<playerColumn<< "\n";
  }
    //std::cout << str << "\n";
    counter++;
  }
      maze[exitRow][exitColumn] = 'x';
      //std::cout << "output: " << maze[exitRow] << "\n";
      maze[playerRow][playerColumn] = 'P';
      //std::cout << "output: " << maze[playerRow]<< "\n";
      return maze;
    };
    
    void printMaze(std::vector<std::string> maze){
              for (auto i: maze)
      std::cout << i << "\n";
    }
};

class PlayerMovement {
  public:
    void movePlayer(std::vector<std::string> maze, int height,int width, int playerRow, int playerColumn, int exitRow, int exitColumn){
      maze[playerRow][playerColumn] = '.';
      std::ifstream file("maze1");
   std::string s;
   //for performance
   s.reserve(height+3);    

   //skip N linesplayerColumn
   for(int i = 0; i < height+3; ++i)
       std::getline(file, s);

   std::getline(file,s);
    for (int i = 0; i < s.size(); i++){
      //std::cout << s[i]<< "\n";
    switch(s[i]) {
        case 'u':   { 
          //std::cout<<"in it "<<playerColumn<<playerRow<< " "<<maze[playerRow-1][playerColumn]<<"\n";
          if ((playerRow-1 >= 0) && ((maze[playerRow-1][playerColumn] == '.'|| 'x'))){
            playerRow--;
            //std::cout<<" moved up" << playerRow << "\n";
          } else {
            std::cout << "invalid move"<<"\n";
          }
          break;}
        case 'd': {
          if ((playerRow+1 <= height) && (maze[playerRow+1][playerColumn] == '.')){
            playerRow++;
            std::cout<<" moved down" << playerRow << "\n";
          } else {
            std::cout << "invalid move"<<"\n";
          }
          break;}
        case 'l':  {
          if ((playerColumn-1 >= 0) && (maze[playerRow][playerColumn-1] == '.')){
            playerColumn--;
          } else {
            std::cout << "invalid move"<<"\n";
          }
          break;}
        case 'r':  {
          //cout<<"something"<<playerColumn<<playerRow<<maze[playerRow][playerColumn+1]<<"\n";
          if ((playerColumn+1 <= width) && ((maze[playerRow][playerColumn+1] == '.' || 'x'))){
            playerColumn++;
            //std::cout<<" moved right" << playerColumn << "\n";
          } else {
            std::cout << "invalid move"<<"\n";
          }
          break;}
    }

}

    if (maze[playerRow][playerColumn]== 'x'){
        maze[playerRow][playerColumn] = 'P';
        cout<<"\n\n";
        for (auto i: maze)
            std::cout << i << "\n";
      cout<<"\n\n"<<"Player is at the Exit!"<<"\n";    
    } else if(maze[playerRow][playerColumn]== '.'){
      maze[playerRow][playerColumn] = 'P';
          for (auto i: maze)
            std::cout << i << "\n";
      cout<<"\n\n"<<"Player is not at the Exit!"<<"\n";    } }
};

int main () {
  Maze maze;
  PlayerMovement player;
  std::vector<std::string> mazeOut = maze.createMaze();
  maze.printMaze(mazeOut);
  int height = maze.height;
  int width = maze.width;
  int playerRow, playerColumn, exitRow, exitColumn;
  playerRow = maze.playerRow;
  playerColumn = maze.playerColumn;
  exitRow = maze.exitRow;
  exitColumn = maze.exitColumn;
  player.movePlayer(mazeOut,height,width, playerRow, playerColumn, exitRow, exitColumn);
  return 0;
}
