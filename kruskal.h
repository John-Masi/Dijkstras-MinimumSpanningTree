#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include "edge.h"

#ifndef KRUSKAL_H
#define KRUSKAL_H

namespace Kruskal {
  int V{5};
  int E{7};
  
  int find(int x, std::vector<int>& p) {
    if(p[x] != x) {
      p[x] = find(p[x],p);
    }
    return p[x];
  }

  void uni(int x,int y, std::vector<int>& p,std::vector<int>& r) {
    x = find(x,p);
    y = find(y,p);
    if(x != y){
      if(r[x] < r[y]) {
        std::swap(x,y);
      }
      p[y] = x;
      if(r[x] == r[y]) {
        r[x]++;
      }
    }
  }

  void algorithm() {
    int totalW{};
    std::vector<Edge> mst;
    std::vector<Edge> e = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };
    std::sort(e.begin(),e.end(),[](Edge e1,Edge e2) { return e1.w < e2.w; });
    

    std::vector<int> p(V);
    std::vector<int> r(V,0);
    
    for(int i = 0; i < V; i++) {
      p[i] = i;
    }
    for(auto& n: e){
      if(find(n.u,p) != find(n.v,p)) {
        uni(n.u,n.v,p,r);
        mst.push_back(n);
        totalW += n.w;
        
      }
    }

    std::cout << "Total weight: " <<totalW << "\n";
    
    std::cout << "Edges in MST:" << "\n";
    for(auto e: mst){
      std::cout << e.u << " - " <<e.v << "  (" << e.w << ") "<<"\n";
    }

  }
};

#endif
