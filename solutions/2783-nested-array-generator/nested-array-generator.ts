var inorderTraversal = function*(arr) {
  yield* arr.flat(Infinity);
};