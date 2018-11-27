#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stdio.h>

using namespace std;
bool isInsideGrid(int x, int y)
{
    if (x <= numberofrows && y <= numberofcolumns && x > 0 && y > 0)
        return true;

    return false;
}
void calculate(){

}
int main(){
    string dir1,dir2;
    dir1="/home/student/workspace/cmpe250-project4-abdullahyildiz2018400291/";
    dir2="input.txt";
    ifstream myfile;
    myfile.open(dir1+dir2);

    if(!myfile.is_open()){
        cout<<"couldn't open it!!"<<endl;
        return -1;
    }
    string line;
    getline(myfile,line);
    stringstream s(line);
    //cout<<line;
    const int numberofrows=5,numberofcolumns=5;

   // memset(visited, 0, sizeof visited);
//    numberofrows=s.get();
//    numberofcolumns=s.get();
   // s>>numberofrows>>numberofcolumns;
    cout<<numberofrows<<numberofcolumns;

    int arrai[numberofrows][numberofcolumns]={{2,2,2,2,2},{3,2,1,0,1},{4,2,0,2,4},{5,2,1,4,7},{6,2,2,6,10}};



    // construct a matrix to keep track of visited cells
    int visited[numberofrows+1][numberofcolumns+1];

    // initially all cells are unvisited
    memset(visited, 0, sizeof visited);

    int sourceX=3,sourceY=1,sinkX=1,sinkY=4;
    cout<<arrai[sourceX][sourceY]<<" -  "<<arrai[sinkX][sinkY];


//    for(int i;i<numberofrows;i++){
//
//        for(int j=0;j<numberofcolumns;j++){
//            getline(myfile,line);
//            stringstream s(line);
//            s>>arrai[i][j];
//           // arrai[i][j]=abs(j+2*i-i*j+1);
//            cout<<arrai[i][j]<<"\t";
//        }
//cout<<endl;
//    }

//    for(int i=1;i<numberofrows+1;i++){
//
//        getline(myfile,line);
//        stringstream sq(line);
//
//        for(int j=1;j<numberofcolumns+1;j++){
//            sq>>arrai[i][j];
//            cout<<arrai[i][j]<<" ";
//        }
//
//    }

    //cout<<arrai[1][3];
//    for(int i=1;i<numberofrows+1;i++){
//
//        for(int j=1;j<numberofcolumns+1;j++){
//            cout<<arrai[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//  getline(myfile,line);

    //int Q=stoi(line);
    //cout<<"Q"<<Q;


//    for(int k=0;k<Q;k++){
//        getline(myfile,line);
//        s<<line;
//        for(int l=0;l<3;l++)
//            s>>sourceX>>sourceY>>sinkX>>sinkY;
//    }

   // cout<<sourceX<<sourceY<<sinkX<<sinkY;


    myfile.close();



    return 0;
}
/*int main(int argc, char* argv[]) {
   // below reads the input file
  //  in your next projects, you will implement that part as well
   if (argc != 3) {
       cout << "Run the code with the following command: ./project2 [input_file] [output_file]" << endl;
       return 1;
   }
   ifstream myfile(argv[1]);
    //ifstream myfile(data);
    if(!myfile.is_open()){
        cout<<"couldn't open it!!"<<endl;
        return -1;
    }*/