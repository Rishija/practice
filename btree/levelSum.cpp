#include "btree.h"

template<class T>
void Btree<T>::level_sum() {
    
    if(root == nullptr)
        return;
    
    queue<Node*> myQueue;
    myQueue.push(root);
    level_sum(myQueue, 1);
}

template<class T>
void Btree<T>::level_sum(queue<Node*> inQueue, int level) {
    
    if(!inQueue.size()) return;
    T sum = 0;
    
    queue<Node*> outQueue;
    while(inQueue.size() > 0){
        Node* thisNode = inQueue.front();
        sum += thisNode -> val;
        if(thisNode -> left != nullptr)
            outQueue.push(thisNode -> left);
        if(thisNode -> right != nullptr)
            outQueue.push(thisNode -> right);
        inQueue.pop();
    }
    cout << "Sum at level " << level << ":\t" << sum << endl;
    level_sum(outQueue, level + 1);
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
    tree.level_sum();
    return 0;
}
