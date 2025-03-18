/*
Нахождение кратчайшего пути ко всем вершинам в графе

В коде используется exit(-1) вместо исключения, потому что в случае исключения при использовании программы не всегда будет понятно, что исключение вызвано специально
*/
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;


void combined_floodfill(uint32_t elem, unordered_map<uint32_t, unordered_set<uint32_t>>& graph, unordered_map<uint32_t, uint32_t>& result, uint32_t current_recursion_depth){

}


int main(int argc, const char *argv[])
{
    if (argc == 1) {
        cout << "Please provide a path to the graph as an argument!\n";
        exit(-1);
    } 
    else if (argc > 2) {
        cout << "Multiple graph handling is not yet supported!\n";
        exit(-1);
    } 
    string file_name = argv[1];
    ifstream file(file_name);
    if (!file.is_open()){
        cout << "Could't open the file provided\n";
        exit(-1);
    }


    uint32_t vertex_count, edge_count, target_vertex, temp_vertex_1, temp_vertex_2, current_recursion_depth;
    unordered_map<uint32_t, unordered_set<uint32_t>> graph;
    unordered_map<uint32_t, uint32_t> result;

    
    file >> vertex_count;
    file >> edge_count;
    for (uint32_t i = 0; i < edge_count; i++){
        file >> temp_vertex_1 >> temp_vertex_2;
        graph[temp_vertex_1].insert(temp_vertex_2);
    }
    file >> target_vertex;

    
    return 0;
}
