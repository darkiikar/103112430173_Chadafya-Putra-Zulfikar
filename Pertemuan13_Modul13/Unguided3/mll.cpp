#include "mll.h"
#include <iostream>

MultiLL::MultiLL() : head(nullptr) {}

MultiLL::~MultiLL() { clear(); }

void MultiLL::addParent(const std::string &id, const std::string &name) {
	Parent* p = new Parent(id, name);
	if (!head) head = p;
	else {
		Parent* cur = head;
		while (cur->next) cur = cur->next;
		cur->next = p;
	}
}

void MultiLL::addChildToParent(const std::string &parentId, const std::string &cid, const std::string &cname, const std::string &habitat, int ekor, double bobot) {
	Parent* cur = head;
	while (cur) {
		if (cur->id == parentId) {
			Child* c = new Child(cid, cname, habitat, ekor, bobot);
			if (!cur->child) cur->child = c;
			else {
				Child* cc = cur->child;
				while (cc->next) cc = cc->next;
				cc->next = c;
			}
			return;
		}
		cur = cur->next;
	}
}

void MultiLL::printAll() const {
	const Parent* p = head;
	int pidx = 1;
	while (p) {
		std::cout << "=== Parent " << pidx << " ===" << std::endl;
		std::cout << "ID Golongan : " << p->id << std::endl;
		std::cout << "Nama Golongan : " << p->name << std::endl;
		if (!p->child) {
			std::cout << "(tidak ada child)" << std::endl;
		} else {
			const Child* c = p->child;
			int cidx = 1;
			while (c) {
				std::cout << " - Child " << cidx << " :" << std::endl;
				std::cout << "ID Hewan : " << c->id << std::endl;
				std::cout << "Nama Hewan : " << c->name << std::endl;
				std::cout << "Habitat : " << c->habitat << std::endl;
				std::cout << "Ekor : " << c->ekor << std::endl;
				std::cout << "Bobot : " << c->bobot << std::endl;
				c = c->next;
				cidx++;
			}
		}
		std::cout << "-------------------------------" << std::endl;
		p = p->next;
		pidx++;
	}
}

void MultiLL::clear() {
	Parent* p = head;
	while (p) {
		Child* c = p->child;
		while (c) {
			Child* nc = c->next;
			delete c;
			c = nc;
		}
		Parent* np = p->next;
		delete p;
		p = np;
	}
	head = nullptr;
}
