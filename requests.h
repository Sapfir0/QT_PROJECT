#ifndef REQUESTS_H
#define REQUESTS_H


unsigned long long int fact(int arg)
{
        return arg<=1 ? 1 : arg * fact(arg - 1); // делаем рекурсию.
}



#endif // REQUESTS_H
