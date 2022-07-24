int main(void)
{
    int n1, n2, max;
    printf("Ingrese dos numeros enteros: ");
    scanf("%d %d", &n1, &n2);
    max = MAYOR(n1, n2);
    int octal=0271;
    int hexa=0xA21B;
    int decimal=41234;
    int decimal2=312;
    int real=1.77;
    float real2 = .1;
    char a = 'b';
    char b = 'z';
    printf("El mayor entre %d y %d es %d\n", n1, n2, max);
    return 0;
}

int MAYOR(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
//hola
/*
comentario largo
*/
/*Comentario de una linea*/
