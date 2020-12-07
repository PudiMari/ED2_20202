 /* 3.1 LinkedList.h --> Kamilla
  * 3.2 LinkedList.c --> Kamilla
  *     3.2.1 init --> Vinícius
  *     3.2.2 isEmpty --> Naíra
  *     3.2.3 enqueue --> Naíra
  *     3.2.4 first --> Vinícius
  *     3.2.5 last --> Vinícius
  *     3.2.6 dequeue --> Mariana
  *     3.2.7 pop 
  *     3.2.8 top 
  *     3.2.9 push --> Mariana
  *     3.2.10 getNodeByPos --> Katia
  *     3.2.11 getPos --> Katia
  *     3.2.12 add
  *     3.2.13 addAll
  *     3.2.14 removePos --> Leonardo
  *     3.2.15 indexOf --> Leonardo
  *     3.2.16 removeData
  *4 LinkedListTest.c --> Kamilla
  */

bool isEmpty(LinkedList *list){
    return(list->size==0);
}

int enqueue(LinkedList *list, void *data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode==NULL) return -1;
    newNode->data = data;
    newNode->next = NULL;
    if(isEmpty(list)) //se a lista estiver vazia
        list->first = newMode; //novo nó é o primeiro
    else{
        Node *aux = list->first; //aux aponta para o primeiro
        while(aux->next!=NULL) //enquanto não for o último nó
            aux = aux->next; //aux avança para o nó seguinte
        aux->next = newNode; //último nó aponta para o novo nó
    }
    list->size++;
    return 1;
}

