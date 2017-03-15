#include <stdio.h>
#include <iostream>
#include <vector>
#include <cassert>

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Vec2 {
    float u;
    float v;
};

//Vec2 zero2{0, 0};
//Vec3 zero3{0, 0, 0};
//Vec2 one2{0, 0};
//Vec3 one3{0, 0, 0};

float vertices[] = {
    // Positions           // Normals           // Texture Coords
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
     0.5f,  -0.5f, 0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
     0.5f, 0.5f,  -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
};

int main(int argc, char* argv[]) {
    size_t array_size = sizeof(vertices) / sizeof(float);
    std::vector<Vec3> vertex;
    std::vector<Vec3> normal;
    std::vector<Vec2> uv;
    const int line = 8;
    const int vertex_size = 288/8;
    printf("size of vertex number %d.\n", vertex_size);
    for(int i = 0; i < vertex_size; ++i) {
        int base = i * 8;
        
        Vec3 v = {vertices[base], vertices[base + 1], vertices[base + 2]};
        Vec3 vn = {vertices[base + 3], vertices[base + 4], vertices[base + 5]};
        Vec2 vt = {vertices[base + 6], vertices[base + 7]};
        
        vertex.push_back(v);
        normal.push_back(vn);
        uv.push_back(vt);
    }
    printf("size of vertex number %lu.\n", vertex.size());
    printf("size of normal number %lu.\n", normal.size());
    printf("size of uv number %lu.\n", uv.size());
    
    FILE* file = fopen("container.obj", "w+");
    if(!file) {
        printf("open file container.obj error.\n");
    }
    for(int i = 0; i < vertex_size; ++i) {
        fprintf(file, "v %f %f %f\n", vertex[i].x, vertex[i].y, vertex[i].z);
    }
    for(int i = 0; i < vertex_size; ++i) {
        fprintf(file, "vt %f %f\n", uv[i].u, uv[i].v);
    }
    for(int i = 0; i < vertex_size; ++i) {
        fprintf(file, "vn %f %f %f\n", normal[i].x, normal[i].y, normal[i].z);
    }
    for(int i = 0; i < vertex_size/3; ++i) {
        int base = i * 3;
        fprintf(file, "f %d/%d/%d %d/%d/%d %d/%d/%d\n", base+1, base+1, base+1, base+2, base+2, base+2, base+3, base+3, base+3);
    }
    fprintf(file, "\n");
    fclose(file);
    return 0;
}
