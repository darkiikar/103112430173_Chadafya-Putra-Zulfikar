#ifndef MLL_H
#define MLL_H

#include <string>

struct Child {
	std::string id;
	std::string name;
	std::string habitat;
	int ekor;
	double bobot;
	Child* next;
	Child(const std::string &i, const std::string &n, const std::string &h, int e, double b) : id(i), name(n), habitat(h), ekor(e), bobot(b), next(nullptr) {}
};

struct Parent {
	std::string id;
	std::string name;
	Parent* next;
	Child* child;
	Parent(const std::string &i, const std::string &n) : id(i), name(n), next(nullptr), child(nullptr) {}
};

class MultiLL {
public:
	MultiLL();
	~MultiLL();
	void addParent(const std::string &id, const std::string &name);
	void addChildToParent(const std::string &parentId, const std::string &cid, const std::string &cname, const std::string &habitat, int ekor, double bobot);
	bool findChild(const std::string &childId, std::string &outParentId, std::string &outParentName, int &parentPos, int &childPos, Child &outChild) const;
	void printAll() const;
private:
	Parent* head;
	void clear();
};

#endif
