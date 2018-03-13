// Print level wise but every level reverse the order.. left to right, then next level right to left. and so on

#include "btree.h"

template<class T>
void Btree<T>::alt_level_order() {
    
    if(root == nullptr)
        return;
    
    deque<Node*>myQueue;
    myQueue.push_back(root);
    alt_level_order(myQueue, 1);
}

/**
 * Time complexity : O(n)
 * Space complexity : O(n)      ( O(n) auxilliary space + O(height) in stack area )
 */
template<class T>
void Btree<T>::alt_level_order(deque<Node*> inQueue, bool level){
    
    if(!inQueue.size()) return;
    
    deque<Node*> outQueue, dupQueue(inQueue);
    while(inQueue.size() > 0){
        Node *printNode, *thisNode = inQueue.front();
        
        if(!level) {
            printNode = dupQueue.back();
            dupQueue.pop_back();
        }
        else {
            printNode = dupQueue.front();
            dupQueue.pop_front();
        }
        
        cout << printNode -> val << " ";
        if(thisNode -> left != nullptr)
            outQueue.push_back(thisNode -> left);
        
        if(thisNode -> right != nullptr)
            outQueue.push_back(thisNode -> right);
        
        inQueue.pop_front();
        
    }
    cout << endl;
    alt_level_order(outQueue, !level);
}

/**
 * Time complexity : O(n)
 * Space complexity : O(n)
 */
template<class T>
void Btree<T>::alt_level_order_stack() {
    
    stack<Node*>stack1, stack2;
    if(root != nullptr)
        stack1.push(root);
    
    bool flag = true;
    
    while(!stack1.empty()) {
        while (!stack1.empty()) {
            Node* thisNode = stack1.top();
            stack1.pop();
            cout << thisNode -> val << " ";
            
            if(flag) {
                if(thisNode -> left != nullptr)
                    stack2.push(thisNode -> left);
                if(thisNode -> right != nullptr)
                    stack2.push(thisNode -> right);
            }
            else {
                if(thisNode -> right != nullptr)
                    stack2.push(thisNode -> right);
                if(thisNode -> left != nullptr)
                    stack2.push(thisNode -> left);
            }
        }
        cout << endl;
        
        stack1 = stack2;
        while(!stack2.empty())
            stack2.pop();
        
        flag = !flag;
    }
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
    cout<<endl;
    tree.alt_level_order();
    cout << endl;
    tree.alt_level_order_stack();
    return 0;
}
