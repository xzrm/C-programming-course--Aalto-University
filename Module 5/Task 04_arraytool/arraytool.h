
#define CHECK(cond, msg) if(cond == 0) printf("%s", msg) 
#define MAKE_ARRAY(type, n) malloc(n * sizeof(type))
#define ARRAY_IDX(type, array, i) *(((type*) array) + i) //array is a point so e.g. (int*) array declares a pointer of type int to array 
                                                        //(or a block of allocated memory in our case)

/*
int* arr[2] ->  array of pointers to int
(int*)arr[2] -> assuming that arr is an array (which was already declared!),
                takes the value which is arr[2] 
                and casts a pointer to int type on it
*/