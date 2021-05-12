#pragma once
#include<vector>
namespace DSA
{

    class Matrix
    {
        private:
            int row;
            int column;
            std::vector<int> matrix;
            bool is_valid;
        public:
            static int No_Objects;
            Matrix():row(0),column(0),matrix({}),is_valid(false){}
            Matrix(int,int,std::vector<int>);
            ~Matrix();
            //Getters
            int getRow() const;
            int getColumn() const;
            void print()const ;
            int get(int,int) const;
            //Setters
            std::vector<int> getMatrix() const ;
            //Checkers
            bool is_multiplicable(Matrix&) const;
            //operators
            Matrix operator*(Matrix&) const;
            void operator=(Matrix) ;
            Matrix operator^(int) const;
    };
    int Matrix::No_Objects=0;
}
