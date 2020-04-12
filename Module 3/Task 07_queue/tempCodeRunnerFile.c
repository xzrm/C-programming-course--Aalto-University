    while (Queue_dequeue(q))
    {
        if (Queue_firstName(q))
            printf("dequeue, firstname: %s\n", Queue_firstName(q));
        else
            printf("Queue is empty\n");
    }