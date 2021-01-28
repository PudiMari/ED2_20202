/*5.1 Hash.h --> Kamilla
 *   5.2 Hash.c --> Kamilla
 *       5.2.1 initHash --> Vinícius 
 *       5.2.2 hash --> Vinícius 
 *       5.2.3 containsKey - Gustavo
 *       5.2.4 put - Naíra
 *       5.2.5 get - Katia  
 *       5.2.6 removeKey - Mariana
 *       5.2.7 showHashStruct - Leonardo
*6 HashTest.c
*/
#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

//InitHash -  Inicialização da Hash by Vinicius
void initHash(HashStruct *hashStruct) {
    for (int i=0;i<MAX;i++) {
        //chamando init de DoublyLinkedList para inicializar cada lista do vetor
        init(&(hashStruct->hashes[i]));
    }
    hashStruct->size = 0;
}

// Função Para calcular em que posição devemos inserir o elemento by Vinicius
int hash(char *key) {
    int sum = 0;
    // percorremos todos os caracteres da string passada
    for (int i = 0; key[i]!=0;i++) {
         //acumulamos os códigos ascii de cada letra com um peso
        sum+=key[i]*(i+1);
    }
    return sum%MAX; //retorna o resto da divisão
}

// Struct-key - estrutura busca e inserção de chave: Gustavo  
bool containsKey(HashStruct *hashStruct, char *key, compare equal) {
    //calcula a posição
    int hashValue = hash(key);
    //busca na fila a posição da chave
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal); 
    
    return (pos!=-1)?true:false;
}

//put - função para inserir elementos na hash by Naíra 
int put(HashStruct *hashStruct, char *key, void *data, compare equal){
    if(!containsKey(hashStruct, key, equal)){
        //Adiciona na fila que está na posição devolvida pela função hash
        int res = enqueue(&hashStruct->hashes[hash(key)], data);
        //Incrementa a quantidade de elementos baseado na quantidade inserida por enqueue
        hashStruct->size+=res;
        return res;
    }
    return 0;
}

// remove key para remover um par by Mariana
void* removeKey(HashStruct *hashStruct, char *key, compare equal) {
    int hashValue = hash(key);
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal);
    void* result = removePos(&hashStruct->hashes[hashValue], pos);
    if (result!=NULL) hashStruct->size--;
    return result;
}

