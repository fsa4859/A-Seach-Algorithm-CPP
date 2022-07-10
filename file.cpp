#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<cstdlib>
using std::vector;
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;


enum class State {kEmpty, kObstacle,kClosed,kPath,kStart,kFinish};

// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

vector<State> ParseLine(string line){

	vector<State> row;
	istringstream stream_final(line);

	if (stream_final){
		//cout <<"streaming is successful" << "\n";

		int n;
		char c;

		while(stream_final>>n>>c){

			if (n==0){
				row.push_back(State::kEmpty);
			}
			else{
				row.push_back(State::kObstacle);
			}

			
		}


	}

	return row;

}


vector<vector<State>> ReadBoardFile(string path){
	vector<vector<State>> Out;
	ifstream file;
	file.open(path);
	if (file){

		//cout << "the stream is successful"<<"\n";

		string line_print;

		while (getline(file,line_print)){

			vector<State> row=ParseLine(line_print);
			Out.push_back(row);

			//cout << line_print << "\n";
		}

	}

	return Out;

}

bool compare(vector<int> a, vector<int> b){


	int f1=a[2]+a[3]; //f1=g1+h1
	int f2=b[2]+b[3]; //f2=g2+h2

	return f1>f2;


}

void CellSort(vector<vector<int>> *v){

	sort(v->begin(), v->end(), compare);
}




int Heuristic(int x1,int y1, int x2, int y2){

	return abs(x2-x1)+abs(y2-y1);


}

bool CheckValidCell(int x,int y,vector<vector<State>> &grid){

	// check that x and y are valid cells in the grid
	// and that they are empty

	bool on_grid_x=(x>=0 && x<grid.size());
	bool on_grid_y=(y>=0 && y<grid[0].size());

	if (on_grid_x && on_grid_y){

		return grid[x][y]==State::kEmpty;
	}

	return false;
}


void AddtoOpen(int x,int y, int g, int h,
	vector<vector<int>> &OpenNodes,vector<vector<State>> &grid){

	/* pushing the coordinates, h and g to the double vector
	of open nodes.
	*/

	OpenNodes.push_back({x,y,g,h});

	// set the values of x and y in the grid to be closed

	grid[x][y]=State::kClosed;

}


void ExpandNeighbours(const vector<int> &current,int goal[2],
	vector<vector<int>> &openlist, vector<vector<State>> &grid){

	// get current node's data
	int x=current[0];
	int y=current[1];
	int g=current[2];

	// loop through current node potential neighbours
	for (int i=0;i<4;i++){
		int x2=x+delta[i][0];
		int y2=y+delta[i][1];

		// check neighbours are on the grid and are not closed
		if (CheckValidCell(x2,y2,grid)){
			int g2=g+1;
			int h2=Heuristic(x2,y2,goal[0],goal[1]);
			AddtoOpen(x2,y2,g2,h2,openlist,grid);

		}
	}
}





vector<vector<State>> search(vector<vector<State>> grid,int init [2],
	int end [2])
{


	vector<vector<int>> open {};

	// initialize the starting node
	int x1=init[0];
	int y1=init[1];
	int g=0;
	int h=Heuristic(x1,y1,end[0],end[1]);

	// add starting node to open vector
	AddtoOpen(x1,y1,g,h,open,grid);

	while (open.size()>0){

		// get the next node
		CellSort(&open); // arranges in descneding order values of f
		auto current=open.back(); // get the last value
		open.pop_back();
		int x=current[0];
		int y=current[1];
		grid[x][y]=State::kPath;

		// CHECK if the search is done

		if (x==end[0] && y==end[1]){

			return grid;
		}

		// if not done, we expand the search to the neigbours 
		// of the current node

		ExpandNeighbours(current,end,open,grid);
		
	}

	cout << "no path found" << "\n";

	return vector<vector<State>> {};


}


string CellString(State cell){

	string state;

	 switch (cell) {
      case State::kObstacle : return "⛰️ ";
      case State::kPath: return "🚗   ";
      case State::kStart: return " 🚦";
      case State::kFinish: return " 🏁";
      default: return "0";
      }
}





void PrintBoard(const vector<vector<State>> board) {
	string output;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cout << CellString(board[i][j]);
			
    }

    cout << "\n";
  }
}




int main(){

	vector<vector<int>> board={{0,1,0,0,0,0},
{0,1,0,0,0,0},{0,1,0,0,0,0},{0,1,0,0,0,0},
{0,0,0,0,1,0}};


auto Board=ReadBoardFile("board.txt");

int Start[2]={0,0};
int End[2]={4,5};

auto solution=search(Board,Start,End);
//PrintBoard(Board);

int ans=Heuristic(1,2,3,4);

cout << ans;

}


