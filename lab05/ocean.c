#include <stdio.h>
#include <stdlib.h>
#define OCEAN_MAX 41981


struct ocean_datum {
    int x; /* grid-reference east-west */
    int y; /* grid-reference north-south */
    double conc; /* concentration of O_2 in mL/L found at grid-ref (x,y) */
};
void print_ocean_datum(struct ocean_datum *o) {
    printf("%d %d %.4f\n", o->x, o->y, o->conc);
}
int read_ocean_datum(struct ocean_datum *o) {
    return 3 == scanf("%d %d %lg", &o->x, &o->y, &o->conc);
}
void sort(struct ocean_datum *o,int n) {
    int p,q;
    int r = 0;
    int smaller = 0;
    struct ocean_datum key;
    for (p=0; p< n-1; p++){
        key = o[p];
        for (q=p; q < n; q++){
            if ((o[q]).conc < key.conc){
                key = o[q];
                r = q;
                smaller = 1;
            }
        }
        if (smaller == 1){
            o[r] = o[q];
            o[p] = key;
        }
        smaller = 0;
    }
}
int main(void) {
    struct ocean_datum ocean_data[OCEAN_MAX];
    int num_items;
    int i;
    num_items = 0;
    while (num_items < OCEAN_MAX && read_ocean_datum(&ocean_data[num_items])) {
        num_items++;
    }
    /* sort the data here */
    sort(ocean_data,num_items);
    /* print out the array of structs */
    for (i = 0; i < num_items; i++) {
        print_ocean_datum(&ocean_data[i]);
    }
    return EXIT_SUCCESS;
}
