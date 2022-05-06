#include <global.hh>

#include <Timer.hpp>
#include <Matrix.hpp>

#include <MultMatrix.hh>

/////////////////////////////////////////////////////////////////////////////////
//  Identificación del alumno
//
// Nombre Completo: Ana Poulette Nicole Muñoz Fuentes
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//   Usage:
//           ./matrixMult --matrix matrix_file
//
//   Description:
//           -->Completar la descripción
//
/////////////////////////////////////////////////////////////////////////////////

void uso(std::string pname)
{
	std::cerr << "Uso: " << pname << " --matrix MATRIX_FILE" << std::endl;
}

int main(int argc, char** argv)
{

	Timer<std::chrono::nanoseconds> timer1;
	Timer<std::chrono::nanoseconds> timer2;
	Timer<std::chrono::nanoseconds> timer3;

	std::string fileMatrixA;

	///////////////////////////////////////
	//  Read command-line parameters
	if(argc != 3){
		uso(argv[0]);
		exit(EXIT_FAILURE);
	}
	std::string mystr;
	for (size_t i=0; i < argc; i++) {
		mystr=argv[i];
		if (mystr == "--matrix") {
			fileMatrixA = argv[i+1];
		}
	}

	if(fileMatrixA == ""){
		uso(argv[0]);
		exit(EXIT_FAILURE);
	}

	Matrix<float> m1(fileMatrixA, " ");
	Matrix<float> m2(fileMatrixA, " ");
	timer1.start();
	try{
		m1.load();
	} catch(std::exception& e){
		std::cerr << e.what() <<std::endl;
		exit(EXIT_FAILURE);
	}
	timer1.stop();
	std::cout << "Time to load matrix in memory: " << timer1.elapsed() << " ns\n";
	try{
		m2.load();
	} catch(std::exception& e){
		std::cerr << e.what() <<std::endl;
		exit(EXIT_FAILURE);
	}
/*	for(size_t i=0; i< m1.rows(); i++){
		for(size_t j=0; j< m1.cols(); j++){
			std::cout << m1(i,j) << "\t";
		}
		std::cout << std::endl;
	}
*/

	// Ejemplo de creación de matrix vacía
	MultMatrix mm;
	timer2.start();
	Matrix<float> C(m1.rows(), m1.cols());

	//Ejemplo de llamada al método del algoritmo ijk
	mm.DOijk(m1, m1, C);
	timer2.stop();

        std::cout << "Timer DOijk: " << timer2.elapsed() << " ns\n";
	//std::cout << "DOIJK" << std::endl;
	/*for(size_t i=0; i<C.rows(); i++){
		for(size_t j=0;j<C.cols();j++){
			std::cout << C(i,j) << "\t";
		}
		std::cout << std::endl;
	}*/
	//std::cout << std::endl;
	//std::cout << "DOKIJ";
	//std::cout << std::endl;
	/*for(size_t i=0; i<C.rows();i++){
		for(size_t j=0; j<C.cols(); j++){
			C.value(i,j,0);
			std::cout << C(i,j) << "\t";
		}
		std::cout << std::endl;
	}*/

	timer3.start();
	mm.DOkij(m1, m1, C);
	timer3.stop();

        std::cout << "Timer DOkij: " << timer3.elapsed() << " ns\n";

	/*for(size_t i=0; i < C.rows(); i++){
		for(size_t j=0; j < C.cols(); j++){
			std::cout << C(i,j) << "\t";
		}
		std::cout << std::endl;
	}*/


	return(EXIT_SUCCESS);
}


