#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

typedef struct{
    char type; // 0 = fried chicken, 1 = French fries
    int amount; // pieces or weight
    char unit; // 0 = piece, 1 = gram
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i){
    while ((first + 1) % BUFFER_SIZE == last){
        // do nothing -- no free buffer item
    }
    memcpy(&buffer[first], i, sizeof(item));
    first = (first + 1) % BUFFER_SIZE;
    printf("Done producing; Log value--- first: %d last: %d\n", first, last);
}

item *consume(){
    item *i = malloc(sizeof(item));
    while(first == last){
        // do nothing -- nothing to consume
    }
    memcpy(i, &buffer[last], sizeof(item));
    last = (last + 1) % BUFFER_SIZE;
    printf("Done selling; Log value--- first: %d last: %d\n", first, last);

    return i;
}

item* addItem(char type, int amount, char unit){
    item *i = malloc(sizeof(item));
    i->type = type;
    i->amount = amount;
    i-> unit = unit;

    return i;
}

int main(){
    item* item1 = addItem('0', '4', '1');
    item* item2 = addItem('1', '7', '0');

    produce(item1);
    produce(item2);

    consume();

    return 0;
}
