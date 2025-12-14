#include <iostream>
#include "mll.h"

int main() {
	MultiLL m;
	m.addParent("G001", "Aves");
	m.addChildToParent("G001", "AV001", "Cendrawasih", "Hutan", 1, 0.3);
	m.addChildToParent("G001", "AV002", "Bebek", "Air", 1, 2);

	m.addParent("G002", "Mamalia");
	m.addChildToParent("G002", "M001", "Harimau", "Hutan", 1, 200);
	m.addChildToParent("G002", "M003", "Gorila", "Hutan", 0, 160);
	m.addChildToParent("G002", "M002", "Kucing", "Darat", 1, 4);

	m.addParent("G003", "Pisces");

	m.addParent("G004", "Amfibi");

	m.printAll();
	return 0;
}