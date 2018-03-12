#include "btree.h"

template<class T>
void Btree<T>::diameter() {
	cout << "Diameter: " << diameter(root).first << endl
	<< "height of tree: " << diameter(root).second << endl;
}

template<class T>
pair<T,T> Btree<T>::diameter(Node* node) {
	if(node == nullptr)
		return make_pair(0,0);

	pair<T,T> lAns = diameter(node -> left),
	rAns = diameter(node -> right),
	thisAns;

	T diameterHere = lAns.second + rAns.second + 1, max;

	if(diameterHere > lAns.first) {
		if(diameterHere > rAns.first)
			max = diameterHere;
		else
			max = rAns.first;
	}
	else if(lAns.first > rAns.first) {
		max = lAns.first;
	}
	else {
		max = rAns.first;
	}

	thisAns = make_pair(max, (lAns.second > rAns.second ? lAns.second : rAns.second) + 1);
	return thisAns;
}

template<class T>
int Btree<T>::diameter_simple() {
    int diam = 0;
    diameter_simple(root, diam);
    return diam;
}

template<class T>
int Btree<T>::diameter_simple(Node* node, int &diam) {
    
    if(node == nullptr)
        return 0;
    
    int left = diameter_simple(node -> left, diam),
    right = diameter_simple(node -> right, diam);
    
    if(diam < 1 + left + right)
        diam = 1 + left + right;
    
    return 1 + ( left > right ? left : right );
}

int main() {
    Btree<int>tree;
    tree.insert(87);
    tree.insert(34);
    tree.insert(64);
    tree.insert(12);
    tree.insert(673);
    tree.insert(98);
    tree.insert(33);
    tree.insert(1);
    tree.insert(39);
    tree.insert(90);
    tree.insert(101);
    tree.insert(147);
    tree.insert(13);
    tree.insert(48);
    tree.insert(61);
    tree.insert(82);
    tree.insert(17);
    tree.insert(537);
    tree.insert(1006);
    tree.insert(289);
    tree.insert(27);
    tree.print_levelOrder();
    cout << endl;
    tree.diameter();
    cout << endl << "With second method: " << tree.diameter_simple() << endl;
    return 0;
}
