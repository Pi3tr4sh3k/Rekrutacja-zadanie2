#include <iostream>

# define VERT 14

float pathWeight(float &r, float &y, float &g, float graph[VERT][VERT]) {
                          // 0  1  2  3  4  5  6  7  8  9  10 11 12 13
    float colors[14][14] = {{0, g, 0, 0, 0, y, 0, 0, 0, 0, 0, 0, 0, 0},   //0
                            {g, 0, r, 0, 0, 0, 0, 0, 0, 0, 0, g, 0, 0},   //1
                            {0, r, 0, g, 0, 0, 0, 0, 0, 0, 0, 0, y, 0},   //2
                            {0, 0, g, 0, g, 0, 0, 0, 0, 0, 0, 0, 0, 0},   //3
                            {0, 0, 0, g, 0, 0, 0, 0, 0, 0, y, 0, 0, r},   //4
                            {y, 0, 0, 0, 0, 0, r, 0, 0, 0, 0, y, 0, 0},   //5
                            {0, 0, 0, 0, 0, r, 0, r, 0, 0, 0, 0, 0, 0},   //6
                            {0, 0, 0, 0, 0, 0, r, 0, r, 0, 0, r, 0, 0},   //7
                            {0, 0, 0, 0, 0, 0, 0, r, 0, y, 0, 0, 0, g},   //8
                            {0, 0, 0, 0, 0, 0, 0, 0, y, 0, y, 0, 0, 0},   //9
                            {0, 0, 0, 0, y, 0, 0, 0, 0, y, 0, 0, 0, 0},   //10
                            {0, g, 0, 0, 0, y, 0, r, 0, 0, 0, 0, y, 0},   //11
                            {0, 0, y, 0, 0, 0, 0, 0, 0, 0, 0, y, 0, g},   //12
                            {0, 0, 0, 0, r, 0, 0, 0, g, 0, 0, 0, g, 0},   //13
    };
    for (int i = 0; i < VERT; i++)
        for (int j = 0; j < VERT; j++)
            graph[i][j] *= colors[i][j];
    return graph[VERT][VERT];


}

float minDistance(float dist[], bool sptSet[]) {

    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < VERT; v++){
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }


    }

    return min_index;
}


void printSolution(float *dist) {
    std::cout<<"The shortest path from A to B is: "<<dist[4];
}


void dijkstra(float graph[VERT][VERT]) {
    bool sptSet[VERT];
    float dist[VERT];
    for (int i = 0; i < VERT; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[0] = 0;
    for (int i = 0; i < VERT - 1; i++){
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < VERT; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist);
}

int main() {
    float r, y, g = 0;
    while (true) {
        std::cout << "Please enter weights of red, yellow and green paths" << std::endl;
        std::cin >> r;
        std::cin >> y;
        std::cin >> g;
        if (r > 0 && y > 0 && g > 0)
            break;
        std::cout << "All numbers must be greater than 0!!! Try again" << std::endl;

    };
//                          0   1    2    3    4    5    6    7    8    9    10   11   12   13
    float graph[14][14] = {{0,  10,  0,   0,   0,   2,   0,   0,   0,   0,   0,   0,   0,   0},
                           {10, 0,   7.8, 0,   0,   0,   0,   0,   0,   0,   0,   4.5, 0,   0},
                           {0,  7.8, 0,   2.2, 0,   0,   0,   0,   0,   0,   0,   0,   1.7, 0},
                           {0,  0,   2.2, 0,   5,   0,   0,   0,   0,   0,   0,   0,   0,   0},
                           {0,  0,   0,   5,   0,   0,   0,   0,   0,   0,   5,   0,   0,   3.3},
                           {2,  0,   0,   0,   0,   0,   3,   0,   0,   0,   0,   7.5, 0,   0},
                           {0,  0,   0,   0,   0,   3,   0,   3.8, 0,   0,   0,   0,   0,   0},
                           {0,  0,   0,   0,   0,   0,   3.8, 0,   2,   0,   0,   3.5, 0,   0},
                           {0,  0,   0,   0,   0,   0,   0,   2,   0,   3.8, 0,   0,   0,   1.3},
                           {0,  0,   0,   0,   0,   0,   0,   0,   3.8, 0,   3.5, 0,   0,   0},
                           {0,  0,   0,   0,   5,   0,   0,   0,   0,   3.5, 0,   0,   0,   0},
                           {0,  4.5, 0,   0,   0,   7.5, 0,   3.5, 0,   0,   0,   0,   4.2, 0},
                           {0,  0,   1.7, 0,   0,   0,   0,   0,   0,   0,   0,   4.2, 0,   3.7},
                           {0,  0,   0,   0,   3.3, 0,   0,   0,   1.3, 0,   0,   0,   3.7, 0},
    };

    pathWeight(r,y,g, graph);
    dijkstra(graph);
}