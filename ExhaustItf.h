#ifndef EXHAUSTITF_H
#define EXHAUSTITF_H

class ExhaustItf
{
public:
    virtual void OpenExhaust(int nr) = 0;
    virtual void CloseExhaust(int nr) = 0;
};

#endif // EXHAUSTITF_H
