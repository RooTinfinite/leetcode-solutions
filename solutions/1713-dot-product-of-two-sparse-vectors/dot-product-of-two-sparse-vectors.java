class SparseVector {

    private int[] array;

    SparseVector(int[] nums) {
        array = nums;
    }

    public int dotProduct(SparseVector vec) {
        int result = 0;

        for (int i = 0; i < array.length; i++) {
            result += array[i] * vec.array[i];
        }
        return result;
    }   
}
