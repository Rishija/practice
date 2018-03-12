#include "btree.h"

template<class T>
void Btree<T>::even_odd_levelSum() {
    pair<T,T> pair= {0,0};
    queue<Node*>myQueue;
    myQueue.push(root);
    even_odd_levelSum(pair, myQueue, 1);
    cout << "Sum of nodes at odd level: " << pair.first << endl
    << "Sum of nodes at even level: " << pair.second <<endl;
}

template<class T>
void Btree<T>::even_odd_levelSum(pair<T,T> &pair, queue<Node*> inQueue, bool level){
    
    if(!inQueue.size()) return;
    
    queue<Node*> outQueue;
    while(inQueue.size() > 0){
        Node* thisNode = inQueue.front();
        level ? pair.first += thisNode -> val : pair.second += thisNode -> val;
        if(thisNode -> left != nullptr)
            outQueue.push(thisNode -> left);
        if(thisNode -> right != nullptr)
            outQueue.push(thisNode -> right);
        inQueue.pop();
    }
    even_odd_levelSum(pair, outQueue, !level);
}


// call it even_odd_levelSum(node, pair, 0);
template<class T>
void Btree<T>::even_odd_levelSum(Node* node, int[2] pair, int level){
   
    if(node == null)
        return;
    pair[level %2] = node -> val;
    
    even_odd_levelSum(node -> left, pair, level + 1);
    even_odd_levelSum(node -> right, pair, level + 1);
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
    tree.even_odd_levelSum();
    return 0;
}

