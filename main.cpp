 /*
Нахождение кратчайшего пути ко всем вершинам в графе

Тк нам нужно найти расстояния стразу до всех вершин, использовать умные алгоритмы поиска путей на графах нет смысла
(Это не значит, что я их не знаю, на одном из хакатонов написал классную смесь дейкстры и a* для задачи с лабиринтом и робомышью)
В коде используется exit(-1) вместо исключения, потому что в случае исключения при использовании программы не всегда будет понятно, что исключение вызвано специально
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <cstdint>
#include <queue>

constexpr int MAX_RECURSION_DEPTH = 100000; // Технически бесконечных рекурсий быть не должно, но это профилактика
constexpr bool USE_BFS = false;

using resultMap = std::unordered_map<uint32_t, uint32_t>;
using graphMap = std::unordered_map<uint32_t, std::unordered_set<uint32_t>>;

// Поиск путей в глубину, возможен небольшой оверхэд
void dfs(uint32_t elem, graphMap& graph,
    resultMap& result, uint32_t current_recursion_depth){
    if (!result.count(elem)) result[elem] = current_recursion_depth;
    else {
        uint32_t new_value = std::min(result[elem], current_recursion_depth);
        bool value_changes = result[elem] == new_value ? 0 : 1;
        result[elem] = new_value;
        if (!value_changes) return;
    }
    if (current_recursion_depth > MAX_RECURSION_DEPTH) return; 

    current_recursion_depth++;

    for (uint32_t i : graph[elem]){
        dfs(i, graph, result, current_recursion_depth);
    }
}


// Поиск в ширину (гарант минимальности пути)
void bfs(uint32_t start_vertex, graphMap& graph, resultMap& distances) {
    std::queue<uint32_t> q;
    q.push(start_vertex);
    distances[start_vertex] = 0;

    while (!q.empty()) {
        uint32_t u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (distances.find(v) == distances.end()) { 
                distances[v] = distances[u] + 1;
                q.push(v);
            }
        }
    }
}


int main(int argc, const char *argv[])
{
    if (argc == 1) {
        std::cout << "Please provide a path to the graph as an argument!\n";
        exit(-1);
    } 
    else if (argc > 2) {
        std::cout << "Multiple graph handling is not yet supported!\n";
        exit(-1);
    } 
    std::string file_name = argv[1];
    std::ifstream file(file_name);
    if (!file.is_open()){
        std::cout << "Could't open the file provided\n";
        exit(-1);
    }


    uint32_t vertex_count, edge_count, target_vertex;
    graphMap graph;
    resultMap result;

    
    file >> vertex_count;
    file >> edge_count;
    for (uint32_t i = 0; i < edge_count; i++){
        uint32_t temp_vertex_1, temp_vertex_2;
        file >> temp_vertex_1 >> temp_vertex_2;
        graph[temp_vertex_1].insert(temp_vertex_2);
        graph[temp_vertex_2].insert(temp_vertex_1); // т.к. граф двунаправленный
    }
    file >> target_vertex;

    if (USE_BFS) bfs(target_vertex, graph, result);
    else dfs(target_vertex, graph, result, 0);
    
    for (uint32_t i = 0; i < result.size(); i++){
        
        // cout << "The shortest possible path from " << target_vertex << " to "<< i << " is " << result[i] << " long" << "\n";
        std::cout << result[i] << "\n";
    }

    
    return 0;
}