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



void MultMatrix::DOijk(Matrix<float>& A, Matrix<float>& B, Matrix<float>& C)
{
	//Completar
	
	for(size_t i=0; i < A.rows(); i++){
		for(size_t j=0; j < B.cols(); j++){
			for(size_t k=0; k < A.cols(); k++){
				float value = A.value(i,k) * B.value(k,j); 
				C.value(i,j,value);
			}
		}
	}
}


void MultMatrix::DOkij(Matrix<float>& A, Matrix<float>& B, Matrix<float>& C)
{
	//Completar
	for(size_t k=0; k < A.cols(); k++){
		for(size_t i=0; i< A.rows(); i++){
			float r = A.value(i,k);
			for(size_t j=0; j< B.cols(); j++){
				float value = r * B.value(k,j);
				C.value(i,j,value);
			}
		}
	}
}

