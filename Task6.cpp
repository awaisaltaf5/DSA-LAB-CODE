#include <iostream>
using namespace std;

int main() {
    int m, n, p, q;
    
    // Taking the dimensions of the first matrix
    cout << "Enter number of rows and columns of first matrix: ";
    cin >> m >> n;

    // Taking the dimensions of the second matrix
    cout << "Enter number of rows and columns of second matrix: ";
    cin >> p >> q;

    // Check if addition and multiplication are possible
    if (m != p || n != q) {
        cout << "Matrix addition is not possible. Both matrices must have the same dimensions.";
        return 0;
    }
    if (n != p) {
        cout << "Matrix multiplication is not possible. Number of columns of first matrix must be equal to number of rows of second matrix.";
        return 0;
    }

    // Declaring matrices
    int matrix1[m][n], matrix2[p][q], result[m][q], sum[m][n];

    // Taking input for the first matrix
    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix1[i][j];
        }
    }

    // Taking input for the second matrix
    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cin >> matrix2[i][j];
        }
    }

    

    
    int num;
    cout<<"\nPress 1 for Addition and Press 2 for Multiplication:";
    cin>>num;
    if(num==1){
        // Initializing the sum matrix to zero for addition
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i][j] = 0;
        }
    }
    
// Matrix Addition
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
     // Displaying the result of matrix addition
     cout << "\nResultant matrix after addition:\n";
     for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
             cout << sum[i][j] << " ";
         }
         cout << endl;
     }
}
else if(num==2){
        // Initializing the result matrix for multiplication to zero
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < q; j++) {
                result[i][j] = 0;
            }
        }

    // Performing matrix multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    // Displaying the result of matrix multiplication
    cout << "\nResultant matrix after multiplication:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
else{
    cout<<"\nInvalid Input!";
}

   

    

    return 0;
}
