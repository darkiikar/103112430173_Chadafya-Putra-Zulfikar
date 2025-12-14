#include <iostream>
#include "mll.h"

void buildSample(MultiLL &m) {
	m.addParent("G001", "Aves");
	m.addChildToParent("G001", "AV001", "Cendrawasih", "Hutan", 1, 0.3);
	m.addChildToParent("G001", "AV002", "Bebek", "Air", 1, 2);

	m.addParent("G002", "Mamalia");
	m.addChildToParent("G002", "M001", "Harimau", "Hutan", 1, 200);
	m.addChildToParent("G002", "M003", "Gorila", "Hutan", 0, 160);
	m.addChildToParent("G002", "M002", "Kucing", "Darat", 1, 4);

	m.addParent("G003", "Pisces");

	m.addParent("G004", "Amfibi");
	m.addChildToParent("G004", "AM001", "Kodok", "Sawah", 0, 0.2);

	m.addParent("G005", "Reptil");
}

int main() {
	MultiLL m;
	buildSample(m);

	std::string pid, pname;
	int ppos, cpos;
	Child found("", "", "", 0, 0.0);

	if (m.findChild("M003", pid, pname, ppos, cpos, found)) {
		std::cout << "Data ditemukan pada list anak dari node parent " << pname << " pada posisi ke-" << cpos << "!" << std::endl;
		std::cout << "---- Data Child ----" << std::endl;
		std::cout << "ID Child : " << found.id << std::endl;
		std::cout << "Posisi dalam list anak : posisi ke-" << cpos << std::endl;
		std::cout << "Nama Hewan : " << found.name << std::endl;
		std::cout << "Habitat : " << found.habitat << std::endl;
		std::cout << "Ekor : " << found.ekor << std::endl;
		std::cout << "Bobot : " << found.bobot << std::endl;
		std::cout << "-----------------------" << std::endl;
		std::cout << "--- Data Parent ---" << std::endl;
		std::cout << "ID Parent : " << pid << std::endl;
		std::cout << "Posisi dalam list induk : posisi ke-" << ppos << std::endl;
		std::cout << "Nama golongan : " << pname << std::endl;
		std::cout << "-----------------------" << std::endl;
	}

	if (m.findChild("AM001", pid, pname, ppos, cpos, found)) {
		std::cout << "Data ditemukan pada list anak dari node parent " << pname << " pada posisi ke-" << cpos << "!" << std::endl;
		std::cout << "--- Data Child ---" << std::endl;
		std::cout << "ID Child : " << found.id << std::endl;
		std::cout << "Posisi dalam list induk : posisi ke-" << cpos << std::endl;
		std::cout << "Nama Hewan : " << found.name << std::endl;
		std::cout << "Habitat : " << found.habitat << std::endl;
		std::cout << "Ekor : " << found.ekor << std::endl;
		std::cout << "Bobot : " << found.bobot << std::endl;
		std::cout << "-----------------------" << std::endl;
		std::cout << "--- Data Parent ---" << std::endl;
		std::cout << "ID Parent : " << pid << std::endl;
		std::cout << "Posisi dalam list induk : posisi ke-" << ppos << std::endl;
		std::cout << "Nama golongan : " << pname << std::endl;
	}

	return 0;
}