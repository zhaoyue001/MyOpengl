#ifndef UNIFORM_H
#define UNIFORM_H
#include "string"
class uniform {
public:
    uniform(unsigned progID) : programID(progID) {}
    enum TYPE{
        FLOAT1,
        FLOAT2,
        FLOAT3,
        FLOAT4,
        INT1,
        INT2,
        INT3,
        INT4,
        FLOATVEC1,
        FLOATVEC2,
        FLOATVEC3,
        FLOATVEC4,
        INTVEC1,
        INTVEC2,
        INTVEC3,
        INTVEC4,
        MAT2,
        MAT3,
        MAT4
    };
    int getLocation(std::string name);
    void setData(std::string name, unsigned count, void *data, TYPE type);
private:
    unsigned programID;
};
#endif