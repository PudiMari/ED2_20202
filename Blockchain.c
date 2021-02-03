/* Blockchain.h --> Kamilla
 * BlockchainTest.c --> Kamilla
 * sha-256.c --> Kamilla
 * Blockchain.c:
 * initBlockchain --> Naíra
 * isValidNewBlock --> Naíra
 */


#include "Blockchain.h"
#include <string.h>
#include "sha-256.c"
#include <time.h>


//Inicialização da estrutura by Naíra
void initBlockchain(Blockchain *blockchain){
    Block *genesisBlock = (Block*)malloc(sizeof(Block));
    genesisBlock->index = 0;
    genesisBlock->previousHash = "0";
    genesisBlock->previousBlock = NULL;
    genesisBlock->timestamp = time(NULL);
    genesisBlock->data = 1000000;

    genesisBlock->hash = calculateHash(genesisBlock->index, genesisBlock->previousHash,
genesisBlock->timestamp, genesisBlock->data);

    blockchain->genesisBlock = genesisBlock;
    blockchain->latestBlock = genesisBlock;
}

//Valida a integridade de um bloco by Naíra
bool isValidNewBlock(Block* newBlock, Block* previousBlock){
    if(previousBlock->index+1 != newBlock->index){
        return false;
    }else if(previousBlock->hash != newBlock->previousHash){
        return false;
    }else if(strcmp(calculateBlockHash(newBlock), newBlock->hash) != 0){
        return false;
    }
    return true;
}
