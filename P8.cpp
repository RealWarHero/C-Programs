#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class matrix{
    private:
    vector<vector<int>> data;
    size_t rows;
    size_t cols;

    public:
        matrix(size_t rows , size_t cols) : rows(rows) , cols(cols){
            data.resize(rows,vector<int>(cols,0));
        }
        matrix(const vector<vector<int>>& matrix) : data(matrix) , rows(matrix.size()) , cols(matrix[0].size()){}
        size_t numrows() const {
            return rows;
        }
        size_t numcols() const {
            return cols;
        }
        int& at(size_t row , size_t col){
            if (row>=rows || col>=cols)
            {
                throw out_of_range("Index out of range");
            }
            return data[row][col];
        }
        const int& at(size_t row , size_t col) const {
            if (row>=rows || col>=cols)
            {
                throw out_of_range("Index out of range");
            }
            return data[row][col];
        }
        matrix operator+(const matrix& other) const {
            if (rows!=other.rows || cols!=other.cols)
            {
                throw invalid_argument("Matrices must have the same dimensions for addition");
            }
            matrix result(rows,cols);
            for (size_t i = 0; i < rows; i++)
            {
                for (size_t j = 0; j < cols; j++)
                {
                    result.data[i][j] = data[i][j] + other.data[i][j];
                } 
            }
            return result;
        }
        matrix operator*(const matrix& other) const {
            if (cols!=other.rows)
            {
                throw invalid_argument("Number of columns in the first matrix should be equal to the number of rows in the second matrix for multiplication");
            }
            matrix result(rows,other.cols);
            for (size_t i = 0; i < rows; i++)
            {
                for (size_t j = 0; j < other.cols; j++)
                {
                    for (size_t k = 0; k < cols; k++)
                    {
                        result.data[i][j] += data[i][k] * other.data[k][j];
                    }
                }
            }
            return result;
        }
        matrix transpose() const{
            matrix result(cols , rows);
            for (size_t i = 0; i < rows; i++)
            {
                for (size_t j = 0; j < cols; j++)
                {
                    result.data[j][i] = data[i][j];
                } 
            }
            return result;
        }
};

void displaymatrix(const matrix& matrix){
    for (size_t i = 0; i < matrix.numrows(); i++)
    {
        for (size_t j = 0; j < matrix.numcols(); j++)
        {
            cout<<matrix.at(i,j)<<" ";
        }
        cout<<endl;
    } 
}

int main(){
    try
    {
        size_t rows,cols;
        cout<<"Enter the number of rows and columns of 1st matrix : ";
        cin>>rows>>cols;
        matrix m1(rows,cols);
        cout<<"Enter the elements of 1st matrix : \n";
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                cin>>m1.at(i,j);
            }
        }
        cout<<"Enter the number of rows and columns of 2nd matrix : ";
        cin>>rows>>cols;
        matrix m2(rows,cols);
        cout<<"Enter the elements of 2nd matrix : \n";
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                cin>>m2.at(i,j);
            }
        }
        int choice;
        cout<<"\nMenu: \n";
        cout<<"1.Sum\n";
        cout<<"2.Product\n";
        cout<<"3.Transpose\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            try
            {
                matrix sum = m1 + m2;
                cout<<"\nSum of matrices is : \n";
                displaymatrix(sum);
            }
            catch(const exception& e)
            {
                cerr<<"Error: " << e.what() << '\n';
            }
            break;
        case 2:
            try
            {
                matrix product = m1 * m2;
                cout<<"\nProduct of matrices is: \n";
                displaymatrix(product);
            }
            catch(const exception& e)
            {
                cerr << e.what() << '\n';
            }
            break;
        case 3:
            try
            {
                matrix transposed = m1.transpose();
                matrix trans = m2.transpose();
                cout<<"\nTranspose of 1st matrix is :\n";
                displaymatrix(transposed);
                cout<<"\nTranspose of 2nd matrix is :\n";
                displaymatrix(trans);
            }
            catch(const exception& e)
            {
                cerr<<"Error: " << e.what() << '\n';
            }
            break;
        default:
            cerr<<"Invalid choice\n";
            break;
        }
    }
    catch(const exception& e)
    {
        cerr<<"Error : "<< e.what() << '\n';
    }
    
    return 0;
}