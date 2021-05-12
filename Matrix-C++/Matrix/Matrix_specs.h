#pragma once
#include<iostream>
#include<vector>
#include "Class_Matrix.h"
namespace DSA
{
    Matrix::Matrix(int r,int c,std::vector<int> arr):row(r),column(c),is_valid(false)
    {
        this->matrix=arr;
        Matrix::No_Objects+=1;
        if(this->matrix.size()==(r*c))
            this->is_valid=true;
        else
            this->is_valid=false;
    }
    Matrix::~Matrix()
    {
        Matrix::No_Objects-=1;
       this->row=0;
       this->column=0;
       this->matrix.clear();
    }
    int Matrix::getRow() const
    {
        return this->row;
    }
    int Matrix::getColumn() const
    {
        return this->column;
    }

    void Matrix::print() const
    {
        if(this->is_valid)
            for(int i=0;i<this->row;i++)
            {
                for(int j=0;j<this->column;j++)
                    std::cout<<this->matrix[i*column+j]<<"\t";
                    std::cout<<std::endl;
            }
    }       
    bool Matrix::is_multiplicable(Matrix& second) const
    {
        return (this->column==second.getRow());
    }
    int Matrix::get(int r,int c) const
    {
        return this->matrix[r*this->column+c];   
    }
    Matrix Matrix::operator*(Matrix& B) const
    {
        std::vector<int> result;
        int sum;
        for(int row=0;row<this->row;row++)
            for(int i=0;i<B.column;i++)
            {
                sum=0;
                for(int j=0;j<this->column;j++)
                    sum+=this->get(row,j)*B.get(j,i);
                result.push_back(sum);
            }
        
        return {this->column,B.getRow(),result};
    }
    std::vector<int> Matrix::getMatrix() const
    {
        return this->matrix;
    }
    void Matrix::operator=(Matrix B)
    {
        this->~Matrix();
        this->column=B.getColumn();
        this->row=B.getRow();
        this->matrix=B.getMatrix();
        this->is_valid=true;
    }

    Matrix Matrix::operator^(int power) const
    {
        auto result=*this;
        for(int i=1;i<power;i++)
            result=*this*result;

        return result;
    }
}