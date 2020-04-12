
    printf("Length of the name: %lu\n", strlen(v.name));

    shortening the name, if it is very long
    v.name[19] = 0;

    if (v.length < 1)
        printf("Length is too short!\n");

    if (v.depth > 100)
        printf("Submarines not allowed\n");

    printf("cargo: %s\n", v.crg.title);