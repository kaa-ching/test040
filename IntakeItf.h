#ifndef INTAKEITF_H
#define INTAKEITF_H

class IntakeItf
{
public:
    virtual void OpenIntake(int nr) = 0;
    virtual void CloseIntake(int nr) = 0;
};

#endif // INTAKEITF_H
