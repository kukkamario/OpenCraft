#ifndef VERTEX_H
#define VERTEX_H

struct Vertex
{
    Vertex():x(0),y(0),z(0){}
    Vertex(float x2,float y2,float z2):x(x2),y(y2),z(z2){}
    float x;
    float y;
    float z;
};

struct Normal
{
    Normal():x(0),y(0),z(0){}
    Normal(float x2,float y2,float z2):x(x2),y(y2),z(z2){}
    float x;
    float y;
    float z;
};

struct TexCoord
{
    TexCoord():u(0),w(0){}
    TexCoord(float u2,float w2):u(u2),w(w2){}
    float u;
    float w;
};

#define BLOCK_VERTEX_OFFSET_VERTEX 0
#define BLOCK_VERTEX_OFFSET_NORMAL 12
#define BLOCK_VERTEX_OFFSET_TEXCOORD 24

struct BlockVertex
{
    Vertex mVertex;
    Normal mNormal;
    TexCoord mTexCoord;
};

#endif // VERTEX_H
