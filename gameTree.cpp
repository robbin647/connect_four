#include<iostream>

class status {
public:
	int blank = 42;
	int getPossibleMoves() {
		return blank;
	}
	int outcome() {
		return 1;
	}
};

class node {
public:
	int value;
	int level;
	status* s = NULL;
	node* nsibling = NULL;
	node* fchild = NULL;
	node(status* s, int l) {
		this->s = s;
		level = l;
	}
};

class tree {
public:
	node* roof = new node(new status(), 0);
	void generateTree(node* n) {
		if (n->s->getPossibleMoves() == 0) {
			n->value = n->s->outcome();
			return;
		}
		else {
			n->fchild = new node(new status(), n->level + 1);
			node* tmp = n->fchild;
			for (int i = 0; i < n->s->getPossibleMoves() - 1; i++) {
				generateTree(tmp);
				if (i != n->s->getPossibleMoves() - 2) {
					tmp->nsibling = new node(new status(), n->level + 1);
					tmp = tmp->nsibling;
				}
			}
			n->value = generateValue(n);
		}
	}
	int generateValue(node* n) {
		int min = 1;
		int max = -1;
		node* tmp = n->fchild;
		while (tmp != NULL) {
			if (tmp->value > max) {
				max = tmp->value;
			}
			else if (tmp->value < min) {
				min = tmp->value;
			}
			tmp = tmp->nsibling;
		}
		if (n->level % 2 == 0) {
			return max;
		}
		else {
			return min;
		}
	}
};
