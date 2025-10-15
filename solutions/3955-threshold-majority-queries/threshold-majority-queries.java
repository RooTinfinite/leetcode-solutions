class Solution {
    public int[] subarrayMajority(int[] nums, int[][] queries) {
        List<Query> list = new ArrayList<>();

        for(int i = 0 ; i < queries.length ; i++) {
            list.add(new Query(queries[i][0], queries[i][1], i, queries[i][2]));
        }

        MosAlgorithm mosalgo = new MosAlgorithm(nums);
        mosalgo.sortQuery(list);

        return mosalgo.processQueries(list);
    }
}

class MosAlgorithm {
    int[] arr;
    int n;
    int blockSize;
    int currL = 0, currR = -1;

    public MosAlgorithm(int[] arr) {
        this.arr = arr;
        this.n = arr.length;
        this.blockSize = (int) Math.sqrt(n);
    }

    public void sortQuery(List<Query> queries) {
        queries.sort((q1, q2) -> {
            int block1 = q1.left / blockSize;
            int block2 = q2.left / blockSize;
            if (block1 != block2) return Integer.compare(block1, block2);
            return Integer.compare(q1.right, q2.right);
        });
    }

    public int[] processQueries(List<Query> queries) {
        currL = 0; 
        currR = -1;

        int[] answers = new int[queries.size()];

        for (Query q : queries) {
            while (currL > q.left) {
                currL--;
                add(currL);
            }
            while (currR < q.right) {
                currR++;
                add(currR);
            }
            while (currL < q.left) {
                remove(currL);
                currL++;
            }
            while (currR > q.right) {
                remove(currR);
                currR--;
            }
            answers[q.idx] = getAnswer(q.threshold);
        }

        return answers;
    }

    Map<Integer, Integer> freq = new HashMap<>();
    Map<Integer, TreeSet<Integer>> map = new HashMap<>();
    int max = 0;

    public void add(int idx) {
        int val = arr[idx];
        int currFreq = freq.getOrDefault(val, 0);

        if(currFreq != 0) {
            map.get(currFreq).remove(val);
        }

        freq.put(val, currFreq + 1);
        map.compute(currFreq + 1, (k, v) -> v == null ? new TreeSet<>() : v).add(val);

        max = Math.max(max, currFreq + 1);
    }

    public void remove(int idx) {
        int val = arr[idx];
        int currFreq = freq.get(val);

        map.get(currFreq).remove(val);
        freq.remove(val);

        if(currFreq != 1) {
            map.get(currFreq - 1).add(val);
            freq.put(val, currFreq - 1);
        }

        if(map.get(max).size() == 0) {
            max--;
        }
    }

    public int getAnswer(int threshold) {
        if(threshold > max) return -1;

        TreeSet<Integer> set = map.get(max);
        return set.first();
    }
}

class Query {
    int left;
    int right;
    int idx;
    int threshold;

    Query(int left, int right, int idx, int threshold) {
        this.left = left;
        this.right = right;
        this.idx = idx;
        this.threshold = threshold;
    }
}