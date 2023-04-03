#include "ArgumentManager.h"
#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool isSolved(vector<vector<char>> matrix, size_t row, size_t col)
{
  for(size_t i=0;i<row;i++)
    {
      for(size_t j=0;j<col;j++)
        {
          if(matrix[i][j] == 'B')
            return false;
        }
    }
  return true;
}

void moveUp(vector<vector<char>> &matrix, size_t row, size_t col)
{
  Stack s;
  int counter =0;
  char temp;
  for(int j=0;j<col;j++)
    {
      for(int i =0;i<row;i++)
        {
          if(matrix[i][j] != 'O' && matrix[i][j] != 'X')
          {
            if(!s.isEmpty() && s.peek() == 'B')
            {
              temp = s.pop();
              s.push('X');
            }
          else
              s.push(matrix[i][j]);
          }
          else if(matrix[i][j] == 'X')
          {
            while(s.getSize() < counter)
              s.push('O');

              s.push('X');
          }
          counter++;  
        }

      while(s.getSize() < counter)
        s.push('O');

      for(int i = row -1; i >=0; i--)
        matrix[i][j] = s.pop();

        counter=0;
      
    }
}

void moveDown(vector<vector<char>> &matrix, size_t row, size_t col) 
{
  Stack s;
  int counter =0;
  char temp;
  for(int j=0;j<col;j++)
  {
      for(int i =row-1;i>=0;i--)
        {
          if(matrix[i][j] != 'O' && matrix[i][j] != 'X')
          {
            if(!s.isEmpty() && s.peek() == 'B')
            {
              temp = s.pop();
              s.push('X');
            }
          else
              s.push(matrix[i][j]);
          }
          else if(matrix[i][j] == 'X')
          {
            while(s.getSize() < counter)
              s.push('O');

              s.push('X');
          }
          counter++;  
        }

      while(s.getSize() < counter)
        s.push('O');

      for(int i=0; i<row; i++)
        matrix[i][j] = s.pop();

        counter=0;
      
    }
}

void moveRight(vector<vector<char>> &matrix, size_t row, size_t col)
{
  Stack s;
  int counter =0;
  char temp;
  
  for(int j=0;j<row;j++)
    {
      for(int i =col-1;i>=0;i--)
        {
          if(matrix[j][i] != 'O' && matrix[j][i] != 'X')
          {
            if(!s.isEmpty() && s.peek() == 'B')
            {
              temp = s.pop();
              s.push('X');
            }
          else
              s.push(matrix[j][i]);
          }
          else if(matrix[j][i] == 'X')
          {
            while(s.getSize() < counter)
              s.push('O');

              s.push('X');
          }
          counter++;  
        }

      while(s.getSize() < counter)
        s.push('O');
        
      for(int i=0; i<col; i++)
        matrix[j][i] = s.pop();

        counter=0;
      
    }
}

void moveLeft(vector<vector<char>> &matrix, size_t row, size_t col)
{
  Stack s;
  int counter =0;
  char temp;
  for(int j=0;j<row;j++)
    {
      for(int i=0;i<col;i++)
        {
          if(matrix[j][i] != 'O' && matrix[j][i] != 'X')
          {
            if(!s.isEmpty() && s.peek() == 'B')
            {
              temp = s.pop();
              s.push('X');
            }
          else
              s.push(matrix[j][i]);
          }
          else if(matrix[j][i] == 'X')
          {
            while(s.getSize() < counter)
              s.push('O');

              s.push('X');
          }
          counter++;  
        }

      while(s.getSize() < counter)
        s.push('O');
        
      for(int i=col-1; i>=0; i--)
        matrix[j][i] = s.pop();

        counter=0;
      
    }
}

void print(vector<vector<char>> &matrix, size_t row, size_t col)
{
  for(size_t i=0;i<row;i++)
    {
      for(size_t j=0;j<col;j++)
        {
          cout << matrix[i][j] << " ";
        }
      cout << endl;
    }
}

void doMoves(Queue &q, Pair t, size_t row, size_t col, string move)
{
  Pair temp;
  temp.matrix = t.matrix;
  temp.moves = t.moves;

  if(move == "1")
  {
    moveUp(temp.matrix,row,col);
    if(temp.matrix != t.matrix)
    {
      temp.moves += "1";
      q.enqueue(temp);
    }
  }

else if(move == "2")
  {
    moveRight(temp.matrix,row,col);
    if(temp.matrix != t.matrix)
    {
      temp.moves += "2";
      q.enqueue(temp);
    }
  }

 else if(move == "3")
  {
    moveDown(temp.matrix,row,col);
    if(temp.matrix != t.matrix)
    {
      temp.moves += "3";
      q.enqueue(temp);
    }
  }

 else if(move == "4")
  {
    moveLeft(temp.matrix, row,col);
    if(temp.matrix != t.matrix)
    {
      temp.moves += "4";
      q.enqueue(temp);
    }
  }
   
}



int main(int argc, char *argv[]) {
  ArgumentManager am(argc, argv);
  string input = am.get("input");
  string output = am.get("output");

  ifstream in(input);
  ofstream out(output);

  size_t row;
  size_t col;
  in >> row; // input row
  in >> col; // input column

  vector<vector<char>> matrix; // input matrix

  // reading the matrix from the input
  
  for (int i = 0; i < row; i++) {
    vector<char> temp;
    for (int j = 0; j < col; j++) {
      char c;
      in >> c;
      temp.push_back(c);
    }
    matrix.push_back(temp);
  }
  
  //Print Original Matrix
  print(matrix, row, col);

  /*
  moveUp(matrix,row,col);
  cout << endl;
  print(matrix,row,col);

  moveDown(matrix,row,col);
  cout << endl;
  print(matrix,row,col);

  moveRight(matrix,row,col);
  cout << endl;
  print(matrix,row,col);
  */

  //Struct Pair has Matrix and a string "moves"
  
  Pair temp;
  temp.matrix = matrix;
  temp.moves ="";

  Queue q;
  q.enqueue(temp);

  while(!q.isEmpty())
    {
      temp = q.dequeue();
      if(isSolved(temp.matrix,row,col))
      {
        if(temp.moves == "")
        {
          out << 0;
          break;
        }
        else
        {
          out << temp.moves; 
          break;
        }
      }
      else        
    { 
      doMoves(q, temp, row, col, "1");
      doMoves(q, temp, row, col, "2");
      doMoves(q, temp, row, col, "3");
      doMoves(q, temp, row, col, "4");
    }  
    }
      
  /* Update compare after shifting temp
else
      {
      Pair compare;
      compare.matrix=  temp.matrix;
      //compare.moves = temp.moves;
        
      moveUp(temp.matrix, row,col);
      if(temp.matrix != compare.matrix)
      {
      temp.moves += "1";
      q.enqueue(temp);
      }
        
      compare.matrix=  temp.matrix;
      moveRight(temp.matrix, row,col);
      if(temp.matrix != compare.matrix)
      {
      temp.moves += "2";
      q.enqueue(temp);
      }
        
      compare.matrix=  temp.matrix;
        
      moveDown(temp.matrix,row,col);
      if(temp.matrix != compare.matrix)
      {
      temp.moves += "3";
      q.enqueue(temp);
      }
        
      compare.matrix=  temp.matrix;
      moveLeft(temp.matrix, row,col);
      if(temp.matrix != compare.matrix)
      {
      temp.moves += "4";
      q.enqueue(temp);
      }
      compare.matrix=  temp.matrix;
      }
*/
  



  return 0;
}
