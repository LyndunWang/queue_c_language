#include <stdio.h>
#include <malloc.h>
#define MAX_SIZE 10
struct  queue_cell{
    int *node;
    int front;
    int rear;
};

/* init queue,malloc a block for the queue */
void init_queue(struct queue_cell *queue)
{
    queue->node = (struct queue_cell *)malloc(sizeof(queue) * MAX_SIZE);
    queue->front = 0;
    queue->rear = 0;
}

/* add a element */
void add_elem(struct queue_cell *queue,int *elem)
{
    if(((queue->rear+1)%MAX_SIZE) == queue->front){

        printf("its full\n");
    }
    else {
        queue -> rear =(queue->rear + 1)%MAX_SIZE;
        queue -> node[queue->rear] = *elem;
    }
}

/* delete a element */
void  delete_elem(struct queue_cell *queue)
{
    if(queue->front == queue->rear){
        printf("its empty\n");
    }
    else{
        queue->front = (queue->front + 1)%MAX_SIZE;
        printf ("%d is delete\n", (queue -> node[queue->front])) ;
    }
}

/* print the queue */
void print_queue(struct queue_cell *queue)
{
    if(queue->front == queue->rear){
        printf("its empty\n");
    }
    else {
        int i = (queue->rear - queue->front);
        int j = 1;
        do {
         printf("%d//\n",(queue->node[queue->front + j]));
         j++;
        } while(j != (i + 1));
    }
}

void main()
{
    /*1:add 2:delete 3:print 4:exit */
    printf("1:add 2:delete 3:print 4:exit\n");
    int tag  = 0;
    int add_value = 0; 
    struct queue_cell *queue;
    init_queue(queue);
    printf("init the queue over,please enter a tag value(1 or 2 or 3 or 4):\n");
    while (1) {
        scanf("%d", &tag);
        if (tag == 1){
            printf ("please enter the add value:\n");
            scanf("%d",&add_value);
            add_elem(queue, &add_value);       
        } else if (tag == 2) {
           delete_elem(queue);
        } else if (tag == 3){
            print_queue(queue);
        } else if (tag == 4){
            printf ("over\n");
            return;
        } else {
            printf ("illegal over\n");
            return;     
        }
        printf ("please enter what u want to do (1 or 2 or 3 or 4):");
   }
}
