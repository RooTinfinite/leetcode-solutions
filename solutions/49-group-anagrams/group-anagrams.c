// Node for the list of strings (anagrams)
typedef struct string_node {
    char *str;
    struct string_node *next;
} string_node;

// Hash table structure
typedef struct hash_table {
    char key[104];      // Key for anagram groups
    string_node *head;  // Head of linked list of anagrams
    int list_size;      // Number of anagrams in the list
    UT_hash_handle hh;  // Makes this structure hashable
} hash_table;

// Function to create new node for list of strings
string_node *new_string_node(char *s) {
    string_node *node = (string_node *)malloc(sizeof(string_node));
    node->str = strdup(s);
    node->next = NULL;
    return node;
}

// Function to insert a node into the hash table
void insert_node(hash_table **table, char *key, char *str) {
    hash_table *s;

    HASH_FIND_STR(*table, key, s);
    if (s == NULL) {
        s = (hash_table *)malloc(sizeof(hash_table));
        strcpy(s->key, key);
        s->head = new_string_node(str);
        s->list_size = 1;
        HASH_ADD_STR(*table, key, s);
    } else {
        // Append to the list of strings
        string_node *new_node = new_string_node(str);
        new_node->next = s->head;
        s->head = new_node;
        s->list_size++;
    }
}

// Function to generate a key from a string
void create_key(char *str, char *key) {
    int count[26] = {0};
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        count[str[i] - 'a']++;
    }
    key[0] = '\0';
    for (int i = 0; i < 26; i++) {
        char buffer[10];
        sprintf(buffer, "#%d", count[i]);
        strcat(key, buffer);
    }
}

// Updated groupAnagrams function
char ***groupAnagrams(char **strs, int strsSize, int *returnSize,
                      int **returnColumnSizes) {
    hash_table *table = NULL, *item, *tmp;
    char ***result;

    // Build the hash table
    for (int i = 0; i < strsSize; i++) {
        char key[104] = {0};
        create_key(strs[i], key);
        insert_node(&table, key, strs[i]);
    }

    *returnSize = HASH_COUNT(table);
    result = (char ***)malloc((*returnSize) * sizeof(char **));
    *returnColumnSizes = (int *)malloc((*returnSize) * sizeof(int));

    int idx = 0;
    HASH_ITER(hh, table, item, tmp) {
        result[idx] = (char **)malloc(item->list_size * sizeof(char *));
        (*returnColumnSizes)[idx] = item->list_size;
        int node_idx = 0;
        for (string_node *node = item->head; node != NULL; node = node->next) {
            result[idx][node_idx++] = node->str;
        }
        idx++;
    }

    // Free the hash table structure, not the strings, as they are returned
    HASH_ITER(hh, table, item, tmp) {
        HASH_DEL(table, item);
        string_node *current = item->head, *next;
        while (current != NULL) {
            next = current->next;
            free(current);  // Free the node, but not the string
            current = next;
        }
        free(item);
    }

    return result;
}