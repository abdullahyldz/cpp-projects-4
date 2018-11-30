#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include "ladder.h"
using namespace std;
//bool isInsideGrid(int x, int y)
//{
//    if (x <= numberofrows && y <= numberofcolumns && x > 0 && y > 0)
//        return true;
//
//    return false;
//}
//void calculate(){
//
//}
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

int row,column;
    s>>row>>column;

    int** matrix = new int*[row];
    for(int i = 0; i < row; ++i)
        matrix[i] = new int[column];

    for(int i=0;i<row;i++){
        getline(myfile,line);
        stringstream s(line);
        for(int j=0;j<column;j++){
            s>>matrix[i][j];
            }
    }
    getline(myfile,line);
    int Q;
    myfile>>Q;
//    int * sourceX[Q],sourceY[Q],sinkX[Q],sinkY[Q];
//
//    for(int i=0;i<Q;i++){
//        getline(myfile,line);
//        stringstream s(line);
//        s>>sourceX[i]>>
//    }
    cout<<"Q"<<Q<<endl;

    bool ** visited=new bool*[row];
    for(int i = 0; i < row; ++i)
        visited[i]=new bool[column,false];

    ladder l(matrix,row,column,Q,0,0,5,3,visited);
    l.printMatrix();
    for(int i = 0; i < row; ++i){
        delete visited[i];
        delete matrix[i];
        cout<<"\ndeleted!";
    }

    // initially all cells are unvisited
    //memset(visited, 0, sizeof visited);

    //int sourceX=3,sourceY=1,sinkX=1,sinkY=4;


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