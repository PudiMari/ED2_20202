 /* 3.1 LinkedList.h --> Kamilla
  * 3.2 LinkedList.c --> Kamilla
  *     3.2.1 init --> Vinícius
  *     3.2.2 isEmpty --> Naíra
  *     3.2.3 enqueue --> Naíra
  *     3.2.4 first --> Vinícius
  *     3.2.5 last --> Vinícius
  *     3.2.6 dequeue --> Mariana
  *     3.2.7 pop --> Kamilla
  *     3.2.8 top --> Kamilla
  *     3.2.9 push --> Mariana
  *     3.2.10 getNodeByPos --> Katia
  *     3.2.11 getPos --> Katia
  *     3.2.12 add --> Gustavo
  *     3.2.13 addAll --> Naíra
  *     3.2.14 removePos --> Leonardo
  *     3.2.15 indexOf --> Leonardo
  *     3.2.16 removeData --> Gustavo
  *4 LinkedListTest.c --> Kamilla
  */
 #include <stdio.h>
 #include <stdlib.h>
 #include "LinkedList.h"
 
//Init feito para inicializar a lista/fila by vinicius
void init(LinkedList *list) {
    list->first=NULL;
    list->size=0;
}

//Verifica se a lista está vazia by Naíra
bool isEmpty(LinkedList *list){
    return(list->size==0);
}

//Insere um elemento ao final da lista by Naíra
int enqueue(LinkedList *list, void *data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode==NULL) return -1;
    newNode->data = data;
    newNode->next = NULL;
    if(isEmpty(list)) //se a lista estiver vazia
        list->first = newNode; //novo nó é o primeiro
    else{
        Node *aux = list->first; //aux aponta para o primeiro
        while(aux->next!=NULL) //enquanto não for o último nó
            aux = aux->next; //aux avança para o nó seguinte
        aux->next = newNode; //último nó aponta para o novo nó
    }
    list->size++;
    return 1;
}
// retorna o primeiro valor da lista by vinicius
void* first(LinkedList *list) {
    return (isEmpty(list))?NULL:list->first->data;
}
//retorna o ultimo valor da lista by vinicius
void* last(LinkedList *list) {
    void *data = NULL;
    if (!isEmpty(list)) {          //Se a lista não estiver vazia
        Node *aux = list->first;   //aux aponta para o primeiro nó
        while (aux->next != NULL)  //enquanto não for o último nó
            aux = aux->next;       //aux avança para o nó seguinte
        data = aux->data;          //endereço de memória do dado no último nó
    }
    return data;
}

//para usar a pilha, reaproveita-se as operações da fila

//pop
void* pop(LinkedList *list) {
    return dequeue(list);
}

//top
void* top(LinkedList *list) {
    return first(list);
}

//Adiciona uma lista dentro de outra lista a partir de uma determinada posição by Naíra
int AddAll(LinkedList *listDest, int pos, LinkedList *listSource){
    if(listDest==NULL || isEmpty(listDest)) return -1;
    if(listSource==NULL || isEmpty(listSource)) return -2;
    Node *last = NULL;
    for(last = listSource->first; last->next!=NULL; last = last->next);
    if(pos==0){
        last->next = listDest->first;
        listDest->first = listSource->first;
    }else{
        Node *aux = getNodeByPos(listDest, (pos-1));
        if(aux==NULL) return -3;
        last->next = aux->next;
        aux->next = listSource->first;
    }
    listDest->size+=listSource->size;
    return listSource->size;
}

// remove um elemento da lista de uma posicao fornecida. by Leonardo
void* removePos (LinkedList *list, int pos) {
    if (isEmpty(list) || pos >=list->size)  // verifica se a lista esta vazia ou se a posicao fornecida eh invalida.
        return NULL;

    Node *nodeRemove = NULL; // variavel auxilar que aponta para o noh a ser removido.
    Node *aux = NULL; // variavel auxiliar que aponta para o noh anterior ao que sera removido.

    if (pos<=0) // verifica se eh o primeiro elemento da lista.
        return dequeue(list); // se for o primeiro podemos aproveitar a funcao dequeue.
    else 
        aux = getNodeByPos(list, pos-1); // busca o elemento anterior da posicao a ser removida.
    
    // realiza a remocao.
    nodeRemove = aux->next;
    aux->next = nodeRemove->next; // faz com que o noh anterior aponte para o noh seguinte, pulando o elemento que sera removido.

    void* dataRemove = nodeRemove->data;// salva o valor do elemento removido.
    free(nodeRemove); // limpa o noh da memoria.
    list->size--;// diminui um do tamanho da lista.

    return dataRemove; // retorna o valor do elemento removido.
}

// retorna a posicao da lista de um elemento determinado. by Leonardo
int indexOf (LinkedList *list, void *data, compare equal){
    if (isEmpty (list)) // verifica se a lista esta vazia.
        return -1; // se estiver vazia, retorna -1, identificando que eh invalida.

    int count = 0;// variavel contadora, para as posicoes da lista.
    Node *aux = list->first; // variavel auxiliar para navegar na lista.

    while (aux!= NULL && !equal(aux->data, data)) {// enquanto nao chega no final da lista, e nao encontra o valor fornecido na lista, continua o loop.
        aux = aux->next; // passa para o proximo elemento.
        count++; // soma mais um na posicao.
    }

    return (aux==NULL) ?-1:count; // se aux igual a NULL, quer dizer que chegou no final da lista e nao encontrou o elemento, senao retorna a posicao onde parou.
}