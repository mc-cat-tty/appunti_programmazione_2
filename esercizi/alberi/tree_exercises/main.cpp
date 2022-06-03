#include <iostream>
#include <string.h>
#include "tree_module/tree.h"
#include "tree_module/type.h"

using namespace std;

void debug_print(tree root) {
    #ifdef DEBUG
    // print(root->inf); cout << endl;
    // print(root->first_child->inf); cout << " ";
    // print(root->first_child->next_sibling->inf); cout << " ";
    // print(root->first_child->next_sibling->next_sibling->inf); cout << endl;
    // print(root->first_child->next_sibling->first_child->inf); cout << endl;
    cout << serialize(root) << endl;
    cout << depth(root) << endl;
    #endif
}

int main() {
    tree root = new_node("Luca");

    node* paolo = new_node("Paolo");
    node* marco = new_node("Marco");
    node* anna = new_node("Anna");
    node* lucia = new_node("Lucia");

    insert_child(root, paolo);
    insert_sibling(paolo, marco);
    insert_sibling(marco, anna);
    insert_child(marco, lucia);

    debug_print(root);

    cout << "Size DFS: " << tree_size_dfs(root) << endl;
    cout << "Size BFS: " << tree_size_bfs(root) << endl;

    cout << "Leaves DFS: " << leaves_dfs(root) << endl;
    cout << "Leaves BFS: " << leaves_bfs(root) << endl;

    cout << search_dfs(root, "Lucia") << " " << search_dfs(root, "Lucia")->parent->inf << endl;
}