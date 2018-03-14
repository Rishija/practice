#include "btree.h"

template<class T>
void Btree<T>::print_vertical() {
    
    map<int, vector<Node*> > collection;
    print_vertical(root, 0, collection);
    
    cout << "** With preorder **" <<endl;
    for(auto element : collection) {
        for(Node* node : element.second) {
            cout << node -> val << " ";
        }
        cout << endl;
    }
    cout << endl << "** With level order **" << endl;
    
    
    /* using level order traversal */
    
    vector<tuple<Node*, int> > items;
    queue<tuple<Node*, int> >queue;
    tuple<Node*, int> current;
    
    if(root != nullptr)
        queue.push({root, 0});
    
    while(!queue.empty()) {
        current = queue.front();
        queue.pop();
        items.push_back(current);
        
        if(get<0>(current) -> left != nullptr)
            queue.push( {get<0>(current) -> left, get<1>(current) - 1} );
        
        if(get<0>(current) -> right != nullptr)
            queue.push( {get<0>(current) -> right, get<1>(current) + 1} );
    }
    
    stable_sort(items.begin(), items.end(), [] (const tuple<Node*, int> &a, const tuple<Node*, int> &b) {
        return get<1>(a) < get<1>(b);
    });
    
    //    for(typename vector<tuple<Node*, int> >::iterator elem = items.begin(); elem != items.end(); ++elem) {
    for(auto elem = items.begin(); elem != items.end(); ++elem) {
        int currentWeight = get<1>(*elem);
        while(get<1>(*elem) == currentWeight) {
            cout << get<0>(*elem) -> val << " ";
            ++ elem;
        }
        -- elem;
        cout << endl;
    }
}

template<class T>
void Btree<T>::print_vertical(Node* node, int weight, map<int, vector<Node*> > &collection) {
    if(node == nullptr)
        return;
    
    collection[weight].push_back(node);
    
    print_vertical(node -> left, weight - 1, collection);
    print_vertical(node -> right, weight + 1, collection);
}

int main() {
    Btree<int>tree;
    tree.insert(5);
    tree.insert(2);
    tree.insert(10);
    tree.insert(1);
    tree.insert(3);
    tree.insert(8);
    tree.insert(4);
    tree.insert(7);
    tree.insert(6);
    tree.insert(20);
    tree.print_levelOrder();
    cout << endl;
    tree.print_vertical();
    return 0;
}
