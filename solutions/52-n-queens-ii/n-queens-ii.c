// In C language "set" data structure is not available hence we are using
// "hashMap" to mimic the set operations.
struct hash_set {
    int id;
    UT_hash_handle hh;
};
int hash_set_exist(struct hash_set *head, int id) {
    struct hash_set *tmp;
    HASH_FIND_INT(head, &id, tmp);
    return tmp != NULL;
}
void hash_set_add(struct hash_set **head, int id) {
    struct hash_set *tmp = (struct hash_set *)malloc(sizeof(struct hash_set));
    tmp->id = id;
    HASH_ADD_INT(*head, id, tmp);
}
void hash_set_delete(struct hash_set **head, int id) {
    struct hash_set *tmp;
    HASH_FIND_INT(*head, &id, tmp);
    HASH_DEL(*head, tmp);
}
int size;
int backtrack(int row, struct hash_set *diagonals,
              struct hash_set *antiDiagonals, struct hash_set *cols) {
    if (row == size) {
        return 1;
    }
    int solutions = 0;
    for (int col = 0; col < size; col++) {
        int currDiagonal = row - col;
        int currAntiDiagonal = row + col;
        if (hash_set_exist(cols, col) ||
            hash_set_exist(diagonals, currDiagonal) ||
            hash_set_exist(antiDiagonals, currAntiDiagonal)) {
            continue;
        }
        hash_set_add(&cols, col);
        hash_set_add(&diagonals, currDiagonal);
        hash_set_add(&antiDiagonals, currAntiDiagonal);
        solutions += backtrack(row + 1, diagonals, antiDiagonals, cols);
        hash_set_delete(&cols, col);
        hash_set_delete(&diagonals, currDiagonal);
        hash_set_delete(&antiDiagonals, currAntiDiagonal);
    }
    return solutions;
}
int totalNQueens(int n) {
    size = n;
    struct hash_set *cols = NULL, *diagonals = NULL, *antiDiagonals = NULL;
    return backtrack(0, diagonals, antiDiagonals, cols);
}