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

// dequeue


// first by vinicius
void* first(DoublyLinkedList *list) {
    return list->first->next->data;
}
// last by vinicius
void* last(DoublyLinkedList *list) {
    return list->first->previous->data;
}

// push

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