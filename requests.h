#ifndef REQUESTS_H
#define REQUESTS_H


unsigned long long int fact(int arg)
{
        return arg<=1 ? 1 : arg * fact(arg - 1); // делаем рекурсию.
}
inline int pifagorianec(int arg1, int arg2)
{
    return (sqrt(arg1*arg1 + arg2*arg2)); //пифагор
}



#endif // REQUESTS_H
