/*  I pledge my Honor that I have abided by the Stevens Honor System. - James Lawrence, Hayden Daly, Roman Bellisari  */

#include <iostream>

struct Matrix
{
  float **data;
  unsigned height;
  unsigned width;

  Matrix(unsigned width_)
  {
    height = 1;
    width = width_;

    float **array2D = 0;
    array2D = new float *[1];

    for (int l = 0; l < width; l++)
    {
      array2D[1][l] = 0; // fill initial values
    }

    data = array2D;
  }

  Matrix(unsigned height_, unsigned width_)
  {
    height = height_;
    width = width_;

    float **array2D = 0;
    array2D = new float *[height];

    for (int h = 0; h < height; h++)
    {
      array2D[h] = new float[width];

      for (int w = 0; w < width; w++)
      {
        array2D[h][w] = 0; // fill initial values
      }
    }
    data = array2D;
  }

  ~Matrix()
  {
    height = 0;
    width = 0;

    if (data)
      delete[] data;
    data = 0;
  }

  friend Matrix operator*(Matrix A, Matrix B)
  {
    // Using A.height as equivalent for n in multiply Matrices method
    Matrix result = Matrix(A.height, A.height);
    float dot;

    // Squaring matrix and storing in multiplied.
    for (int k = 0; k < A.height; k++)
    {
      for (int j = 0; j < A.height; j++)
      {
        dot = 0;
        for (int i = 0; i < A.height; i++)
          dot += A.data[k][i] * B.data[i][j];
        result.data[k][j] = dot;
      }
    }
    return result;
  }
};

// Return pointer to 2D array with dimensions [height x width]
float **create2DArray(unsigned height, unsigned width)
{
  float **array2D = 0;
  array2D = new float *[height];

  for (int h = 0; h < height; h++)
  {
    array2D[h] = new float[width];

    for (int w = 0; w < width; w++)
    {
      array2D[h][w] = 0; // fill initial values
    }
  }

  return array2D;
}

float *create1DArray(unsigned length)
{
  float *array1D = 0;
  array1D = new float[length];

  for (int l = 0; l < length; l++)
  {
    array1D[l] = 0; // fill initial values
  }

  return array1D;
}

float **multiplyMatrix(float **arr1, float **arr2, int n)
{
  float **multiplied = create2DArray(n, n);
  float dot;

  // Squaring matrix and storing in multiplied.
  for (int k = 0; k < n; k++)
  {
    for (int j = 0; j < n; j++)
    {
      dot = 0;
      for (int i = 0; i < n; i++)
      {
        dot += arr1[k][i] * arr2[i][j];
      }
      multiplied[k][j] = dot;
    }
  }

  return multiplied;
}

int main()
{

  /*
  Input:

  N

    . . .
  . 
  .  NXN (A)
  .

  N (B)
  .
  .
  .
*/
  // Read from input file
  std::freopen("./matrix.dat", "r", stdin);
  int n;
  std::cin >> n;
  float **A = create2DArray(n, n);
  float *B = create1DArray(n);
  float x;

  // Read in array A
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      std::cin >> x;
      A[i][j] = x;
    }
  }

  // Print out A
  std::cout << "A:" << std::endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      std::cout << (A[i][j]) << "  ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  // Read in array B
  for (int i = 0; i < n; i++)
  {
    std::cin >> x;
    B[i] = x;
  }

  // Print out B
  std::cout << "B:" << std::endl;
  for (int i = 0; i < n; i++)
  {
    std::cout << (B[i]) << std::endl;
  }
  std::cout << std::endl;

  // A^2 and A^3
  float **A_squared = create2DArray(n, n);
  float **A_cubed = create2DArray(n, n);

  A_squared = multiplyMatrix(A, A, n);
  std::cout << "A^2:" << std::endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      std::cout << (A_squared[i][j]) << "  ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  A_cubed = multiplyMatrix(A_squared, A, n);
  std::cout << "A^3:" << std::endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      std::cout << (A_cubed[i][j]) << "  ";
    }
    std::cout << std::endl;
  }

  // Clean up memory
  for (int i = 0; i < n; i++)
  {
    delete[] A[i], A_squared[i], A_cubed[i];
  }
  delete[] A, A_squared, A_cubed, B;
  A = 0;
  A_squared = 0;
  A_cubed = 0;
  B = 0;

  return 0;
}