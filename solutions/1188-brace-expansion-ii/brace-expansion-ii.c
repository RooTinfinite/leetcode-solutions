typedef struct {
    char* key;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** obj, char* key) {
    HashItem* pEntry = NULL;
    HASH_FIND_STR(*obj, key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, char* key) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = strdup(key);
    HASH_ADD_STR(*obj, key, pEntry);
    return true;
}

void hashFree(HashItem** obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr->key);
        free(curr);
    }
}

typedef struct {
    char* expression;
    int idx;
    int len;
} Parser;

bool isLetter(char c) { return c >= 'a' && c <= 'z'; }

void setUnion(HashItem** dest, HashItem** src) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *src, curr, tmp) { hashAddItem(dest, curr->key); }
}

int cmpstr(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

HashItem* expr_impl(Parser* parser);
HashItem* term_impl(Parser* parser);
HashItem* item_impl(Parser* parser);

// item -> letter | { expr }
HashItem* item_impl(Parser* parser) {
    HashItem* ret = NULL;
    if (parser->expression[parser->idx] == '{') {
        parser->idx++;
        HashItem* subResult = expr_impl(parser);
        setUnion(&ret, &subResult);
        hashFree(&subResult);
    } else {
        char str[2] = {parser->expression[parser->idx], '\0'};
        hashAddItem(&ret, str);
    }
    parser->idx++;
    return ret;
}

// term -> item | item term
HashItem* term_impl(Parser* parser) {
    // Initialize an empty set and take its Cartesian product with subsequent
    // results
    HashItem* ret = NULL;
    hashAddItem(&ret, "");

    // An item starts with { or a lowercase letter; continue matching only when
    // this condition is met
    while (parser->idx < parser->len &&
           (parser->expression[parser->idx] == '{' ||
            isLetter(parser->expression[parser->idx]))) {
        HashItem* sub = item_impl(parser);
        HashItem* tmp = NULL;

        // Cartesian product operation
        HashItem *currLeft = NULL, *tmpLeft = NULL;
        HASH_ITER(hh, ret, currLeft, tmpLeft) {
            HashItem *currRight = NULL, *tmpRight = NULL;
            HASH_ITER(hh, sub, currRight, tmpRight) {
                // Concatenate strings
                char* combined = (char*)malloc(strlen(currLeft->key) +
                                               strlen(currRight->key) + 1);
                strcpy(combined, currLeft->key);
                strcat(combined, currRight->key);
                hashAddItem(&tmp, combined);
                free(combined);
            }
        }

        // Free the old set
        hashFree(&ret);
        hashFree(&sub);
        ret = tmp;
    }
    return ret;
}

// expr -> term | term, expr
HashItem* expr_impl(Parser* parser) {
    HashItem* ret = NULL;
    while (true) {
        // Take the union with the result of term()
        HashItem* termResult = term_impl(parser);
        setUnion(&ret, &termResult);
        hashFree(&termResult);

        // Continue if a comma is matched; otherwise, stop matching
        if (parser->idx < parser->len &&
            parser->expression[parser->idx] == ',') {
            parser->idx++;
            continue;
        } else {
            break;
        }
    }
    return ret;
}

char** braceExpansionII(char* expression, int* returnSize) {
    Parser parser;
    parser.expression = expression;
    parser.idx = 0;
    parser.len = strlen(expression);

    HashItem* resultSet = expr_impl(&parser);

    int count = HASH_COUNT(resultSet);
    *returnSize = count;
    char** result = (char**)malloc(count * sizeof(char*));
    HashItem *curr = NULL, *tmp = NULL;
    int i = 0;
    HASH_ITER(hh, resultSet, curr, tmp) {
        result[i] = strdup(curr->key);
        i++;
    }

    qsort(result, count, sizeof(char*), cmpstr);
    hashFree(&resultSet);

    return result;
}