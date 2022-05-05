#pragma once

/////////////////////////////////////////////////////////////////////////////////
//  Identificación del alumno
//
//  Nombre Completo:  Ana Poulette Nicole Muñoz Fuentes
/////////////////////////////////////////////////////////////////////////////////

#include <global.hh>
#include <Matrix.hpp>

class MultMatrix
{
private:
	//Todas las variables privadas deben comenzar con _


public:
	MultMatrix(){}
	~MultMatrix(){}
	
	void DOijk(Matrix<float>& A, Matrix<float>& B, Matrix<float>& C);
	void DOkij(Matrix<float>& A, Matrix<float>& B, Matrix<float>& C);

};



