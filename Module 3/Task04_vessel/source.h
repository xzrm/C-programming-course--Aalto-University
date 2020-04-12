struct cargo {
    const char *title;
    int quantity;
    double weight;
};


struct vessel {
    char name[31];
    double length;
    double depth;
    struct cargo crg;
};


struct vessel create_vessel(const char *name, double length, double depth, struct cargo crg);
void print_vessel(const struct vessel *ship);