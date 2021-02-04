/* Blockchain.h --> Kamilla
 * BlockchainTest.c --> Kamilla
 * sha-256.c --> Kamilla
 * Blockchain.c:
 *      initBlockchain --> Naíra
 *      Hash_to_string --> Vinícius
 *      CalculateHash --> Gustavo
 *      CalculateBlockHash --> Vinícius
 *      GenerateNewBlock --> Katia
 *      GetLatestBlock --> Katia
 *      IsValidNewBlock --> Naíra
 *      IsBlockChainValid --> Leonardo
 *      AddBlock --> Mariana
 *    
 */


#include "Blockchain.h"
#include <string.h>
#include "sha-256.c"
#include <time.h>


//inicialização da estrutura by Naíra
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

//Transforma uma hash de 32 bytes em uma string de 64 caracteres by Vinicius
static void hash_to_string(char string[65], const uint8_t hash[32])
{
    size_t i;
    for (i = 0; i < 32; i++) {
        //montar uma string com 64 caracteres hexadecimais
        string += sprintf(string, "%02x", hash[i]); //02x hexadecimal em 2 caracteres
    }
}

//calcula a hash de um bloco by vini
char* calculateBlockHash(Block *block) {
    return calculateHash(block->index, block->previousHash, block->timestamp, block->data);
}

//valida a integridade de um bloco by Naíra
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
