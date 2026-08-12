typedef struct {
    char key[3];
    char val;
    UT_hash_handle hh;
} my_hash;
my_hash* mappings = NULL;
void initMappings() {
    char keys[3] = {'}', ']', ')'};
    char values[3] = {'{', '[', '('};
    for (int i = 0; i < 3; i++) {
        my_hash* some_data = malloc(sizeof *some_data);
        some_data->key[0] = keys[i];
        some_data->key[1] = '\0';
        some_data->val = values[i];
        HASH_ADD_STR(mappings, key, some_data);
    }
}
bool isValid(char* s) {
    initMappings();  // create mappings
    int top = -1;
    char* stack = (char*)malloc(strlen(s) + 1);
    for (int i = 0; s[i]; i++) {
        my_hash* m = NULL;
        char key[3] = {s[i], '\0'};
        HASH_FIND_STR(mappings, key, m);
        if (m == NULL) {
            stack[++top] = s[i];
        } else {
            if (top < 0 || stack[top--] != m->val) {
                return false;
            }
        }
    }
    bool ret = top == -1;
    HASH_CLEAR(hh, mappings);  // clean mappings for next call
    free(stack);
    return ret;
}