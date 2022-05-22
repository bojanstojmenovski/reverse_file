#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *value;
    struct node *next;
};
typedef struct node node_t;

void print_list_in_flie(node_t *head, FILE *file) {
    node_t *temporary = head;

    while (temporary != NULL) {
        fprintf(file, "%s", temporary->value);
        fprintf(file, "\n");
        temporary = temporary->next;
    }
}

node_t *create_node(char *value) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

int main(int argc, char *argv[]) {
    if (argc > 2) {
        fprintf(stderr, "Usage: reverse <input> <output>");
        exit(1);
    } else {
        FILE *fr = fopen("input.txt", "r");
        if (!fr) {
            fprintf(stderr, "Error: Cannot open file 'input.txt'!");
            exit(1);
        }

        FILE *fw = fopen("output.txt", "w+");
        if (!fw) {
            fprintf(stderr, "Error: Cannot open file 'output.txt'!");
            exit(1);
        }

        char * line = NULL;
        size_t len = 0;
        node_t *head = NULL;
        node_t *tmp;
        char * a = NULL;

        while (getline(&line, &len, fr) != -1) {
            tmp = create_node(line);
            tmp->next = head;
            head = tmp;
        }

        print_list_in_flie(head, fw);

        fclose(fw);
        fclose(fr);
    }
    
    return 0;
}