#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char value[1024];
    struct node *next;
};
typedef struct node node_t;

// Printing values of nodes of a linked list in a file
void print_list_in_file(node_t *head, FILE *file) {
    node_t *temporary = head;

    while (temporary != NULL) {
        fprintf(file, "%s", temporary->value);
        temporary = temporary->next;
    }
}

void print_list_on_screen(node_t *head) {
    node_t *temporary = head;

    while (temporary != NULL) {
        printf("%s", temporary->value);
        temporary = temporary->next;
    }
}

node_t *create_node(char *value) {
    node_t *new_node = malloc(sizeof(node_t));
    strncpy(new_node->value, value, strlen(value));
    new_node->next = NULL;
    return new_node;
}

node_t *read_lines_from_file(char *file) {
    FILE *fr = fopen(file, "r");

        if (!fr) {
            fprintf(stderr, "Error: Cannot open file 'input.txt'!");
            exit(1);
        }
        
        char * line = NULL;
        size_t len = 0;
        node_t *head = NULL;
        node_t *tmp;

        while (getline(&line, &len, fr) != -1) {
            tmp = create_node(line);
            tmp->next = head;
            head = tmp;
        }

        fclose(fr);

        return head;
}

void write_in_file(char *output, node_t *head) {
            FILE *fw = fopen(output, "w+");

            if (!fw) {
                fprintf(stderr, "Error: Cannot open file 'output.txt'!");
                exit(1);
            }

            print_list_in_file(head, fw);

            fclose(fw);
}

int main(int argc, char *argv[]) {
    if (argc > 3) {

        fprintf(stderr, "Usage: reverse <input> <output>");
        exit(1);
        
    } else if (argc == 1) {

        printf("Enter the name of input file: ");
        char input_file[100];
        gets(input_file);

        node_t *head = read_lines_from_file(input_file); 
        print_list_on_screen(head);

        printf("Enter the name of output file: ");
        char output_file[100];
        gets(output_file);

        write_in_file(output_file, head);

    } else {

        node_t *head = read_lines_from_file(argv[1]);        

        if (argv[2]) {
            write_in_file(argv[2], head);
        } else {
            print_list_on_screen(head);
        }

    }
    
    return 0;
}