/*
 * DoublyLinkedList.c (seguindo a estrutura de tópicos da LinkedList)
 *
 * 3.1 LinkedList.h --> Kamilla
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
 *     3.2.12 add
 *     3.2.13 addAll
 *     3.2.14 removePos --> Leonardo
 *     3.2.15 indexOf --> Leonardo
 *     3.2.16 removeData
 *     3.2.17 show
 *     3.2.18 showMe -->Katia
 *4 LinkedListTest.c --> Kamilla
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "DoublyLinkedList.h"

// init by Vinicius
void init(DoublyLinkedList *list) {
    Node *trashNode = (Node*)malloc(sizeof(Node));
    trashNode->data=NULL;
    trashNode->previous=trashNode;
    trashNode->next=trashNode;
    list->first=trashNode;
    list->size=0;
}

// enqueue

// dequeue by Mariana
void* dequeue(DoublyLinkedList *list) {
    if (isEmpty(list)) return NULL;
    Node *trash = list->first;
    Node *first = list->first->next;

    first->next->previous = trash;
    trash->next = first->next;

    void *data = first->data;
    free(first);
    list->size--;

    return data;
}


// first by vinicius
void* first(DoublyLinkedList *list) {
    return list->first->next->data;
}
// last by vinicius
void* last(DoublyLinkedList *list) {
    return list->first->previous->data;
}

// push by Mariana
int push(DoublyLinkedList *list, void *data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    newNode->data = data;

    newNode->next = list->first->next;
    newNode->previous = list->first;
    list->first->next->previous = newNode;
    list->first->next = newNode;

    list->size++;

    return 1;
}

//pop e top

void* pop(DoublyLinkedList *list) {
    return dequeue(list);
}

void* top(DoublyLinkedList *list) {
    return first(list);
}
// isEmpty

// indexOf

// retorna o endereço do nó localizado em determinada posição by Katia
Node* getNodeByPos(DoublyLinkedList *list,int pos) {
    if (isEmpty(list) || pos>=list->size) return NULL; //null caso lista vazia ou posição maior que a lista
    Node *aux = list->first->next;  //guarda o endereço do primeiro nó
    for (int count=0;(aux!=list->first && count<pos);count++,aux=aux->next); //laço para encontrar a posição
    return aux;  //retorna a posição encontrada
}

// retorna o conteúdo que está no endereço retornado anteriormente by Katia
void* getPos(DoublyLinkedList *list,int pos) {
    Node *res = getNodeByPos(list,pos);   //auxliar recebe o endereço da posição encontrada
    return (res==NULL)?NULL:res->data;  //caso aux não seja null, retorna a posição encontrada
}

// retorna a posicao da lista de um elemento determinado. by Leonardo
int indexOf (DoublyLinkedList *list, void *data, compare equal) {
    if (isEmpty (list))// verifica se a lista esta vazia.
        return -1; // se estiver vazia, retorna -1, indicando que eh invalida.

    int count = 0;// variavel contadora, para as posicoes da lista.
    Node *aux = list->first->next;// variavel auxiliar da lista.

    while (aux!= list->first && !equal (aux->data, data)){
        aux = aux->next; // passa para o proximo elemento.
        count++; // incrementa mais um a contadora.
    }

    return (aux==list->first)?-1:count;
}

// remove um elemento da lista de uma posicao fornecida. by Leonardo
void* removePos (DoublyLinkedList *list, int pos) {
    if (isEmpty(list) || pos>= list->size) // verifica se a lista esta vazia ou se a posicao fornecida eh invalida.
        return NULL;

    Node *nodeRemove = getNodeByPos (list, pos); // variavel auxiliar que aponta para o noh a ser removido.

    //realiza a remocao.
    nodeRemove->previous->next = nodeRemove->next;
    nodeRemove->next->previous = nodeRemove->previous;

    void* dataRemove = nodeRemove->data; // salva o valor do elemento removido.
    free (nodeRemove);// limpa o noh da memoria.
    list->size--;// decrementa um do tamanho da lista.

    return dataRemove;// retorna o valor do elemento removido.
}
// add

// addAll

//removePos

//removeData

//show

// verificação do uso da memória durante a execução by Katia
void showMem(DoublyLinkedList *list) {
    printf("Trash Node: %p\n\n",list->first);
    Node *aux = list->first->next;  //variavel aux começando do 2° nó
    printf("Node Addr  : Previous    - Data        - Next\n\n");
    while (aux!=list->first) {  //percorre toda lista até o final, ao encontrar o trash
        printf("%p: %p - %p - %p\n",aux, aux->previous, aux->data, aux->next);
        aux=aux->next;
    }
}
