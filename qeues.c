#include <stdio.h>
#include "stdlib.h"


struct qeue {
   int data;
   struct qeue * next;  
};

//struct qeue == int== float == char 
//typedef es ponerle un apodo a un tipo de dato

typedef struct qeue cola;

int insert(cola ** start, int data);
int seek(cola * start);
int delete (cola **start, int data);
cola * search(cola * inicio, int data);
int buscar(cola *inicio, int data);

int main() {
    cola * inicio = NULL;
    int num;
    insert(&inicio, 5);
    insert(&inicio, 2);
    insert(&inicio, 7);
    seek(inicio);
    printf("\n");

    //printf("Inserta valor a eliminar");
    //scanf("%i", &num);
    //if(delete(&inicio, num) == 0)
     //   printf("Nosta\n");
    //else
    //    printf("Si esta y se borro\n");    
    //delete(&inicio, 2);
    delete(&inicio, 5);
    seek(inicio);

    //cola * prueba = search(inicio, 7);
    /*if(!search(inicio, 7))
        printf("No esta\n");
    else
        printf("Encontrado: %i\n", search(inicio, 7)->data);// %i\n", prueba->data);*/

    /*if(buscar(inicio, 7) != 0)
        printf("Encontrado: %i\n", buscar(inicio, 7));
    else
        printf("Nosta");    */

    num = 7;
    if(buscar(inicio, num) == num)
        printf("Encontrado: %i\n", num);
    else
        printf("No esta bb\n");    
    //prueba->data = 9;
    //seek(inicio);
    return 0;
}

int insert(cola ** start, int data) {
    if(!(*start)) {
        (*start) = (cola *) malloc(sizeof(cola));
        if(!(*start))
            return 0;
        (*start)->data = data;
        (*start)->next = NULL;
        return 1;
    }
    return insert(&(*start)->next, data);
    /*if((*start)){
        return insert(&(*start)->next, data);    
    }
    (*start) = (cola *) malloc(sizeof(cola)); 
    (*start)->data = data;
    (*start)->next = NULL;
    return 1;*/
}

int seek(cola * start) {
    if(!start)
        return 0;
    printf("%i\n", start->data);
    return seek(start->next);        
}

int delete(cola ** start, int data) {
    if(!(*start))
        return 0;
    int valor_cola = (*start)->data;
    if(valor_cola != data)
        return delete(&(*start)->next, data);
    cola * aux = NULL;
    aux = (*start);
    (*start) = (*start)->next;
    free(aux);
    return 1;
}

cola * search(cola * inicio, int data) { //retorna la referencia al elemento buscado
    if(!inicio){
        return NULL;
    }
    if(inicio->data != data)
        return search(inicio->next, data);
    return inicio;
}

int buscar(cola * inicio, int data) { //retorna el valor buscado, si se encuentra en la cola
    if(!inicio) 
        return 0;
    if(inicio->data != data)
        return buscar(inicio->next, data);
    return inicio->data;        
}
