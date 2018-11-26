#include <iostream>

class Szulo {

public:
		
	void szuloUzenet() {
		std::cout << "szuloUzenet()" << std::endl; 	
	}		


};

class Gyerek: public Szulo {

public:
	void gyerekUzenet() {
		std::cout << "gyerekUzenet()" << std::endl;
	}

};


int main() {
	Szulo* szulo = new Gyerek();
	szulo->szuloUzenet();
	szulo->gyerekUzenet();
	delete szulo;
	return 0;
}
