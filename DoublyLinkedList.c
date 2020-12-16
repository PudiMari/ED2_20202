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
 *4 LinkedListTest.c --> Kamilla
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "DoublyLinkedList.h"


//pop e top

void* pop(DoublyLinkedList *list) {
    return dequeue(list);
}

void* top(DoublyLinkedList *list) {
    return first(list);
