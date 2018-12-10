#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include "ladder.h"
#include "graph.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    string dir1,dir2,dir3;
    dir1="/home/student/workspace/cmpe250-project4-abdullahyildiz2018400291/";
    dir2="input.txt";
    dir3="output.txt";
    string dir_in=dir1+dir2;
    string dir_out=dir1+dir3;
    ifstream myfile;
    myfile.open(dir1+dir2);
    //grap

    if(!myfile.is_open()){
        cout<<"couldn't open it!!"<<endl;
        return -1;
    }


int row,column;
    myfile>>row>>column;


    ladder l(row,column,dir_in,dir_out);

   // l.printMatrix();

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