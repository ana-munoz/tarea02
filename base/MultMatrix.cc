#include <MultMatrix.hh>

/////////////////////////////////////////////////////////////////////////////////
//  Identificación del alumno
//
//  Nombre Completo: Ana Poulette Nicole Muñoz Fuentes
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//
//   Description:
//           -->Completar la descripción
//
/////////////////////////////////////////////////////////////////////////////////



void MultMatrix::DOijk(const Matrix<float>& A,const Matrix<float>& B, Matrix<float>& C)
{
	//Completar
	for(size_t i=0; i<filas(A); i++){
		for(size_t j=0; j<columnas(B); j++){
			for(size_t k=0; k<columnas(A); k++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}


void MultMatrix::DOkij(const Matrix<float>& A,const Matrix<float>& B, Matrix<float>& C)
{
	//Completar
	for(size_t k=0; k<columnas(A); k++){
		float r = A[i][k];
		for(size_t j=0; j<columnas(B); j++){
			C[i][j] = r * B[k][j];
		}
	}
}

