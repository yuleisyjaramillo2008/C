# include <stdio.h>
float calculoPromedioUnidad(int a);
float validacionNota();
int validacionNumeroActividad();
float calcularACD();
float calcularAA();
float calcularAPE();
float calcularExamenSumativo();
void notaCiclo(float a);
int main(){
    const int  NUMEROUNIDAD=3;
    int i;
    float promedioUnidad, sumaUnidad=0;

    for(i=1; i<=NUMEROUNIDAD; i++){
        promedioUnidad=calculoPromedioUnidad(i); 
        sumaUnidad=sumaUnidad+promedioUnidad;
    }
    notaCiclo(sumaUnidad);

    return 0; 
}

// Control del número de actividades
int validacionNumeroActividad(){
    int actividad;
    do{
        printf("Ingrese la cantidad de notas o actividades\n");
        scanf("%i", &actividad);
        if(actividad<=0){
            printf("ERROR: El valor ingresado no es valido\n");
        }
    }while(actividad<=0);
    return actividad;
}

// Control del ingreso de notas. 
float validacionNota(){
    float nota;
    do{
        printf("Ingrese la nota\n");
        scanf("%f", &nota);
        if(nota<0||nota>10){
            printf("ERROR: La nota ingresada es invalida");
        }
    }while(nota<0||nota>10);
    return nota;
}

// Función para calcular el promedio de cada unidad sumando los preponderados. 
float calculoPromedioUnidad(int a){
    float preponderadoACD, preponderadoAPE, preponderadoAA, preponderadoES, promedioUnidad;
    printf("Unidad %i\n", a);
    printf("ACD\n");
    preponderadoACD=calcularACD();
    printf("APE\n");
    preponderadoAPE=calcularAPE();
    printf("AA\n");
    preponderadoAA=calcularAA();
    printf("Examen Sumativo\n");
    preponderadoES=calcularExamenSumativo();
    promedioUnidad=preponderadoACD+preponderadoAPE+preponderadoAA+preponderadoES;
    printf("El promedio de la Unidad %i es: %f\n", a, promedioUnidad);
    return promedioUnidad;
    
}

// Función para calcular el preponderado de ACD
float calcularACD(){
    int j, numeroActividad;
    float preponderadoACD, nota, promedioACD=0;
    numeroActividad=validacionNumeroActividad();
    for(j=1; j<=numeroActividad; j++){
        printf("Actividad %i\n", j);
        nota=validacionNota();
        promedioACD=promedioACD+nota;
    }
    preponderadoACD= (promedioACD/numeroActividad)*0.2;
    return preponderadoACD;
}

// Función para calcular el preponderado de los APE.
float calcularAPE(){
    int j, numeroActividad;
    float preponderadoAPE, nota, promedioAPE=0;
    numeroActividad=validacionNumeroActividad();
    for(j=1; j<=numeroActividad; j++){
        printf("Actividad %i\n", j);
        nota=validacionNota();
        promedioAPE=promedioAPE+nota;
    }
    preponderadoAPE= (promedioAPE/numeroActividad)*0.25;
    return preponderadoAPE;

}

// Función para calcular el preponderado de los AA.
float calcularAA(){
    int j, numeroActividad;
    float preponderadoAA, nota, promedioAA=0;
    numeroActividad=validacionNumeroActividad();
    for(j=1; j<=numeroActividad; j++){
        printf("Actividad %i\n", j);
        nota=validacionNota();
        promedioAA=promedioAA+nota;
    }
    preponderadoAA= (promedioAA/numeroActividad)*0.2;
    return preponderadoAA;
}

// Función para calcular el preponderado del Examen Sumatívo.
float calcularExamenSumativo(){
    float porcentajeABP, porcentajePD, notaABP, notaPD, preponderadoES;
    do{
        printf("Ingrese el porsentaje que equivale el ABP\nNota; no poner el %%\n");
        scanf("%f", &porcentajeABP);
    }while(porcentajeABP<=0 || porcentajeABP>=100);
    porcentajePD=100-porcentajeABP;
    printf("ABP\n");
    notaABP=validacionNota();
    printf("PD\n");
    notaPD=validacionNota();
    preponderadoES=(notaABP*(porcentajeABP/100)+notaPD*(porcentajePD/100))*0.35;
    return preponderadoES;
}

// Calculo de la nota del ciclo. 
void notaCiclo(float a){
    a=a/3;
    printf("Su nota final del ciclo es: %f\n", a);
    if(a>=7){
        printf("APROBADO\n");
    }else if (a>=2.5){
        printf("SUPLETORIO\n");
    }else{
        printf("REPROBADO\n");
    }
}
