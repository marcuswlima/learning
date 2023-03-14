template < class T > // ou template< typename T >
T min( T value1, T value2 )
{
    T retorno;
    if (value1 < value2)
        retorno = value1;
    else if (value2 < value1)
        retorno = value2;
    else if (value1 = value2)   
        retorno =  0;
    return retorno;
} // fim do template de função maximum