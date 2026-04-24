#include <vector> 
#include <utility> 
#include <iostream> 
#include <queue>
#include <climits>

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

namespace Dijksrta {
  int size{5};

  void algortihm() {
    // Vertices are each index of the vector while the vector of pairs are the edges 
    std::vector<std::vector<std::pair<int,int>>> ad(size);
    // Creating edges
    ad[0].push_back({1, 2});
    ad[1].push_back({0, 2});

    ad[0].push_back({3, 6});
    ad[3].push_back({0, 6});

    ad[1].push_back({2, 3});
    ad[2].push_back({1, 3});

    ad[1].push_back({3, 8});
    ad[3].push_back({1, 8});

    ad[1].push_back({4, 5});
    ad[4].push_back({1, 5});

    ad[2].push_back({4, 7});
    ad[4].push_back({2, 7});

    ad[3].push_back({4, 9});
    ad[4].push_back({3, 9});

    int source{};
    std::vector<int> distance(size,INT_MAX);
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<>> p_queue;
    distance[source] = 0;
    p_queue.push({0,source});
    while(!p_queue.empty()) {
      auto [d,u] = p_queue.top();
      p_queue.pop();
      if(d > distance[u]) {
        continue;
      }

      for(auto [v, w]: ad[u]) {
        // Relaxing of the edges 
        if(distance[u] + w < distance[v]) {
          distance[v] = distance[u] + w;
          p_queue.push({distance[v],v});
        }
      }
    }

    std::cout << "Shortest distances from node 0: \n";
    for(int i = 0; i < size; i++) {
      std::cout << source << " -> " << i << " = " << distance[i] << "\n";
    }
  }
};

#endif 
