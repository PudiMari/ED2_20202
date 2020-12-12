// implementação do removeData
bool removeData(LinkedList *list, void *data, compare equal) {
    if (isEmpty(list)) return -1;
    Node *nodeRemove = NULL;
    if (equal(list->first->data,data)) {
        nodeRemove = list->first;
        list->first = list->first->next;
        free(nodeRemove->data);
        free(nodeRemove);
        list->size--;
        return true;
    } else {
        Node *aux = list->first;
        while(aux->next!=NULL && !equal(aux->next->data,data))
            aux=aux->next;
    
        if (aux->next!=NULL) {
            Node *nodeRemove = aux->next;
            aux->next = nodeRemove->next;
            free(nodeRemove->data);
            free(nodeRemove);
            list->size--;
            return true;
        } else {
            return false;
        }
    }
}

// implementação da Função Add 
int add(LinkedList *list, int pos, void *data) {
    if (pos <= 0) return push(list,data);
    Node *aux = getNodeByPos(list, (pos-1));
    if (aux==NULL) return -2;
    
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    
    newNode->data = data;
    newNode->next = NULL;
    
    newNode->next = aux->next;
    aux->next = newNode;
    
    list->size++;
    
    return 1;
}