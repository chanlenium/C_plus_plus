#ifndef NAME_H
#define NAME_H
// Virtual Inheritance

class Name {
    const char* name;
protected:
    Name(const char* n);
public:
    virtual void display() const;
};
#endif